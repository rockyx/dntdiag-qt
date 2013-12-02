#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ECU_VISTEONPOWERTRAIN_H__
#define __DNT_ECU_VISTEONPOWERTRAIN_H__

#include <DNTGlobal.h>
#include <DNTAbstractECU.h>
#ifndef Q_MOC_RUN
#include <dnt/RVisteon.h>
#endif

class DNT_ECU_DECL DNTVisteonPowertrain : public DNTAbstractECU
{
private:
  RVisteonPowertrainPtr _native;
public:
  DNTVisteonPowertrain(const RICommboxPtr &boxNative, const RVehicleDBPtr &dbNative, RVisteonModel model);
  DNTVisteonPowertrain(const DNTVisteonPowertrain &other);
  DNTVisteonPowertrain& operator=(const DNTVisteonPowertrain &other);
  ~DNTVisteonPowertrain();
};

#endif // __DNT_ECU_VISTEONPOWERTRAIN_H__
