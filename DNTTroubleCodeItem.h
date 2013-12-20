#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_TROUBLECODEITEM_H__
#define __DNT_TROUBLECODEITEM_H__

#include <DNTGlobal.h>

class RTroubleCodeItem;
typedef QSharedPointer<RTroubleCodeItem> RTroubleCodeItemPtr;

class DNT_DIAG_DECL RTroubleCodeItem
{
  friend class RTroubleCodeVector;
  friend class QVector<RTroubleCodeItem>;
  friend bool operator == (const RTroubleCodeItem &left, const RTroubleCodeItem &right);
private:
  dnt::RTroubleCodeItemPtr _native;
  QString _code;
  QString _content;
  QString _description;
private:
  RTroubleCodeItem(const dnt::RTroubleCodeItemPtr &native);
  void prepareData();
public:
  RTroubleCodeItem();
  const QString &getCode() const;
  QString& getCode();
  const QString &getContent() const;
  QString &getContent();
  const QString &getDescription() const;
  QString &getDescription();
};

bool operator == (const RTroubleCodeItem &left, const RTroubleCodeItem &right);

#endif // __DNT_TROUBLECODEITEM_H__
