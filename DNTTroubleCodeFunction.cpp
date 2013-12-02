#include "DNTTroubleCodeFunction.h"
#include <dnt/RTroubleCodeFunction.h>

DNTTroubleCodeFunction::DNTTroubleCodeFunction(const RTroubleCodeFunctionPtr &native)
  : _native(native)
  , _tcs()
{
  if (_native)
    _tcs = DNTTroubleCodeVector(_native->getTroubleCodes());
}

DNTTroubleCodeFunction::DNTTroubleCodeFunction(const DNTTroubleCodeFunction &other)
  : _native(other._native)
  , _tcs(other._tcs)
{

}

DNTTroubleCodeFunction& DNTTroubleCodeFunction::operator =(const DNTTroubleCodeFunction &other)
{
  if (this == &other) return *this;
  _native = other._native;
  _tcs = other._tcs;
  return *this;
}

DNTTroubleCodeFunction::~DNTTroubleCodeFunction()
{

}

bool DNTTroubleCodeFunction::readCurrent()
{
  return _native->current();
}

bool DNTTroubleCodeFunction::readHistory()
{
  return _native->history();
}

bool DNTTroubleCodeFunction::clear()
{
  return _native->clear();
}

DNTTroubleCodeVector DNTTroubleCodeFunction::getTroubleCodes()
{
  return _tcs;
}
