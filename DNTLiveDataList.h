#ifdef _MSC_VER
#pragma once
#endif

#ifndef __DNT_LIVEDATALIST_H__
#define __DNT_LIVEDATALIST_H__

#include <QList>
#include <DNTGlobal.h>
#include <DNTLiveDataItem.h>

class DNT_DIAG_DECL DNTLiveDataList
{
  friend class DNTDataStreamFunction;
public:
  typedef QList<DNTLiveDataItem> Elements;
private:
  RLiveDataListPtr _native;
  Elements _data;
  Elements _enabledItems;
  Elements _showedItems;
private:
  void addItems();
  void fillEnabledItems();
  void fillShowedItems();
private:
  DNTLiveDataList(const RLiveDataListPtr &native = RLiveDataListPtr());
public:
  DNTLiveDataList(const DNTLiveDataList &other);
  DNTLiveDataList& operator=(const DNTLiveDataList &other);
  ~DNTLiveDataList();
//  int enabledCount();
//  int enabledCount() const;
//  int showedCount();
//  int showedCount() const;
  int nextShowedIndex();
  int nextShowedIndex() const;
//  int getEnabledIndex(int index);
//  int getEnabledIndex(int index) const;
  int getShowedPosition(int index);
  int getShowedPosition(int index) const;
//  int getShowedIndex(int index);
//  int getShowedIndex(int index) const;
//  void collateEnable();
//  void collateShowed();
  void collate();
  bool isEmpty();
  bool isEmpty() const;
  DNTLiveDataItem& operator[](int index);
  const DNTLiveDataItem& operator[](int index) const;
//  Elements items();
  Elements getEnabledItems();
  Elements getShowedItems();
};

#endif // __DNT_LIVEDATALIST_H__
