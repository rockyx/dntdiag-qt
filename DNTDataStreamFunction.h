#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_DATASTREAMFUNCTION_H__
#define __DNT_DATASTREAMFUNCTION_H__

#include <DNTLiveDataList.h>

class DNT_DIAG_DECL RDataStreamFunction : public QObject
{
  Q_OBJECT
  template<typename NativePtr, typename Model> friend class RAbstractECU;
private:
  dnt::RDataStreamFunctionPtr _native;
  RLiveDataList _ldl;
  QFutureWatcher<bool> _dataStreamReadWatcher;
  QFuture<bool> _dataStreamReadFuture;
  QFutureWatcher<bool> _dataStreamCalcWatcher;
  QFuture<bool> _dataStreamCalcFuture;
  QFutureWatcher<bool> _dataStreamOnceWatcher;
  QFuture<bool> _dataStreamOnceFuture;
private:
  RDataStreamFunction(const dnt::RDataStreamFunctionPtr &native = dnt::RDataStreamFunctionPtr(), QObject *parent = 0);
  void stopRead();
  void stopCalc();
  bool readData();
  bool readDataOnce();
  bool calcData();
  bool calcDataOnce();
  bool readCalcOnce();
public:
  RDataStreamFunction(const RDataStreamFunction &other);
  RDataStreamFunction& operator = (const RDataStreamFunction &other);
  RLiveDataList& getLiveData();
  const RLiveDataList& getLiveData() const;
  void start();
  void stop();
  void once();
  bool result();
private slots:
  void finished();
  void onceFinished();
signals:
  void dataStreamFinished(bool);
};

typedef QSharedPointer<RDataStreamFunction> RDataStreamFunctionPtr;


#endif // __DNT_DATASTREAMFUNCTION_H__

