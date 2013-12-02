#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_COMMBOX_H__
#define __DNT_COMMBOX_H__

#include <QObject>
#include <QSharedPointer>
#include <DNTGlobal.h>
#ifndef Q_MOC_RUN
#include <dnt/RCommboxVer.h>
#endif

class CommboxPrivate;
typedef QSharedPointer<CommboxPrivate> CommboxPrivatePtr;
class DNT_DIAG_DECL DNTCommbox : public QObject
{
  Q_OBJECT
  Q_PROPERTY(RCommboxVer version READ getVersion)
  Q_ENUMS(RCommboxVer)
public:
private:
  RCommboxVer _ver;
  RIOBufferPtr _buffer;
  RICommboxPtr _box;
  DNTSerialPortThreadPtr _port;
private:
  bool openC168SerialModel();
  bool openW80SerialModel();
  void closeSerialPort();
public:
  DNTCommbox(RCommboxVer ver);
  DNTCommbox(const DNTCommbox &other);
  DNTCommbox &operator=(const DNTCommbox &other);
  ~DNTCommbox();
  RCommboxVer getVersion();
  RICommboxPtr & getNative();
  const RICommboxPtr &getNative() const;
  bool connect();
  bool disconnect();
};

#endif // __DNT_COMMBOX_H__
