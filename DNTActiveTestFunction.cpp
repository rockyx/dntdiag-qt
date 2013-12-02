#include "DNTActiveTestFunction.h"
#include <dnt/RActiveTestFunction.h>


DNTActiveTestFunction::DNTActiveTestFunction(const RActiveTestFunctionPtr &native)
  : _native(native)
{

}

DNTActiveTestFunction::DNTActiveTestFunction(const DNTActiveTestFunction &other)
  : _native(other._native)
{

}

DNTActiveTestFunction& DNTActiveTestFunction::operator =(const DNTActiveTestFunction &other)
{
  if (this == &other) return *this;
  _native = other._native;
  return *this;
}

DNTActiveTestFunction::~DNTActiveTestFunction()
{

}

void DNTActiveTestFunction::changeState(RActiveState state)
{
  _native->changeState(state);
}

bool DNTActiveTestFunction::execute(int mode)
{
  return _native->execute(mode);
}
