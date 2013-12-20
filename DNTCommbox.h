#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_COMMBOX_H__
#define __DNT_COMMBOX_H__

#ifndef Q_MOC_RUN
#include <dnt/RCommboxVer.h>
#endif
#include <DNTSerialPortThread.h>

class DNT_DIAG_DECL RCommbox : public QObject
{
  Q_OBJECT
public:
  template<typename NativePtr, typename Model> friend class RAbstractECU;
  enum Version
  {
    UNKNOW = dnt::RCommboxVer::UNKNOW,
    C168 = dnt::RCommboxVer::C168,
    W80 = dnt::RCommboxVer::W80,
    ELM327 = dnt::RCommboxVer::ELM327,
    TL718 = dnt::RCommboxVer::TL718,
    LAST = dnt::RCommboxVer::LAST
  };

  Q_PROPERTY(Version version READ getVersion)
  Q_ENUMS(Versions)
public:
private:
  Version _ver;
  dnt::RIOBufferPtr _buffer;
  dnt::RICommboxPtr _box;
  RSerialPortThreadPtr _port;
private:
  bool openC168SerialModel();
  bool openW80SerialModel();
  void closeSerialPort();
protected:
  const dnt::RICommboxPtr& getNative() const;
public:
  RCommbox();
  RCommbox(Version ver);
  Version getVersion();
  void setVersion(Version ver);
  bool connect();
  bool connect(Version ver);
  bool disconnect();
};

typedef QSharedPointer<RCommbox> RCommboxPtr;

#endif // __DNT_COMMBOX_H__
