#include "DNTBoschCanbusChassis.h"
#include <dnt/RBoschCanbusChassis.h>

DNTBoschCanbusChassis::DNTBoschCanbusChassis(const DNTCommbox &commbox, const DNTVehicleDB &db, RBoschCanbusChassisModel model)
  : DNTAbstractECU()
  , _native(new RBoschCanbusChassis(commbox.getNative(), db.getNative(), model))
{
  setNative(_native);
}

DNTBoschCanbusChassis::DNTBoschCanbusChassis(const DNTBoschCanbusChassis &other)
  : _native(other._native)
{
  setNative(_native);
}

DNTBoschCanbusChassis& DNTBoschCanbusChassis::operator =(const DNTBoschCanbusChassis &other)
{
  if (this == &other) return *this;
  _native = other._native;
  setNative(_native);
  return *this;
}

DNTBoschCanbusChassis::~DNTBoschCanbusChassis()
{

}
