#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ACTIVETESTFUNCTION_H__
#define __DNT_ACTIVETESTFUNCTION_H__

#include <DNTGlobal.h>
#ifndef Q_MOC_RUN
#include <dnt/RActiveState.h>
#endif

class DNT_DIAG_DECL DNTActiveTestFunction
{
  friend class DNTAbstractECU;
private:
  RActiveTestFunctionPtr _native;
private:
  DNTActiveTestFunction(const RActiveTestFunctionPtr &native = RActiveTestFunctionPtr());
public:
  DNTActiveTestFunction(const DNTActiveTestFunction &other);
  DNTActiveTestFunction &operator=(const DNTActiveTestFunction &other);
  ~DNTActiveTestFunction();
  void changeState(RActiveState state);
  bool execute(int mode);
};

#endif // __DNT_ACTIVETESTFUNCTION_H__
