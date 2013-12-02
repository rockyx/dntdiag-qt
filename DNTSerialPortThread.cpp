#include "DNTSerialPortThread.h"
#include <QtDebug>
#include <QDateTime>
#include <dnt/RSerialPort.h>
#include <dnt/RIOBuffer.h>

class SerialPortRead : public QRunnable
{
private:
  RSerialPortPtr _port;
  RIOBufferPtr _buffer;
public:
  SerialPortRead(const RSerialPortPtr &port, const RIOBufferPtr &buffer);
  void run() Q_DECL_OVERRIDE;
};

class SerialPortWrite : public QRunnable
{
private:
  RSerialPortPtr _port;
  RIOBufferPtr _buffer;
public:
  SerialPortWrite(const RSerialPortPtr &port, const RIOBufferPtr &buffer);
  void run() Q_DECL_OVERRIDE;
};

SerialPortRead::SerialPortRead(const RSerialPortPtr &port, const RIOBufferPtr &buffer)
  : _port(port)
  , _buffer(buffer)
{
}

void SerialPortRead::run()
{
  static uint8_t buff[256];
  static qint64 size = 0;
  while (_port->isOpen()) {
    size = _port->bytesToRead();
    while (size > 0) {
      size = qMin(size, qint64(256));
      _port->read(buff, size);
      _buffer->pushToFromEcuBuffer(buff, size);
      size = _port->bytesToRead();
    }
    QThread::msleep(1);
  }
}

SerialPortWrite::SerialPortWrite(const RSerialPortPtr &port, const RIOBufferPtr &buffer)
  : _port(port)
  , _buffer(buffer)
{

}

void SerialPortWrite::run()
{
  static uint8_t buff[256];
  static int32_t size = 0;
  while (_port->isOpen()) {
    size = _buffer->toEcuBufferBytesAvailable();
    while (size > 0) {
      size = qMin(size, 256);
      _buffer->popFromToEcuBuffer(buff, size);
      _port->write(buff, size);
      size = _buffer->toEcuBufferBytesAvailable();
    }
    QThread::msleep(1);
  }
}

DNTSerialPortThread::DNTSerialPortThread(const RIOBufferPtr &buffer)
  : _buffer(buffer)
  , _port(new RSerialPort())
  , _read(new SerialPortRead(_port, _buffer))
  , _write(new SerialPortWrite(_port, _buffer))
  , _pool()
{
  _read->setAutoDelete(false);
  _write->setAutoDelete(false);
}

DNTSerialPortThread::~DNTSerialPortThread()
{
  _port->close();
  _pool.waitForDone();
  delete _read;
  delete _write;
}

RSerialPortPtr DNTSerialPortThread::getPort()
{
  return _port;
}

void DNTSerialPortThread::start()
{
  _pool.start(_write);
  _pool.start(_read);
}
