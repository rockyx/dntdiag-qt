#include "DNTRegister.h"
#include <dnt/RRegister.h>
#include "DNTTroubleCodeVector.h"

using namespace std;

void RRegister::init(const QString &path)
{
  qRegisterMetaType<RTroubleCodeVector>("RTroubleCodeVector");
  auto utf8 = path.toUtf8();
  dnt::RRegisterInst().init(string(utf8.data(), utf8.length()));
}

bool RRegister::check()
{
  return dnt::RRegisterInst().check();
}

QString RRegister::idCode()
{
  auto idCode = dnt::RRegisterInst().getIdCode();
  return QString::fromUtf8(idCode.c_str(), idCode.length());
}

void RRegister::save(const QString &text)
{
  auto utf8 = text.toUtf8();
  dnt::RRegisterInst().save(string(utf8.data(), utf8.length()));
}
