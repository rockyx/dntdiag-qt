#include "DNTMikuniPowertrain.h"
#include "../native/dnt/RMikuniPowertrain.h"

RMikuniPowertrain::RMikuniPowertrain(const RCommbox &commbox, const RVehicleDB &db, Model model)
  : RAbstractECU(commbox, db, static_cast<ModelType>(model))
{
}

QString RMikuniPowertrain::getVersion()
{
  auto ver = _native->getECUVersion();
  return QString::fromUtf8(ver.c_str(), ver.length());
}

bool RMikuniPowertrain::tpsIdleSetting()
{
  return _native->tpsIdleSetting();
}

bool RMikuniPowertrain::longTermLearnValueZoneInitialization()
{
  return _native->longTermLearnValueZoneInitialization();
}

bool RMikuniPowertrain::iscLearnValueInitialization()
{
  return _native->iscLearnValueInitialization();
}
