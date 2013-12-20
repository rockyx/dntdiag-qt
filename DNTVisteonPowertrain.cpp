#include "DNTVisteonPowertrain.h"
#include <dnt/RVisteonPowertrain.h>

RVisteonPowertrain::RVisteonPowertrain(const RCommbox &box, const RVehicleDB &db, Model model)
  : RAbstractECU(box, db, static_cast<ModelType>(model))
{

}

