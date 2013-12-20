#include "DNTVehicleDB.h"
#include <dnt/RVehicleDB.h>

using namespace std;

RVehicleDB::RVehicleDB()
{

}

RVehicleDB::RVehicleDB(const QString &absPath, const QString &vName)
  : _path(absPath.toUtf8())
  , _name(vName.toUtf8())
  , _native(new dnt::RVehicleDB(string(_path.data(), _path.length()), string(_name.data(), _name.length())))
{
}

const dnt::RVehicleDBPtr &RVehicleDB::getNative() const
{
  return _native;
}

bool RVehicleDB::open()
{
  if (_native) return _native->open();
  return false;
}

bool RVehicleDB::open(const QString &absPath, const QString &vName)
{
  _path = absPath.toUtf8();
  _name = vName.toUtf8();
  _native.reset(new dnt::RVehicleDB(string(_path.data(), _path.length()), string(_name.data(), _name.length())));
  return _native->open();
}

void RVehicleDB::close()
{
  if (_native) _native->close();
}

QString RVehicleDB::getText(const QString &name, const QString &sys)
{
  if (!_native) return QString();
  auto nameUtf8 = name.toUtf8();
  auto sysUtf8 = sys.toUtf8();
  auto str = _native->text()->get(string(nameUtf8.data(), nameUtf8.length()), string(sysUtf8.data(), sysUtf8.length()));
  return QString::fromUtf8(str.c_str(), str.length());
}

