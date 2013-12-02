#include "DNTVisteonPowertrain.h"
#include <dnt/RVisteonPowertrain.h>

DNTVisteonPowertrain::DNTVisteonPowertrain(const RICommboxPtr &boxNative, const RVehicleDBPtr &dbNative, RVisteonModel model)
  : DNTAbstractECU()
  , _native(new RVisteonPowertrain(boxNative, dbNative, model))
{
  setNative(_native);
}

DNTVisteonPowertrain::DNTVisteonPowertrain(const DNTVisteonPowertrain &other)
  : _native(other._native)
{
  setNative(_native);
}

DNTVisteonPowertrain& DNTVisteonPowertrain::operator =(const DNTVisteonPowertrain &other)
{
  if (this == &other) return *this;
  _native = other._native;
  setNative(_native);
  return *this;
}

DNTVisteonPowertrain::~DNTVisteonPowertrain()
{

}

