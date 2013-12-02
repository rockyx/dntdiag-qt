#include "DNTSystemDB.h"
#include <dnt/RSystemDB.h>

using namespace std;

void DNTSystemDB::init(const QString &path)
{
  auto utf8 = path.toUtf8();
  RSystemDBInst().init(string(utf8.data(), utf8.length()));
}

QString DNTSystemDB::queryText(const QString &name)
{
  auto utf8 = name.toUtf8();
  auto ret = RSystemDBInst().queryText(string(utf8.data(), utf8.length()));
  return QString::fromUtf8(ret.c_str(), ret.length());
}
