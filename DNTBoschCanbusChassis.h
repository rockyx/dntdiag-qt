#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ECU_BOSCHCANBUSCHASSIS_H__
#define __DNT_ECU_BOSCHCANBUSCHASSIS_H__

#include <DNTGlobal.h>
#include <DNTAbstractECU.h>
#ifndef Q_MOC_RUN
#include <dnt/RBosch.h>
#endif

#include <DNTCommbox.h>
#include <DNTVehicleDB.h>

class DNT_ECU_DECL DNTBoschCanbusChassis : public DNTAbstractECU
{
private:
  RBoschCanbusChassisPtr _native;
public:
  DNTBoschCanbusChassis(const DNTCommbox &commbox, const DNTVehicleDB &db, RBoschCanbusChassisModel model);
  DNTBoschCanbusChassis(const DNTBoschCanbusChassis &other);
  DNTBoschCanbusChassis& operator=(const DNTBoschCanbusChassis &other);
  ~DNTBoschCanbusChassis();
};

#endif // __DNT_ECU_BOSCHCANBUSCHASSIS_H__
