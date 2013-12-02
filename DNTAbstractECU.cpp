#include "DNTAbstractECU.h"
#include <dnt/RAbstractECU.h>

DNTAbstractECU::DNTAbstractECU()
  : _native()
  , _troubleCode()
  , _dataStream()
  , _freezeStream()
  , _activeTest()
{

}

DNTAbstractECU::~DNTAbstractECU()
{

}

void DNTAbstractECU::setFunctions()
{
  if (!_native)
    return;
  _troubleCode = DNTTroubleCodeFunction(_native->getTroubleCode());
  _dataStream = DNTDataStreamFunction(_native->getDataStream());
  _freezeStream = DNTDataStreamFunction(_native->getFreezeStream());
  _activeTest = DNTActiveTestFunction(_native->getActiveTest());
}

QString DNTAbstractECU::getLastInfo()
{
  auto str = _native->getLastInfo();
  return QString::fromUtf8(str.c_str(), str.length());
}

bool DNTAbstractECU::ioChannelInit()
{
  auto ret = _native->ioChannelInit();
  if (ret) setFunctions();
  return ret;
}

DNTTroubleCodeFunction DNTAbstractECU::getTroubleCode()
{
  return _troubleCode;
}

DNTDataStreamFunction DNTAbstractECU::getDataStream()
{
  return _dataStream;
}

DNTDataStreamFunction DNTAbstractECU::getFreezeStream()
{
  return _freezeStream;
}

DNTActiveTestFunction DNTAbstractECU::getActiveTest()
{
  return _activeTest;
}
