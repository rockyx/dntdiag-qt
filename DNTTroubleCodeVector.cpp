#include "DNTTroubleCodeVector.h"
#include <dnt/RTroubleCodeVector.h>

DNTTroubleCodeVector::DNTTroubleCodeVector(const RTroubleCodeVectorPtr &native)
  : _native(native)
{
  addItems();
}

DNTTroubleCodeVector::DNTTroubleCodeVector()
  : _native()
{

}

DNTTroubleCodeVector::DNTTroubleCodeVector(const DNTTroubleCodeVector &other)
  : _native(other._native)
{
  addItems();
}

DNTTroubleCodeVector& DNTTroubleCodeVector::operator =(const DNTTroubleCodeVector &other)
{
  if (this == &other) return *this;
  _native = other._native;
  addItems();
  return *this;
}

DNTTroubleCodeVector::~DNTTroubleCodeVector()
{

}

void DNTTroubleCodeVector::addItems()
{
  if (!_native)
    return;

  int size = _native->size();
  for (int i = 0; i < size; ++i) {
    DNTTroubleCodeItem item(_native->at(i));
    append(item);
  }
}
