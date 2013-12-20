#include "DNTTroubleCodeFunction.h"

RTroubleCodeFunction::RTroubleCodeFunction(const dnt::RTroubleCodeFunctionPtr &native)
  : _native(native)
  , _currentWatcher()
  , _currentFuture()
  , _historyWatcher()
  , _historyFuture()
  , _clearWatcher()
  , _clearFuture()
{

}

bool RTroubleCodeFunction::tryReadCurrent()
{
  if (_currentWatcher.isRunning()) return false;
  if (!_native) return false;

  _currentWatcher.disconnect();
  connect(&_currentWatcher, SIGNAL(finished()), this, SLOT(sendCurrentFinished()));
  _currentFuture = QtConcurrent::run(_native.get(), &dnt::RTroubleCodeFunction::current);
  _currentWatcher.setFuture(_currentFuture);

  return true;
}

bool RTroubleCodeFunction::tryReadHistory()
{
  if (_historyWatcher.isRunning()) return false;
  if (!_native) return false;

  _historyWatcher.disconnect();
  connect(&_historyWatcher, SIGNAL(finished()), this, SLOT(sendHistoryFinished()));
  _historyFuture = QtConcurrent::run(_native.get(), &dnt::RTroubleCodeFunction::history);
  _historyWatcher.setFuture(_historyFuture);
  return true;
}

bool RTroubleCodeFunction::tryClear()
{
  if (_clearWatcher.isRunning()) return false;
  if (!_native) return false;

  _clearWatcher.disconnect();
  connect(&_clearWatcher, SIGNAL(finished()), this, SLOT(sendClearFinished()));
  _clearFuture = QtConcurrent::run(_native.get(), &dnt::RTroubleCodeFunction::clear);
  _clearWatcher.setFuture(_clearFuture);
  return true;
}

RTroubleCodeVector RTroubleCodeFunction::waitCurrentFinish()
{
  _currentWatcher.waitForFinished();
  return RTroubleCodeVector(_currentFuture.result());
}

RTroubleCodeVector RTroubleCodeFunction::waitHistoryFinish()
{
  _historyWatcher.waitForFinished();
  return RTroubleCodeVector(_historyFuture.result());
}

bool RTroubleCodeFunction::waitClearFinish()
{
  _clearWatcher.waitForFinished();
  return _clearFuture.result();
}

void RTroubleCodeFunction::sendCurrentFinished()
{
  auto ret = RTroubleCodeVector(_currentFuture.result());
  QString message = QString::fromUtf8(_native->getMessage().c_str());
  emit currentFinished(message, ret);
}

void RTroubleCodeFunction::sendHistoryFinished()
{
  auto ret = RTroubleCodeVector(_historyFuture.result());
  QString message = QString::fromUtf8(_native->getMessage().c_str());
  emit historyFinished(message, ret);
}

void RTroubleCodeFunction::sendClearFinished()
{
  auto ret = _clearFuture.result();
  QString message = QString::fromUtf8(_native->getMessage().c_str());
  emit clearFinished(message, ret);
}

QString RTroubleCodeFunction::getMessage()
{
  if (!_native) return QString();
  return QString::fromUtf8(_native->getMessage().c_str());
}

