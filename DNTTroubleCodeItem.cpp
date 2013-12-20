#include "DNTTroubleCodeItem.h"
#include <dnt/RTroubleCodeItem.h>

void RTroubleCodeItem::prepareData()
{
  if (!_native)
    return;

  auto str = _native->getCode();
  _code = QString::fromUtf8(str.c_str(), str.length());

  str = _native->getContent();
  _content = QString::fromUtf8(str.c_str(), str.length());

  str = _native->getDescription();
  _description = QString::fromUtf8(str.c_str(), str.length());
}

RTroubleCodeItem::RTroubleCodeItem(const dnt::RTroubleCodeItemPtr &native)
  : _native(native)
{
  prepareData();
}

RTroubleCodeItem::RTroubleCodeItem()
{
}

const QString &RTroubleCodeItem::getCode() const
{
  return _code;
}

QString &RTroubleCodeItem::getCode()
{
  return _code;
}

QString &RTroubleCodeItem::getContent()
{
  return _content;
}

const QString &RTroubleCodeItem::getContent() const
{
  return _content;
}

QString &RTroubleCodeItem::getDescription()
{
  return _description;
}

const QString &RTroubleCodeItem::getDescription() const
{
  return _description;
}
bool operator == (const RTroubleCodeItem &left, const RTroubleCodeItem &right)
{
  return left._native == right._native;
}
