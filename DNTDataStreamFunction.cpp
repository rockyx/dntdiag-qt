#include "DNTDataStreamFunction.h"
#include <dnt/RDataStreamFunction.h>

DNTDataStreamFunction::DNTDataStreamFunction(const RDataStreamFunctionPtr &native)
  : _native(native)
  , _ldl()
{
  if (_native)
    _ldl = DNTLiveDataList(_native->getLiveData());
}

DNTDataStreamFunction::DNTDataStreamFunction(const DNTDataStreamFunction &other)
  : _native(other._native)
  , _ldl(other._ldl)
{

}

DNTDataStreamFunction& DNTDataStreamFunction::operator =(const DNTDataStreamFunction &other)
{
  if (this == &other) return *this;
  _native = other._native;
  _ldl = other._ldl;
  return *this;
}

DNTDataStreamFunction::~DNTDataStreamFunction()
{
}

void DNTDataStreamFunction::stopRead()
{
  if (_native)
    _native->stopRead();
}

void DNTDataStreamFunction::stopCalc()
{
  if (_native)
    _native->stopCalc();
}

bool DNTDataStreamFunction::readData()
{
  if (!_native) return false;
  return _native->readData();
}

bool DNTDataStreamFunction::readDataOnce()
{
  if (!_native) return false;
  return _native->readDataOnce();
}

bool DNTDataStreamFunction::calcData()
{
  if (!_native) return false;
  return _native->calcData();
}

bool DNTDataStreamFunction::calcDataOnce()
{
  if (!_native) return false;
  return _native->calcDataOnce();
}

DNTLiveDataList &DNTDataStreamFunction::getLiveData()
{
  return _ldl;
}


