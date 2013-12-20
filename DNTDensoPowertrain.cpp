#include "DNTDensoPowertrain.h"
#include <dnt/RDensoPowertrain.h>

RDensoPowertrain::RDensoPowertrain(const RCommbox &commbox, const RVehicleDB &db, Model model)
  : RAbstractECU(commbox, db, static_cast<ModelType>(model))
{
}
