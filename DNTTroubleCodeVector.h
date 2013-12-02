#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_TROUBLECODEVECTOR_H__
#define __DNT_TROUBLECODEVECTOR_H__

#include <QVector>
#include <DNTTroubleCodeItem.h>

class DNT_DIAG_DECL DNTTroubleCodeVector : public QVector<DNTTroubleCodeItem>
{
  friend class DNTTroubleCodeFunction;
private:
  RTroubleCodeVectorPtr _native;
private:
  DNTTroubleCodeVector(const RTroubleCodeVectorPtr &native);
  void addItems();
public:
  DNTTroubleCodeVector();
  DNTTroubleCodeVector(const DNTTroubleCodeVector &other);
  DNTTroubleCodeVector& operator=(const DNTTroubleCodeVector& other);
  ~DNTTroubleCodeVector();
};

#endif // __DNT_TROUBLECODEVECTOR_H__
