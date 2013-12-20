#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_MIKUNIPOWERTRAIN_H__
#define __DNT_MIKUNIPOWERTRAIN_H__

#ifndef Q_MOC_RUN
#include <dnt/RMikuni.h>
#include <dnt/RMikuniPowertrain.h>
#endif
#include <DNTAbstractECU.h>
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>

class DNT_ECU_DECL RMikuniPowertrain : public RAbstractECU<dnt::RMikuniPowertrain, dnt::RMikuniModel>
{
public:
  enum Model
  {
    DCJ_16A = dnt::RMikuniModel::DCJ_16A,
    DCJ_16C = dnt::RMikuniModel::DCJ_16C,
    DCJ_10 = dnt::RMikuniModel::DCJ_10,
    QM200GY_F = dnt::RMikuniModel::QM200GY_F,
    QM200_3D = dnt::RMikuniModel::QM200_3D,
    QM200J_2L = dnt::RMikuniModel::QM200J_2L
  };

public:
  RMikuniPowertrain(const RCommbox &commbox, const RVehicleDB &db, Model model);
  QString getVersion();
  bool tpsIdleSetting();
  bool longTermLearnValueZoneInitialization();
  bool iscLearnValueInitialization();
};

typedef QSharedPointer<RMikuniPowertrain> RMikuniPowertrainPtr;

#endif // __DNT_MIKUNIPOWERTRAIN_H__
