#include "DNTSystemDB.h"
#include <dnt/RSystemDB.h>

using namespace std;

void RSystemDB::init(const QString &path)
{
  auto utf8 = path.toUtf8();
  dnt::RSystemDBInst().init(string(utf8.data(), utf8.length()));
}

QString RSystemDB::queryText(const QString &name)
{
  auto utf8 = name.toUtf8();
  auto ret = dnt::RSystemDBInst().queryText(string(utf8.data(), utf8.length()));
  return QString::fromUtf8(ret.c_str(), ret.length());
}
