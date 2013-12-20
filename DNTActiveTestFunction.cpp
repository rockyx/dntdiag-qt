#include "DNTActiveTestFunction.h"
#include <dnt/RActiveTestFunction.h>

RActiveTestFunction::RActiveTestFunction(const dnt::RActiveTestFunctionPtr &native)
  : _native(native)
{

}

void RActiveTestFunction::changeState(ActiveState state)
{
  if (_native)
    _native->changeState(static_cast<dnt::RActiveState>(state));
}

bool RActiveTestFunction::execute(int mode)
{
  if (_native)
    return _native->execute(mode);
  return false;
}
