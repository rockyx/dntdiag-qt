#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_LIVEDATAITEM_H__
#define __DNT_LIVEDATAITEM_H__

#include <DNTGlobal.h>
#include <QString>

class DNT_DIAG_DECL DNTLiveDataItem
{
  friend class DNTLiveDataList;
private:
  RLiveDataItemPtr _native;
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
  DNTLiveDataItem(const RLiveDataItemPtr &native);
  void getDatas();
public:
  DNTLiveDataItem();
  DNTLiveDataItem(const DNTLiveDataItem &other);
  DNTLiveDataItem& operator=(const DNTLiveDataItem &other);
  ~DNTLiveDataItem();
  const QString &shortName() const;
  const QString &content() const;
  const QString &unit() const;
  const QString &defaultValue() const;
  const QString &description() const;
  const QString &cmdName() const;
  const QString &cmdClass() const;
  int index() const;
  int position() const;
  bool isEnabled() const;
  bool isShowed() const;
  bool isOutOfRange() const;
  QString minValue();
  QString maxValue();
  QByteArray command();
  const QString &value() const;
  DNT_DIAG_DECL friend bool operator==(const DNTLiveDataItem &left, const DNTLiveDataItem &right);
};

DNT_DIAG_DECL bool operator==(const DNTLiveDataItem &left, const DNTLiveDataItem &right);

#endif // __DNT_LIVEDATAITEM_H__
