#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_VEHICLEDB_H__
#define __DNT_VEHICLEDB_H__

#include <DNTGlobal.h>

class DNT_DIAG_DECL RVehicleDB
{
  template<typename NativePtr, typename Model> friend class RAbstractECU;
private:
  QByteArray _path;
  QByteArray _name;
  dnt::RVehicleDBPtr _native;
protected:
  const dnt::RVehicleDBPtr &getNative() const;
public:
  RVehicleDB();
  RVehicleDB(const QString &absPath, const QString &vName);
  bool open();
  bool open(const QString &absPath, const QString &vName);
  void close();
  QString getText(const QString &name, const QString &sys);
};

typedef QSharedPointer<RVehicleDB> RVehicleDBPtr;

#endif // __DNT_VEHICLEDB_H__
