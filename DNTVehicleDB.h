#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_VEHICLEDB_H__
#define __DNT_VEHICLEDB_H__

#include <QString>
#include <QByteArray>
#include <QSharedPointer>
#include <DNTGlobal.h>

class DNT_DIAG_DECL DNTVehicleDB
{
private:
  RVehicleDBPtr _native;
public:
  DNTVehicleDB(const QString &absPath, const QString &vName);
  DNTVehicleDB(const DNTVehicleDB &other);
  DNTVehicleDB& operator = (const DNTVehicleDB &other);
  ~DNTVehicleDB();
  bool open();
  void close();
  QString getText(const QString &name, const QString &sys);
  RVehicleDBPtr &getNative();
  const RVehicleDBPtr &getNative() const;
};

#endif // __DNT_VEHICLEDB_H__
