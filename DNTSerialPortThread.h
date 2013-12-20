#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_SERIALPORTTHREAD_H__
#define __DNT_SERIALPORTTHREAD_H__

#include <DNTGlobal.h>

class RSerialPortThread;
typedef QSharedPointer<RSerialPortThread> RSerialPortThreadPtr;

class RSerialPortThread : public QObject
{
private:
  dnt::RIOBufferPtr _buffer;
  dnt::RSerialPortPtr _port;
  QRunnable *_read;
  QRunnable *_write;
  QThreadPool _pool;
public:
  RSerialPortThread(const dnt::RIOBufferPtr& buffer);
  ~RSerialPortThread();
  dnt::RSerialPortPtr getPort();
  void start();
private slots:
};

#endif // __DNT_SERIALPORTHREAD_H__
