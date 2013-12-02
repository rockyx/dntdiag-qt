#include "DNTLiveDataItem.h"
#include <dnt/RLiveDataItem.h>

DNTLiveDataItem::DNTLiveDataItem(const RLiveDataItemPtr &native)
  : _native(native)
  , _shortName()
  , _content()
  , _unit()
  , _defaultValue()
  , _description()
  , _cmdName()
  , _cmdClass()
  , _minValue()
  , _maxValue()
  , _index(-2)
  , _cmd()
  , _value()
{
  getDatas();
}

DNTLiveDataItem::DNTLiveDataItem()
  : _native()
  , _shortName()
  , _content()
  , _unit()
  , _defaultValue()
  , _description()
  , _cmdName()
  , _cmdClass()
  , _minValue()
  , _maxValue()
  , _index(-2)
  , _cmd()
  , _value()
{

}

DNTLiveDataItem::DNTLiveDataItem(const DNTLiveDataItem &other)
  : _native(other._native)
  , _shortName(other._shortName)
  , _content(other._content)
  , _unit(other._unit)
  , _defaultValue(other._defaultValue)
  , _description(other._description)
  , _cmdName(other._cmdName)
  , _cmdClass(other._cmdClass)
  , _minValue(other._minValue)
  , _maxValue(other._maxValue)
  , _index(other._index)
  , _cmd(other._cmd)
{

}

DNTLiveDataItem& DNTLiveDataItem::operator =(const DNTLiveDataItem &other)
{
  if (this == &other) return *this;
  _native = other._native;
  _shortName = other._shortName;
  _content = other._content;
  _unit = other._unit;
  _defaultValue = other._defaultValue;
  _description = other._description;
  _cmdName = other._cmdName;
  _cmdClass = other._cmdClass;
  _minValue = other._minValue;
  _maxValue = other._maxValue;
  _index = other._index;
  _cmd = other._cmd;
  return *this;
}

DNTLiveDataItem::~DNTLiveDataItem()
{
}

void DNTLiveDataItem::getDatas()
{
  if (!_native)
    return;
  auto text = _native->getShortName();
  _shortName = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getContent();
  _content = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getUnit();
  _unit = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getDefaultValue();
  _defaultValue = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getDescription();
  _defaultValue = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getCmdName();
  _cmdName = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getCmdClass();
  _cmdClass = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getMinValue();
  _minValue = QString::fromUtf8(text.c_str(), text.length());

  text = _native->getMaxValue();
  _maxValue = QString::fromUtf8(text.c_str(), text.length());

  _index = _native->getIndex();

  auto buff = _native->getCommand();
  _cmd = QByteArray((char*)buff.data(), buff.length());
}

const QString &DNTLiveDataItem::shortName() const
{
  return _shortName;
}

const QString &DNTLiveDataItem::content() const
{
  return _content;
}

const QString &DNTLiveDataItem::unit() const
{
  return _unit;
}

const QString &DNTLiveDataItem::defaultValue() const
{
  return _defaultValue;
}

const QString &DNTLiveDataItem::description() const
{
  return _description;
}

const QString &DNTLiveDataItem::cmdName() const
{
  return _cmdName;
}

const QString &DNTLiveDataItem::cmdClass() const
{
  return _cmdClass;
}

QString DNTLiveDataItem::minValue()
{
  return _minValue;
}

QString DNTLiveDataItem::maxValue()
{
  return _maxValue;
}

int DNTLiveDataItem::index() const
{
  return _index;
}

int DNTLiveDataItem::position() const
{
  return _native->getPosition();
}

QByteArray DNTLiveDataItem::command()
{
  return _cmd;
}

const QString &DNTLiveDataItem::value() const
{
  auto str = _native->getValue();
  _value = QString::fromUtf8(str.c_str(), str.length());
  return _value;
}

bool DNTLiveDataItem::isEnabled() const
{
  return _native->isEnabled();
}

bool DNTLiveDataItem::isShowed() const
{
  return _native->isShowed();
}

bool DNTLiveDataItem::isOutOfRange() const
{
  return _native->isOutOfRange();
}

bool operator==(const DNTLiveDataItem &left, const DNTLiveDataItem &right)
{
  if (&left == &right) return true;
  return left._native == right._native;
}
