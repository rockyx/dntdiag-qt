#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_DENSOPOWERTRAIN_H__
#define __DNT_DENSOPOWERTRAIN_H__

#include <DNTGlobal.h>
#include <DNTAbstractECU.h>
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>
#ifndef Q_MOC_RUN
#include <dnt/RDenso.h>
#endif

class DNT_ECU_DECL DNTDensoPowertrain : public DNTAbstractECU
{
private:
  RDensoPowertrainPtr _native;
public:
  DNTDensoPowertrain(const DNTCommbox &commbox, const DNTVehicleDB &db, RDensoModel model);
  DNTDensoPowertrain(const DNTDensoPowertrain &other);
  DNTDensoPowertrain& operator=(const DNTDensoPowertrain &other);
  ~DNTDensoPowertrain();
};

#endif // __DNT_DENSOPOWERTRAIN_H__
