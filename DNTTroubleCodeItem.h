#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_TROUBLECODEITEM_H__
#define __DNT_TROUBLECODEITEM_H__

#include <QString>
#include <QSharedPointer>
#include <DNTGlobal.h>

class DNT_DIAG_DECL DNTTroubleCodeItem
{
  friend class DNTTroubleCodeVector;
  friend class QVector<DNTTroubleCodeItem>;
private:
  RTroubleCodeItemPtr _native;
  QString _code;
  QString _content;
  QString _description;
private:
  DNTTroubleCodeItem(const RTroubleCodeItemPtr &native = RTroubleCodeItemPtr());
public:
  DNTTroubleCodeItem(const DNTTroubleCodeItem &other);
  DNTTroubleCodeItem & operator=(const DNTTroubleCodeItem &other);
  friend bool operator==(const DNTTroubleCodeItem &left, const DNTTroubleCodeItem &right);
  ~DNTTroubleCodeItem();
  const QString& getCode() const;
  const QString& getContent() const;
  const QString& getDescription() const;
};

bool operator==(const DNTTroubleCodeItem &left, const DNTTroubleCodeItem &right);

#endif // __DNT_TROUBLECODEITEM_H__
