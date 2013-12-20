#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_DENSOPOWERTRAIN_H__
#define __DNT_DENSOPOWERTRAIN_H__

#ifndef Q_MOC_RUN
#include <dnt/RDenso.h>
#include <dnt/RDensoPowertrain.h>
#endif
#include <DNTAbstractECU.h>
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>

class DNT_ECU_DECL RDensoPowertrain : public RAbstractECU<dnt::RDensoPowertrain, dnt::RDensoModel>
{
public:
  enum Model
  {
    DCJ_GW250 = dnt::RDensoModel::DCJ_GW250
  };

public:
  RDensoPowertrain(const RCommbox &commbox, const RVehicleDB &db, Model model);
};

typedef QSharedPointer<RDensoPowertrain> RDensoPowertrainPtr;

#endif // __DNT_DENSOPOWERTRAIN_H__
