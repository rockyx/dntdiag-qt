#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_TROUBLECODEFUNCTION_H__
#define __DNT_TROUBLECODEFUNCTION_H__

#include <DNTGlobal.h>
#include <DNTTroubleCodeVector.h>

class DNT_DIAG_DECL DNTTroubleCodeFunction
{
  friend class DNTAbstractECU;
private:
  RTroubleCodeFunctionPtr _native;
  DNTTroubleCodeVector _tcs;
private:
  DNTTroubleCodeFunction(const RTroubleCodeFunctionPtr &native = RTroubleCodeFunctionPtr());
public:
  DNTTroubleCodeFunction(const DNTTroubleCodeFunction &other);
  DNTTroubleCodeFunction& operator=(const DNTTroubleCodeFunction &other);
  ~DNTTroubleCodeFunction();
  bool readCurrent();
  bool readHistory();
  bool clear();
  DNTTroubleCodeVector getTroubleCodes();
};

#endif // __DNT_TROUBLECODEFUNCTION_H__
