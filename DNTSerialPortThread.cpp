#include "DNTSerialPortThread.h"
#include <QtDebug>
#include <QDateTime>
#include <dnt/RSerialPort.h>
#include <dnt/RIOBuffer.h>

class SerialPortRead : public QRunnable
{
private:
  dnt::RSerialPortPtr _port;
  dnt::RIOBufferPtr _buffer;
public:
  SerialPortRead(const dnt::RSerialPortPtr &port, const dnt::RIOBufferPtr &buffer);
  void run() Q_DECL_OVERRIDE;
};

class SerialPortWrite : public QRunnable
{
private:
  dnt::RSerialPortPtr _port;
  dnt::RIOBufferPtr _buffer;
public:
  SerialPortWrite(const dnt::RSerialPortPtr &port, const dnt::RIOBufferPtr &buffer);
  void run() Q_DECL_OVERRIDE;
};

SerialPortRead::SerialPortRead(const dnt::RSerialPortPtr &port, const dnt::RIOBufferPtr &buffer)
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

SerialPortWrite::SerialPortWrite(const dnt::RSerialPortPtr &port, const dnt::RIOBufferPtr &buffer)
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

RSerialPortThread::RSerialPortThread(const dnt::RIOBufferPtr &buffer)
  : _buffer(buffer)
  , _port(new dnt::RSerialPort())
  , _read(new SerialPortRead(_port, _buffer))
  , _write(new SerialPortWrite(_port, _buffer))
  , _pool()
{
  _read->setAutoDelete(false);
  _write->setAutoDelete(false);
}

RSerialPortThread::~RSerialPortThread()
{
  _port->close();
  _pool.waitForDone();
  delete _read;
  delete _write;
}

dnt::RSerialPortPtr RSerialPortThread::getPort()
{
  return _port;
}

void RSerialPortThread::start()
{
  _pool.start(_write);
  _pool.start(_read);
}
