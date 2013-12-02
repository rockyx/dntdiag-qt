#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_DATASTREAMFUNCTION_H__
#define __DNT_DATASTREAMFUNCTION_H__

#include <DNTGlobal.h>
#include <DNTLiveDataList.h>

class DNT_DIAG_DECL DNTDataStreamFunction
{
  friend class DNTAbstractECU;
private:
  RDataStreamFunctionPtr _native;
  DNTLiveDataList _ldl;
private:
  DNTDataStreamFunction(const RDataStreamFunctionPtr &native = RDataStreamFunctionPtr());
public:
  DNTDataStreamFunction(const DNTDataStreamFunction &other);
  DNTDataStreamFunction& operator=(const DNTDataStreamFunction &other);
  ~DNTDataStreamFunction();
  void stopRead();
  void stopCalc();
  bool readData();
  bool readDataOnce();
  bool calcData();
  bool calcDataOnce();
  DNTLiveDataList &getLiveData();
};


#endif // __DNT_DATASTREAMFUNCTION_H__

