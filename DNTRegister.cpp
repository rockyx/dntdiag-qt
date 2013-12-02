#include "DNTRegister.h"
#include <dnt/RRegister.h>

using namespace std;

void DNTRegister::init(const QString &path)
{
  auto utf8 = path.toUtf8();
  RRegisterInst().init(string(utf8.data(), utf8.length()));
}

bool DNTRegister::check()
{
  return RRegisterInst().check();
}

QString DNTRegister::idCode()
{
  auto idCode = RRegisterInst().getIdCode();
  return QString::fromUtf8(idCode.c_str(), idCode.length());
}

void DNTRegister::save(const QString &text)
{
  auto utf8 = text.toUtf8();
  RRegisterInst().save(string(utf8.data(), utf8.length()));
}
