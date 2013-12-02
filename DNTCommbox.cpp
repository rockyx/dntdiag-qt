#include "DNTCommbox.h"
#include <QtSerialPort/QSerialPort>
#include <dnt/RSerialPort.h>
#include <dnt/RIOBuffer.h>
#include <dnt/RCommboxFactory.h>
#include <dnt/RGLC168Commbox.h>
#include <dnt/RGLW80Commbox.h>
#include <dnt/RICommbox.h>

#include <DNTSerialPortThread.h>

DNTCommbox::DNTCommbox(RCommboxVer ver)
  : _ver(ver)
  , _buffer(new RIOBuffer())
  , _box(RCommboxFactoryInst().getCommbox(_buffer, _ver))
  , _port()
{

}

DNTCommbox::DNTCommbox(const DNTCommbox &other)
  : _ver(other._ver)
  , _buffer(other._buffer)
  , _box(other._box)
  , _port(other._port)
{

}

DNTCommbox& DNTCommbox::operator =(const DNTCommbox &other)
{
  if (this == &other) return *this;
  _ver = other._ver;
  _buffer = other._buffer;
  _box = other._box;
  _port = other._port;
  return *this;
}

DNTCommbox::~DNTCommbox()
{

}

void DNTCommbox::closeSerialPort()
{
  _port.reset(); // will close SerialPort also.
}

bool DNTCommbox::openC168SerialModel()
{
  RGLC168CommboxPtr box = boost::dynamic_pointer_cast<RGLC168Commbox>(_box);
  _port.reset(new DNTSerialPortThread(_buffer));
  auto infos = QSerialPortInfo::availablePorts();
  auto port = _port->getPort();
  for(auto info : infos) {
    port->setPortName(info.portName().toStdString());
    if (!port->open())
      continue;

    port->setBaudRate(9600);
    port->setDataBits(8);
    port->setStopBits(RSerialStopBits::One);
    port->setParity(RSerialParity::None);
    port->setHandshake(RSerialHandshake::None);

    port->setDtrEnable(false);
    QThread::msleep(50);
    port->setDtrEnable(true);
    QThread::msleep(50);

    _port->start();

    for (int i = 0; i < 3; i++) {
      if (!box->connect()) continue;
      if (!box->beginBaudChange()) continue;
      port->setBaudRate(QSerialPort::Baud57600);
      if (!box->endBaudChange()) {
        port->setBaudRate(QSerialPort::Baud9600);
        continue;
      }
      return true;
    }
  }
  _port.reset();
  return false;

}

bool DNTCommbox::openW80SerialModel()
{
  RGLW80CommboxPtr box = boost::dynamic_pointer_cast<RGLW80Commbox>(_box);
  _port.reset(new DNTSerialPortThread(_buffer));
  auto infos = QSerialPortInfo::availablePorts();
  auto port = _port->getPort();
  for (auto info : infos) {
    port->setPortName(info.portName().toStdString());
    port->setBaudRate(115200);
    port->setStopBits(RSerialStopBits::Two);
    port->setParity(RSerialParity::None);
    port->setHandshake(RSerialHandshake::None);
    port->setDataBits(8);
    if (!port->open()) continue;
    _port->start();
    port->setDtrEnable(false);
    QThread::sleep(1);
    port->setDtrEnable(true);
    QThread::sleep(1);
    for (qint32 i = 0; i < 3; i++)
      if (box->connect()) return true;
  }
  _port.reset();
  return false;
}

RCommboxVer DNTCommbox::getVersion()
{
  return _ver;
}

bool DNTCommbox::connect()
{
  auto ver = getVersion();
  if (ver == RCommboxVer::C168) { // C168 and W80 only support SerialPort
    return openC168SerialModel();
  } else if (ver == RCommboxVer::W80) {
    return openW80SerialModel();
  }
  return false;
}

bool DNTCommbox::disconnect()
{
  auto ver = getVersion();
  if (ver == RCommboxVer::C168 ||
      ver == RCommboxVer::W80) { // C168 and W80 should shut down serialport and the thread
    bool ret = true;
    if (_port) {
      ret = _box->disconnect();
      closeSerialPort();
    }
    return ret;
  }
  return false;
}

RICommboxPtr &DNTCommbox::getNative()
{
  return _box;
}

const RICommboxPtr &DNTCommbox::getNative() const
{
  return _box;
}
