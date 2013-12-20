#include "DNTTroubleCodeVector.h"
#include <dnt/RTroubleCodeVector.h>

RTroubleCodeVector::RTroubleCodeVector(const dnt::RTroubleCodeVectorPtr &native)
  : _null(native ? false : true)
{
  if (!native) return;

  auto size = native->size();
  for (decltype(size) i = 0; i < size; ++i) {
    RTroubleCodeItem item(native->at(i));
    append(item);
  }
}

RTroubleCodeVector::RTroubleCodeVector()
{

}

bool RTroubleCodeVector::isNull() const
{
  return _null;
}
