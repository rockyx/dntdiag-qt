#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ECU_VISTEONPOWERTRAIN_H__
#define __DNT_ECU_VISTEONPOWERTRAIN_H__

#ifndef Q_MOC_RUN
#include <dnt/RVisteon.h>
#include <dnt/RVisteonPowertrain.h>
#endif
#include <DNTAbstractECU.h>

class DNT_ECU_DECL RVisteonPowertrain : public RAbstractECU<dnt::RVisteonPowertrain, dnt::RVisteonModel>
{
public:
  enum Model
  {
    QM250J_2L = dnt::RVisteonModel::QM250J_2L
  };

public:
  RVisteonPowertrain(const RCommbox &box, const RVehicleDB &db, Model model);
};

#endif // __DNT_ECU_VISTEONPOWERTRAIN_H__
