#include "DNTVehicleDB.h"
#include <dnt/RVehicleDB.h>

using namespace std;

DNTVehicleDB::DNTVehicleDB(const QString &absPath, const QString &vName)
  : _native()
{
  auto absPathUtf8 = absPath.toUtf8();
  auto vNameUtf8 = vName.toUtf8();
  _native.reset(new RVehicleDB(string(absPathUtf8.data(), absPathUtf8.length()), string(vNameUtf8.data(), vNameUtf8.length())));
}

DNTVehicleDB::~DNTVehicleDB()
{

}

DNTVehicleDB::DNTVehicleDB(const DNTVehicleDB &other)
  : _native(other._native)
{

}

DNTVehicleDB& DNTVehicleDB::operator =(const DNTVehicleDB &other)
{
  if (this == &other) return *this;
  _native = other._native;
  return *this;
}

bool DNTVehicleDB::open()
{
  return _native->open();
}

void DNTVehicleDB::close()
{
  _native->close();
}

RVehicleDBPtr &DNTVehicleDB::getNative()
{
  return _native;
}

const RVehicleDBPtr &DNTVehicleDB::getNative() const
{
  return _native;
}

QString DNTVehicleDB::getText(const QString &name, const QString &sys)
{
  auto nameUtf8 = name.toUtf8();
  auto sysUtf8 = sys.toUtf8();
  auto str = _native->text()->get(string(nameUtf8.data(), nameUtf8.length()), string(sysUtf8.data(), sysUtf8.length()));
  return QString::fromUtf8(str.c_str(), str.length());
}
