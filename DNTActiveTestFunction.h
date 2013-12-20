#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ACTIVETESTFUNCTION_H__
#define __DNT_ACTIVETESTFUNCTION_H__

#ifndef Q_MOC_RUN
#include <dnt/RActiveState.h>
#endif
#include <DNTGlobal.h>

class DNT_DIAG_DECL RActiveTestFunction
{
  template<typename NativePtr, typename Model> friend class RAbstractECU;
public:
  enum ActiveState
  {
    Positive = dnt::RActiveState::Positive,
    Idle = dnt::RActiveState::Idle,
    Negative = dnt::RActiveState::Negative,
    Stop = dnt::RActiveState::Stop
  };

private:
  dnt::RActiveTestFunctionPtr _native;
private:
  RActiveTestFunction(const dnt::RActiveTestFunctionPtr &native = dnt::RActiveTestFunctionPtr());
public:
  void changeState(ActiveState state);
  bool execute(int mode);
};

typedef QSharedPointer<RActiveTestFunction> RActiveTestFunctionPtr;

#endif // __DNT_ACTIVETESTFUNCTION_H__
