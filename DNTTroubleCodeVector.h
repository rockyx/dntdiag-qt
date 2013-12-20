#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_TROUBLECODEVECTOR_H__
#define __DNT_TROUBLECODEVECTOR_H__

#include <DNTTroubleCodeItem.h>

class DNT_DIAG_DECL RTroubleCodeVector : public QVector<RTroubleCodeItem>
{
  friend class RTroubleCodeFunction;
  friend class RTroubleCodeData;
private:
  bool _null;
private:
  RTroubleCodeVector(const dnt::RTroubleCodeVectorPtr &native);
  void addItems();
public:
  RTroubleCodeVector();
  bool isNull() const;
};

Q_DECLARE_METATYPE(RTroubleCodeVector)

typedef QSharedPointer<RTroubleCodeVector> RTroubleCodeVectorPtr;

#endif // __DNT_TROUBLECODEVECTOR_H__
