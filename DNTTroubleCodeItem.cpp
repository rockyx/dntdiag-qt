#include "DNTTroubleCodeItem.h"
#include <dnt/RTroubleCodeItem.h>

DNTTroubleCodeItem::DNTTroubleCodeItem(const RTroubleCodeItemPtr &native)
  : _native(native)
{
  auto str = _native->getCode();
  _code = QString::fromUtf8(str.c_str(), str.length());

  str = _native->getContent();
  _content = QString::fromUtf8(str.c_str(), str.length());

  str = _native->getDescription();
  _description = QString::fromUtf8(str.c_str(), str.length());

}

DNTTroubleCodeItem::DNTTroubleCodeItem(const DNTTroubleCodeItem &other)
  : _native(other._native)
{

}

DNTTroubleCodeItem& DNTTroubleCodeItem::operator =(const DNTTroubleCodeItem &other)
{
  if (this == &other) return *this;
  _native = other._native;
  return *this;
}

DNTTroubleCodeItem::~DNTTroubleCodeItem()
{

}

bool operator ==(const DNTTroubleCodeItem &left, const DNTTroubleCodeItem &right)
{
  if (&left == &right) return true;
  return left._native == right._native;
}

const QString &DNTTroubleCodeItem::getCode() const
{
  return _code;
}

const QString &DNTTroubleCodeItem::getContent() const
{
  return _content;
}

const QString &DNTTroubleCodeItem::getDescription() const
{
  return _description;
}
