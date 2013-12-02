#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_MIKUNIPOWERTRAIN_H__
#define __DNT_MIKUNIPOWERTRAIN_H__

#include <DNTGlobal.h>
#include <DNTAbstractECU.h>
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>
#ifndef Q_MOC_RUN
#include <dnt/RMikuni.h>
#endif

class DNT_ECU_DECL DNTMikuniPowertrain : public DNTAbstractECU
{
private:
  RMikuniPowertrainPtr _native;
public:
  DNTMikuniPowertrain(const DNTCommbox &commbox, const DNTVehicleDB &db, RMikuniModel model);
  DNTMikuniPowertrain(const DNTMikuniPowertrain &other);
  DNTMikuniPowertrain& operator=(const DNTMikuniPowertrain &other);
  ~DNTMikuniPowertrain();
  QString getVersion();
  bool tpsIdleSetting();
  bool longTermLearnValueZoneInitialization();
  bool iscLearnValueInitialization();
};

#endif // __DNT_MIKUNIPOWERTRAIN_H__
