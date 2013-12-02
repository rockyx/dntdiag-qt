#include "DNTMikuniPowertrain.h"
#include "../native/dnt/RMikuniPowertrain.h"

DNTMikuniPowertrain::DNTMikuniPowertrain(const DNTCommbox &commbox, const DNTVehicleDB &db, RMikuniModel model)
  : DNTAbstractECU()
  , _native(new RMikuniPowertrain(commbox.getNative(), db.getNative(), model))
{
  setNative(_native);
}

DNTMikuniPowertrain::DNTMikuniPowertrain(const DNTMikuniPowertrain &other)
  : _native(other._native)
{
  setNative(_native);
}

DNTMikuniPowertrain& DNTMikuniPowertrain::operator=(const DNTMikuniPowertrain &other)
{
  if (this == &other) return *this;
  _native = other._native;
  setNative(_native);
  return *this;
}

DNTMikuniPowertrain::~DNTMikuniPowertrain()
{

}

QString DNTMikuniPowertrain::getVersion()
{
  auto ver = _native->getECUVersion();
  return QString::fromUtf8(ver.c_str(), ver.length());
}

bool DNTMikuniPowertrain::tpsIdleSetting()
{
  return _native->tpsIdleSetting();
}

bool DNTMikuniPowertrain::longTermLearnValueZoneInitialization()
{
  return _native->longTermLearnValueZoneInitialization();
}

bool DNTMikuniPowertrain::iscLearnValueInitialization()
{
  return _native->iscLearnValueInitialization();
}
