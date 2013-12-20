#include "DNTSynerjectPowertrain.h"
#include <dnt/RSynerjectPowertrain.h>

RSynerjectPowertrain::RSynerjectPowertrain(const RCommbox &commbox, const RVehicleDB &db, Model model)
  : RAbstractECU(commbox, db, static_cast<ModelType>(model))
{
}

QString RSynerjectPowertrain::getVersion()
{
  auto str = _native->getECUVersion();
  return QString::fromUtf8(str.c_str(), str.length());
}

