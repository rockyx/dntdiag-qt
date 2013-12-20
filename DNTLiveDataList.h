#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_LIVEDATALIST_H__
#define __DNT_LIVEDATALIST_H__

#include <DNTLiveDataItem.h>

class DNT_DIAG_DECL RLiveDataList
{
  friend class RDataStreamFunction;
public:
  typedef QList<RLiveDataItem> Elements;
private:
  dnt::RLiveDataListPtr _native;
  Elements _data;
  Elements _enabledItems;
  Elements _showedItems;
private:
  void saveItems();
  void fillEnabledItems();
  void fillShowedItems();
private:
  RLiveDataList(const dnt::RLiveDataListPtr &native = dnt::RLiveDataListPtr());
public:
  int nextShowedIndex();
  int getShowedPosition(int index);
  void collate();
  bool isEmpty();
  RLiveDataItem & operator[](int index);
  const RLiveDataItem& operator[](int index) const;
  const Elements& getEnabledItems() const;
  const Elements& getShowedItems() const;
  inline int size()
  {
    return _data.size();
  }
};

typedef QSharedPointer<RLiveDataList> RLiveDataListPtr;

#endif // __DNT_LIVEDATALIST_H__
