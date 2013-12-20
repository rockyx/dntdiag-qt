#include "DNTLiveDataItem.h"
#include <dnt/RLiveDataItem.h>

RLiveDataItem::RLiveDataItem(const dnt::RLiveDataItemPtr &native)
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

RLiveDataItem::RLiveDataItem()
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

void RLiveDataItem::getDatas()
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

const QString &RLiveDataItem::shortName() const
{
  return _shortName;
}

const QString &RLiveDataItem::content() const
{
  return _content;
}

const QString &RLiveDataItem::unit() const
{
  return _unit;
}

const QString &RLiveDataItem::defaultValue() const
{
  return _defaultValue;
}

const QString &RLiveDataItem::description() const
{
  return _description;
}

const QString &RLiveDataItem::cmdName() const
{
  return _cmdName;
}

const QString &RLiveDataItem::cmdClass() const
{
  return _cmdClass;
}

const QString &RLiveDataItem::minValue() const
{
  return _minValue;
}

const QString &RLiveDataItem::maxValue() const
{
  return _maxValue;
}

int RLiveDataItem::index()
{
  return _index;
}

int RLiveDataItem::position()
{
  return _native->getPosition();
}

const QByteArray &RLiveDataItem::command() const
{
  return _cmd;
}

const QString &RLiveDataItem::value() const
{
  auto str = _native->getValue();
  _value = QString::fromUtf8(str.c_str(), str.length());
  return _value;
}

bool RLiveDataItem::isEnabled() const
{
  return _native->isEnabled();
}

bool RLiveDataItem::isShowed() const
{
  return _native->isShowed();
}

bool RLiveDataItem::isOutOfRange()
{
  return _native->isOutOfRange();
}

void RLiveDataItem::setIsShowed(bool value)
{
  if (_native)
    _native->setShowed(value);
}

bool operator == (const RLiveDataItem &left, const RLiveDataItem &right)
{
  return left._native == right._native;
}
