#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ABSTRACTECU_H__
#define __DNT_ABSTRACTECU_H__

#include <QString>
#include <DNTGlobal.h>
#include <DNTTroubleCodeFunction.h>
#include <DNTDataStreamFunction.h>
#include <DNTActiveTestFunction.h>

class DNT_DIAG_DECL DNTAbstractECU
{
private:
  RAbstractECUPtr _native;
  DNTTroubleCodeFunction _troubleCode;
  DNTDataStreamFunction _dataStream;
  DNTDataStreamFunction _freezeStream;
  DNTActiveTestFunction _activeTest;
private:
  void setFunctions();
protected:
  template<typename DeviceNative>
  void setNative(const DeviceNative &native)
  {
    _native = boost::dynamic_pointer_cast<RAbstractECU>(native);
  }
private:
  DNTAbstractECU(const DNTAbstractECU &other);
  DNTAbstractECU &operator=(const DNTAbstractECU &other);
public:
  DNTAbstractECU();
  ~DNTAbstractECU();
  QString getLastInfo();
  bool ioChannelInit();
  DNTTroubleCodeFunction getTroubleCode();
  DNTDataStreamFunction getDataStream();
  DNTDataStreamFunction getFreezeStream();
  DNTActiveTestFunction getActiveTest();
};

#endif // __DNT_ABSTRACTECU_H__
