#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_ABSTRACTECU_H__
#define __DNT_ABSTRACTECU_H__

#ifndef Q_MOC_RUN
#include <dnt/RAbstractECU.h>
#endif
#include <DNTCommbox.h>
#include <DNTVehicleDB.h>
#include <DNTTroubleCodeFunction.h>
#include <DNTDataStreamFunction.h>
#include <DNTActiveTestFunction.h>

class RECUInterface
{
public:
  virtual QString getLastInfo() = 0;
  virtual bool ioChannelInit() = 0;
  virtual RTroubleCodeFunction *getTroubleCode() const = 0;
  virtual RDataStreamFunction *getDataStream() const = 0;
  virtual RDataStreamFunction *getFreezeStream() const = 0;
  virtual RActiveTestFunction *getActiveTest() const = 0;
};

typedef QSharedPointer<RECUInterface> RECUInterfacePtr;

template<typename Native, typename Model>
class RAbstractECU : public RECUInterface
{
public:
  typedef Native NativeType;
  typedef boost::shared_ptr<Native> NativePtr;
  typedef Model ModelType;
protected:
  NativePtr _native;
private:
  dnt::RAbstractECUPtr _baseNative;
  RTroubleCodeFunction *_troubleCode;
  RDataStreamFunction *_dataStream;
  RDataStreamFunction *_freezeStream;
  RActiveTestFunction *_activeTest;
public:
  RAbstractECU(const RCommbox & commbox, const RVehicleDB &db, Model model)
    : _native(new NativeType(commbox.getNative(), db.getNative(), model))
    , _baseNative(boost::dynamic_pointer_cast<dnt::RAbstractECU>(_native))
    , _troubleCode(new RTroubleCodeFunction(_native->getTroubleCode()))
    , _dataStream(new RDataStreamFunction(_native->getDataStream()))
    , _freezeStream(new RDataStreamFunction(_native->getFreezeStream()))
    , _activeTest(new RActiveTestFunction(_native->getActiveTest()))
  {

  }

  virtual ~RAbstractECU()
  {
    delete _troubleCode;
    delete _dataStream;
    delete _freezeStream;
    delete _activeTest;
  }

  QString getLastInfo()
  {
    auto str = _baseNative->getLastInfo();
    return QString::fromUtf8(str.c_str(), str.length());
  }

  bool ioChannelInit()
  {
    return _baseNative->ioChannelInit();
  }

  RTroubleCodeFunction *getTroubleCode() const
  {
    return _troubleCode;
  }

  RDataStreamFunction *getDataStream() const
  {
    return _dataStream;
  }

  RDataStreamFunction *getFreezeStream() const
  {
    return _freezeStream;
  }

  RActiveTestFunction *getActiveTest() const
  {
    return _activeTest;
  }
};

#endif // __DNT_ABSTRACTECU_H__
