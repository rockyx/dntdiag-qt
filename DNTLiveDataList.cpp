#include "DNTLiveDataList.h"
#include <dnt/RLiveDataList.h>

RLiveDataList::RLiveDataList(const dnt::RLiveDataListPtr &native)
  : _native(native)
{
  saveItems();
  fillEnabledItems();
  fillShowedItems();
}

void RLiveDataList::saveItems()
{
  if (!_native)
    return;
  _data.clear();
  auto size = _native->size();
  for (int i = 0; i < size; ++i)
    _data.append(RLiveDataItem(_native->get(i)));
}

void RLiveDataList::fillEnabledItems()
{
  _enabledItems.clear();
  if (!_native) return;
  auto size = _native->getEnabledCount();
  for (int i = 0; i < size; ++i) {
    auto index = _native->getEnabledIndex(i);
    if (index == -1) break;
    _enabledItems.append(_data[index]);
  }
}

void RLiveDataList::fillShowedItems()
{
  _showedItems.clear();
  if (!_native) return;
  auto size = _native->getShowedCount();
  for (int i = 0; i < size; ++i) {
    auto index = _native->getShowedIndex(i);
    _showedItems.append(_data[index]);
  }
}

int RLiveDataList::nextShowedIndex()
{
  if (_native)
    return _native->getNextShowedIndex();
  return 0;
}

int RLiveDataList::getShowedPosition(int index)
{
  if (_native)
    return _native->getShowedPosition(index);
  return 0;
}

void RLiveDataList::collate()
{
  if (!_native) return;

  _native->collateEnable();
  fillEnabledItems();

  _native->collateShowed();
  fillShowedItems();
}

bool RLiveDataList::isEmpty()
{
  if (_native)
    return _native->empty();
  return true;
}

RLiveDataItem& RLiveDataList::operator [](int index)
{
  assert(_native);
  return _data[index];
}

const RLiveDataItem& RLiveDataList::operator [](int index) const
{
  assert(_native);
  return _data[index];
}

const RLiveDataList::Elements& RLiveDataList::getEnabledItems() const
{
  return _enabledItems;
}

const RLiveDataList::Elements& RLiveDataList::getShowedItems() const
{
  return _showedItems;
}
