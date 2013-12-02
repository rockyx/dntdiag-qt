#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_SERIALPORTTHREAD_H__
#define __DNT_SERIALPORTTHREAD_H__

#include <QtSerialPort/QSerialPortInfo>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QSharedPointer>
#include <DNTGlobal.h>


class DNTSerialPortThread : public QObject
{
private:
  RIOBufferPtr _buffer;
  RSerialPortPtr _port;
  QRunnable *_read;
  QRunnable *_write;
  QThreadPool _pool;
public:
  DNTSerialPortThread(const RIOBufferPtr& buffer);
  ~DNTSerialPortThread();
  RSerialPortPtr getPort();
  void start();
private slots:
};

#endif // __DNT_SERIALPORTHREAD_H__
