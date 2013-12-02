#include "DNTDensoPowertrain.h"
#include <dnt/RDensoPowertrain.h>

DNTDensoPowertrain::DNTDensoPowertrain(const DNTCommbox &commbox, const DNTVehicleDB &db, RDensoModel model)
  : DNTAbstractECU()
  , _native(new RDensoPowertrain(commbox.getNative(), db.getNative(), model))
{
  setNative(_native);
}

DNTDensoPowertrain::DNTDensoPowertrain(const DNTDensoPowertrain &other)
  : _native(other._native)
{
  setNative(_native);
}

DNTDensoPowertrain& DNTDensoPowertrain::operator =(const DNTDensoPowertrain &other)
{
  if (this == &other) return *this;
  _native = other._native;
  setNative(_native);
  return *this;
}

DNTDensoPowertrain::~DNTDensoPowertrain()
{

}
