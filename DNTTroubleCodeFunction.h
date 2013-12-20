#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_TROUBLECODEFUNCTION_H__
#define __DNT_TROUBLECODEFUNCTION_H__

#ifndef Q_MOC_RUN
#include <dnt/RTroubleCodeFunction.h>
#endif
#include <DNTTroubleCodeVector.h>

class DNT_DIAG_DECL RTroubleCodeFunction : public QObject
{
  Q_OBJECT
  template<typename NativePtr, typename Model> friend class RAbstractECU;
private:
  dnt::RTroubleCodeFunctionPtr _native;
  QFutureWatcher<dnt::RTroubleCodeVectorPtr> _currentWatcher;
  QFuture<dnt::RTroubleCodeVectorPtr> _currentFuture;
  QFutureWatcher<dnt::RTroubleCodeVectorPtr> _historyWatcher;
  QFuture<dnt::RTroubleCodeVectorPtr> _historyFuture;
  QFutureWatcher<bool> _clearWatcher;
  QFuture<bool> _clearFuture;
private:
  RTroubleCodeFunction(const dnt::RTroubleCodeFunctionPtr &native = dnt::RTroubleCodeFunctionPtr());
public:
  // return false if start fail(consider still running, or native is nullptr
  bool tryReadCurrent();
  bool tryReadHistory();
  bool tryClear();
  RTroubleCodeVector waitCurrentFinish();
  RTroubleCodeVector waitHistoryFinish();
  bool waitClearFinish();
  QString getMessage();
public slots:
  void sendCurrentFinished();
  void sendHistoryFinished();
  void sendClearFinished();
signals:
  void currentFinished(const QString &text, const RTroubleCodeVector &tcs);
  void historyFinished(const QString &text, const RTroubleCodeVector &tcs);
  void clearFinished(const QString &text, bool result);
};

typedef QSharedPointer<RTroubleCodeFunction> RTroubleCodeFunctionPtr;

#endif // __DNT_TROUBLECODEFUNCTION_H__
