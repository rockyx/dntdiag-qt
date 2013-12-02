#include "DNTSynerjectPowertrain.h"
#include <dnt/RSynerjectPowertrain.h>

DNTSynerjectPowertrain::DNTSynerjectPowertrain(const DNTCommbox &commbox, const DNTVehicleDB &db, RSynerjectModel model)
  : DNTAbstractECU()
  , _native(new RSynerjectPowertrain(commbox.getNative(), db.getNative(), model))
{
  setNative(_native);
}

DNTSynerjectPowertrain::DNTSynerjectPowertrain(const DNTSynerjectPowertrain &other)
  : _native(other._native)
{
  setNative(_native);
}

DNTSynerjectPowertrain& DNTSynerjectPowertrain::operator =(const DNTSynerjectPowertrain &other)
{
  if (this == &other) return *this;
  _native = other._native;
  setNative(_native);
  return *this;
}

DNTSynerjectPowertrain::~DNTSynerjectPowertrain()
{

}

QString DNTSynerjectPowertrain::getVersion()
{
  auto str = _native->getECUVersion();
  return QString::fromUtf8(str.c_str(), str.length());
}

