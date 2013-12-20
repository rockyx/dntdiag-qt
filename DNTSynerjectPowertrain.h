#ifndef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ECU_SYNERJECTPOWERTRAIN_H__
#define __DNT_ECU_SYNERJECTPOWERTRAIN_H__

#ifndef Q_MOC_RUN
#include <dnt/RSynerject.h>
#include <dnt/RSynerjectPowertrain.h>
#endif
#include <DNTAbstractECU.h>
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>

class DNT_ECU_DECL RSynerjectPowertrain : public RAbstractECU<dnt::RSynerjectPowertrain, dnt::RSynerjectModel>
{
public:
  enum Model
  {
    QM125T_8H = dnt::RSynerjectModel::QM125T_8H,
    QM250GY = dnt::RSynerjectModel::QM250GY,
    QM250T = dnt::RSynerjectModel::QM250T
  };

public:
  RSynerjectPowertrain(const RCommbox &commbox, const RVehicleDB &db, Model model);
  QString getVersion();
};

#endif // __DNT_ECU_SYNERJECTPOWERTRAIN_H__
