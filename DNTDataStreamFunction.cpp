#include "DNTDataStreamFunction.h"
#include <dnt/RDataStreamFunction.h>

RDataStreamFunction::RDataStreamFunction(const dnt::RDataStreamFunctionPtr &native, QObject *parent)
  : QObject(parent)
  , _native(native)
  , _ldl(_native ? _native->getLiveDataItems() : dnt::RLiveDataListPtr())
  , _dataStreamReadWatcher()
  , _dataStreamReadFuture()
  , _dataStreamCalcWatcher()
  , _dataStreamCalcFuture()
  , _dataStreamOnceWatcher()
  , _dataStreamOnceFuture()
{
}

RDataStreamFunction::RDataStreamFunction(const RDataStreamFunction &other)
  : _native(other._native)
  , _ldl(other._ldl)
  , _dataStreamReadWatcher()
  , _dataStreamReadFuture()
  , _dataStreamCalcWatcher()
  , _dataStreamCalcFuture()
  , _dataStreamOnceWatcher()
  , _dataStreamOnceFuture()
{

}

RDataStreamFunction &RDataStreamFunction::operator = (const RDataStreamFunction &other)
{
  if (this == &other) return *this;
  _native = other._native;
  _ldl = other._ldl;
  return *this;
}

void RDataStreamFunction::stopRead()
{
  if (_native)
    _native->stopRead();
}

void RDataStreamFunction::stopCalc()
{
  if (_native)
    _native->stopCalc();
}

bool RDataStreamFunction::readData()
{
  if (!_native) return false;
  return _native->readData();
}

bool RDataStreamFunction::readDataOnce()
{
  if (!_native) return false;
  return _native->readDataOnce();
}

bool RDataStreamFunction::calcData()
{
  if (!_native) return false;
  return _native->calcData();
}

bool RDataStreamFunction::calcDataOnce()
{
  if (!_native) return false;
  return _native->calcDataOnce();
}

RLiveDataList& RDataStreamFunction::getLiveData()
{
  return _ldl;
}

const RLiveDataList& RDataStreamFunction::getLiveData() const
{
  return _ldl;
}

void RDataStreamFunction::finished()
{
  auto ret = _dataStreamReadFuture.result() && _dataStreamCalcFuture.result();
  emit dataStreamFinished(ret);
}

void RDataStreamFunction::start()
{
  _dataStreamReadWatcher.disconnect();
  _dataStreamCalcWatcher.disconnect();

  connect(&_dataStreamReadWatcher, SIGNAL(finished()), this, SLOT(finished()));

  _dataStreamReadFuture = QtConcurrent::run(this, &RDataStreamFunction::readData);
  _dataStreamCalcFuture = QtConcurrent::run(this, &RDataStreamFunction::calcData);
}

void RDataStreamFunction::stop()
{
  stopRead();
  stopCalc();

  _dataStreamCalcWatcher.waitForFinished();
  _dataStreamReadWatcher.waitForFinished();
}

bool RDataStreamFunction::readCalcOnce()
{
  return readDataOnce() && calcDataOnce();
}

void RDataStreamFunction::onceFinished()
{
  auto ret = _dataStreamOnceFuture.result();
  emit dataStreamFinished(ret);
}

void RDataStreamFunction::once()
{
  _dataStreamOnceWatcher.disconnect();
  connect(&_dataStreamOnceWatcher, SIGNAL(finished()), this, SLOT(onceFinished()));

  _dataStreamOnceFuture = QtConcurrent::run(this, &RDataStreamFunction::readCalcOnce);
}


