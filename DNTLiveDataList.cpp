#include "DNTLiveDataList.h"
#include <dnt/RLiveDataList.h>

DNTLiveDataList::DNTLiveDataList(const RLiveDataListPtr &native)
  : _native(native)
  , _data()
{
  addItems();
  fillEnabledItems();
  fillShowedItems();
}

DNTLiveDataList::DNTLiveDataList(const DNTLiveDataList &other)
  : _native(other._native)
  , _data(other._data)
  , _enabledItems(other._enabledItems)
  , _showedItems(other._showedItems)
{

}

DNTLiveDataList& DNTLiveDataList::operator =(const DNTLiveDataList &other)
{
  if (this == &other) return *this;
  _native = other._native;
  _data = other._data;
  _enabledItems = other._enabledItems;
  _showedItems =other._showedItems;
  return *this;
}

DNTLiveDataList::~DNTLiveDataList()
{

}

void DNTLiveDataList::addItems()
{
  if (!_native)
    return;
  auto size = _native->size();
  for (int i = 0; i < size; ++i)
    _data.append(DNTLiveDataItem(_native->get(i)));
}

void DNTLiveDataList::fillEnabledItems()
{
  _enabledItems.clear();
  if (!_native) return;
  auto size = _native->getEnabledCount();
  for (int i = 0; i < size; ++i) {
    auto index = _native->getEnabledIndex(i);
    _enabledItems.append(_data[index]);
  }
}

void DNTLiveDataList::fillShowedItems()
{
  _showedItems.clear();
  if (!_native) return;
  auto size = _native->getShowedCount();
  for (int i = 0; i < size; ++i) {
    auto index = _native->getShowedIndex(i);
    _showedItems.append(_data[index]);
  }
}

int DNTLiveDataList::nextShowedIndex()
{
  if (_native)
    return _native->getNextShowedIndex();
  return 0;
}

int DNTLiveDataList::nextShowedIndex() const
{
  if (_native)
    return _native->getNextShowedIndex();
  return 0;
}

int DNTLiveDataList::getShowedPosition(int index)
{
  if (_native)
    return _native->getShowedPosition(index);
  return 0;
}

int DNTLiveDataList::getShowedPosition(int index) const
{
  if (_native)
    return _native->getShowedPosition(index);
  return 0;
}

void DNTLiveDataList::collate()
{
  if (!_native) return;

  _native->collateEnable();
  fillEnabledItems();

  _native->collateShowed();
  fillShowedItems();
}

bool DNTLiveDataList::isEmpty()
{
  if (_native)
    return _native->empty();
  return true;
}

bool DNTLiveDataList::isEmpty() const
{
  if (_native)
    return _native->empty();
  return true;
}

DNTLiveDataItem& DNTLiveDataList::operator [](int index)
{
  assert(_native);
  return _data[index];
}

const DNTLiveDataItem& DNTLiveDataList::operator [](int index) const
{
  assert(_native);
  return _data[index];
}

DNTLiveDataList::Elements DNTLiveDataList::getEnabledItems()
{
  return _enabledItems;
}

DNTLiveDataList::Elements DNTLiveDataList::getShowedItems()
{
  return _showedItems;
}

