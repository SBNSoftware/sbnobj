/**
 * @file   sbnobj/Common/Metadata/OrderedPairList.cxx
 * @brief  Object holding a list of pairs.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   January 16, 2025
 * @see    sbnobj/Common/Metadata/OrderedPairList.h
 */

// library header
#include "sbnobj/Common/Metadata/OrderedPairList.h"

// C/C++ standard libraries
#include <algorithm> // std::binary_search(), std::lower_bound()
#include <ostream>
#include <sstream>
#include <utility> // std::less
#include <type_traits> // std::true_type


// -----------------------------------------------------------------------------
// ---  sbn::OrderedPairList  ------------------------------------------
// -----------------------------------------------------------------------------
bool sbn::OrderedPairList::contains(Key_t const& key) const noexcept {
  
  return std::binary_search(items.begin(), items.end(), key, ItemSorter{});
  
}


// -----------------------------------------------------------------------------
auto sbn::OrderedPairList::getPtr(Key_t const& key) const -> Value_t const* {
  
  auto const it = findInsertionPoint(key);
  return ((it == items.end()) || (std::get<0>(*it) != key))
    ? nullptr: &(std::get<1>(*it));
  
}


// -----------------------------------------------------------------------------
auto sbn::OrderedPairList::get(Key_t const& key) const -> std::optional<Value_t>
{
  
  Value_t const* ptr = getPtr(key);
  return ptr? std::make_optional(*ptr): std::nullopt;
  
}


// -----------------------------------------------------------------------------
sbn::OrderedPairList& sbn::OrderedPairList::finish() {
  
  std::sort(items.begin(), items.end());
  
  // remove duplicates
  auto const itFirstDuplicate = std::unique(items.begin(), items.end());
  items.erase(itFirstDuplicate, items.end());
  
  return *this;
  
} // sbn::OrderedPairList::finish()


// -----------------------------------------------------------------------------
bool sbn::OrderedPairList::insert(Key_t key, Value_t value) {
  
  auto const it = findInsertionPoint(key);
  if ((it == items.end()) || (std::get<0>(*it) != key)) { // new key
    items.emplace(it, std::move(key), std::move(value));
    return true;
  }
  else {
    // using an index since the iterator is constant
    items[std::distance(items.cbegin(), it)].second = std::move(value);
    return false;
  }
  
} // sbn::OrderedPairList::insert()


// -----------------------------------------------------------------------------
void sbn::OrderedPairList::dump(std::ostream& out) const {
  
  for (auto const& [ key, value ]: items)
    out << key << " = " << value << "\n";
  
} // sbn::OrderedPairList::dump()


// -----------------------------------------------------------------------------
auto sbn::OrderedPairList::findInsertionPoint(Key_t const& key) const
  -> const_iterator
{
  return std::lower_bound(items.begin(), items.end(), key, ItemSorter{});
}


// -----------------------------------------------------------------------------
// ---  free functions  --------------------------------------------------------
// -----------------------------------------------------------------------------
std::ostream& sbn::operator<<
  (std::ostream& out, OrderedPairList const& list)
  { list.dump(out); return out; }


// -----------------------------------------------------------------------------
