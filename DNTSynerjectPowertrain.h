#ifndef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ECU_SYNERJECTPOWERTRAIN_H__
#define __DNT_ECU_SYNERJECTPOWERTRAIN_H__

#include <DNTGlobal.h>
#include <DNTAbstractECU.h>
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>
#ifndef Q_MOC_RUN
#include <dnt/RSynerject.h>
#endif

class DNT_ECU_DECL DNTSynerjectPowertrain : public DNTAbstractECU
{
private:
  RSynerjectPowertrainPtr _native;
public:
  DNTSynerjectPowertrain(const DNTCommbox &commbox, const DNTVehicleDB &db, RSynerjectModel model);
  DNTSynerjectPowertrain(const DNTSynerjectPowertrain &other);
  DNTSynerjectPowertrain& operator=(const DNTSynerjectPowertrain &other);
  ~DNTSynerjectPowertrain();
  QString getVersion();
};

#endif // __DNT_ECU_SYNERJECTPOWERTRAIN_H__
