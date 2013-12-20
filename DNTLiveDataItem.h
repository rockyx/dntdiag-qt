#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_LIVEDATAITEM_H__
#define __DNT_LIVEDATAITEM_H__

#include <DNTGlobal.h>

class DNT_DIAG_DECL RLiveDataItem
{
  friend class RLiveDataList;
  friend bool DNT_DIAG_DECL operator == (const RLiveDataItem &left, const RLiveDataItem &right);
private:
  dnt::RLiveDataItemPtr _native;
  QString _shortName;
  QString _content;
  QString _unit;
  QString _defaultValue;
  QString _description;
  QString _cmdName;
  QString _cmdClass;
  QString _minValue;
  QString _maxValue;
  mutable QString _value;
  int _index;
  QByteArray _cmd;
private:
  RLiveDataItem(const dnt::RLiveDataItemPtr &native);
  void getDatas();
public:
  RLiveDataItem();
  const QString &shortName() const;
  const QString &content() const;
  const QString &unit() const;
  const QString &defaultValue() const;
  const QString &description() const;
  const QString &cmdName() const;
  const QString &cmdClass() const;
  int index();
  int position();
  bool isEnabled() const;
  bool isShowed() const;
  bool isOutOfRange();
  const QString &minValue() const;
  const QString &maxValue() const;
  const QByteArray &command() const;
  const QString &value() const;
  void setIsShowed(bool value);
};

bool DNT_DIAG_DECL operator == (const RLiveDataItem &left, const RLiveDataItem &right);

typedef QSharedPointer<RLiveDataItem> RLiveDataItemPtr;

#endif // __DNT_LIVEDATAITEM_H__
