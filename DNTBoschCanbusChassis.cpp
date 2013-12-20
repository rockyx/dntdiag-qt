#include "DNTBoschCanbusChassis.h"
#include <dnt/RBoschCanbusChassis.h>

RBoschCanbusChassis::RBoschCanbusChassis(const RCommbox &commbox, const RVehicleDB &db, Model model)
  : RAbstractECU(commbox, db, static_cast<ModelType>(model))
{
}
