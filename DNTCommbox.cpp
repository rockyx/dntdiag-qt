#include "DNTCommbox.h"
#include <QtSerialPort/QSerialPort>
#include <dnt/RSerialPort.h>
#include <dnt/RIOBuffer.h>
#include <dnt/RCommboxFactory.h>
#include <dnt/RGLC168Commbox.h>
#include <dnt/RGLW80Commbox.h>
#include <dnt/RICommbox.h>

RCommbox::RCommbox(Version ver)
  : _ver(ver)
  , _buffer(new dnt::RIOBuffer())
  , _box(dnt::RCommboxFactoryInst().getCommbox(_buffer, static_cast<dnt::RCommboxVer>(_ver)))
  , _port()
{

}

RCommbox::RCommbox()
  : _ver(UNKNOW)
  , _buffer(new dnt::RIOBuffer())
  , _box()
  , _port()
{

}

void RCommbox::closeSerialPort()
{
  _port.reset(); // will close SerialPort also.
}

bool RCommbox::openC168SerialModel()
{
  dnt::RGLC168CommboxPtr box = boost::dynamic_pointer_cast<dnt::RGLC168Commbox>(_box);
  _port.reset(new RSerialPortThread(_buffer));
  auto infos = QSerialPortInfo::availablePorts();
  auto port = _port->getPort();
  for(auto info : infos) {
    port->setPortName(info.portName().toStdString());
    if (!port->open())
      continue;

    port->setBaudRate(9600);
    port->setDataBits(8);
    port->setStopBits(dnt::RSerialStopBits::One);
    port->setParity(dnt::RSerialParity::None);
    port->setHandshake(dnt::RSerialHandshake::None);

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

bool RCommbox::openW80SerialModel()
{
  dnt::RGLW80CommboxPtr box = boost::dynamic_pointer_cast<dnt::RGLW80Commbox>(_box);
  _port.reset(new RSerialPortThread(_buffer));
  auto infos = QSerialPortInfo::availablePorts();
  auto port = _port->getPort();
  for (auto info : infos) {
    port->setPortName(info.portName().toStdString());
    port->setBaudRate(115200);
    port->setStopBits(dnt::RSerialStopBits::Two);
    port->setParity(dnt::RSerialParity::None);
    port->setHandshake(dnt::RSerialHandshake::None);
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

void RCommbox::setVersion(Version ver)
{
  if (_ver != ver) {
    disconnect();
    _ver = ver;
    _box = dnt::RCommboxFactoryInst().getCommbox(_buffer, static_cast<dnt::RCommboxVer>(_ver));
  }
}

RCommbox::Version RCommbox::getVersion()
{
  return _ver;
}

bool RCommbox::connect()
{
  if (!_box) return false;
  if (_ver == C168) { // C168 and W80 only support SerialPort
    return openC168SerialModel();
  } else if (_ver == W80) {
    return openW80SerialModel();
  }
  return false;
}

bool RCommbox::connect(RCommbox::Version ver)
{
  _ver = ver;
  _box = dnt::RCommboxFactoryInst().getCommbox(_buffer, static_cast<dnt::RCommboxVer>(_ver));
  return connect();
}

bool RCommbox::disconnect()
{
  if (!_box) return false;
  if (_ver == C168 || _ver == W80) { // C168 and W80 should shut down serialport and the thread
    bool ret = true;
    if (_port) {
      ret = _box->disconnect();
      closeSerialPort();
    }
    return ret;
  }
  return false;
}

const dnt::RICommboxPtr& RCommbox::getNative() const
{
  return _box;
}
