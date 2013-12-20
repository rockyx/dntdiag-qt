#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ECU_BOSCHCANBUSCHASSIS_H__
#define __DNT_ECU_BOSCHCANBUSCHASSIS_H__

#ifndef Q_MOC_RUN
#include <dnt/RBosch.h>
#include <dnt/RBoschCanbusChassis.h>
#endif
#include <DNTAbstractECU.h>

class DNT_ECU_DECL RBoschCanbusChassis : public RAbstractECU<dnt::RBoschCanbusChassis, dnt::RBoschCanbusChassisModel>
{
public:
  enum Model
  {
    BESTURN_B50_ABS = dnt::RBoschCanbusChassisModel::BESTURN_B50_ABS
  };

public:
  RBoschCanbusChassis(const RCommbox &commbox, const RVehicleDB &db, Model model);
};

typedef QSharedPointer<RBoschCanbusChassis> RBoschCanbusChassisPtr;

#endif // __DNT_ECU_BOSCHCANBUSCHASSIS_H__
