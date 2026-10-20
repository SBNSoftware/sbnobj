/**
 * @file   sbnobj/Common/Metadata/OrderedPairList.h
 * @brief  Information from the execution environment of the job.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   January 16, 2025
 * @see    sbnobj/Common/Metadata/OrderedPairList.cxx
 */


#ifndef SBNOBJ_COMMON_METADATA_ORDEREDPAIRLIST_H
#define SBNOBJ_COMMON_METADATA_ORDEREDPAIRLIST_H

// SBN libraries
#include "sbnobj/Common/Metadata/details/PairKeyComparer.h"

// C/C++ standard libraries
#include <optional>
#include <string>
#include <tuple> // std::pair
#include <vector>
#include <iosfwd> // std::ostream


// -----------------------------------------------------------------------------
namespace sbn {
  struct OrderedPairList;
  
  /// Dumps a `sbn::OrderedPairList` object into a C++ output stream.
  std::ostream& operator<<
    (std::ostream& out, OrderedPairList const& list);
  
}

// -----------------------------------------------------------------------------
/**
 * @brief Data object with a list of key-value pairs.
 * 
 * This object is sort of a map (`std::map`), but with a simpler internal
 * structure. It has lookup as fast as a `std::map`, but insertion is slow
 * and not really supported by the interface.
 * Keys are expected to be unique, although this is not enforced (i.e. duplicate
 * keys yield undefined behaviour).
 * 
 * The reason of this class is that its simpler structure makes it easier to be
 * serialized.
 * 
 * 
 * To fill the list, the suggested way is to add the pairs with
 * `items.emplace_back()` and after insertion is over sort it with `finish()`.
 * 
 */
struct sbn::OrderedPairList {
  
  // maybe one day this will be a template.
  using Key_t = std::string; ///< Type of the key.
  using Value_t = std::string; ///< Type of the value.
  
  using Item_t = std::pair<Key_t, Value_t>; ///< Type stored in the list.
  using List_t = std::vector<Item_t>; ///< Implementation of the list./
  
  using const_iterator = List_t::const_iterator;
  using value_type = List_t::value_type;
  using size_type = List_t::size_type;
  
  
  /// Comparison functor ordering by key.
  using ItemSorter = details::PairKeyComparer;
  
  /// All the variables: name -> value, lexicographically ordered by name.
  List_t items;
  
  
  // --- BEGIN ---  Limited STL-like access  -----------------------------------
  /// @name Limited STL-like access
  /// @{
  
  const_iterator begin() const noexcept { return items.begin(); }
  
  const_iterator end() const noexcept { return items.end(); }
  
  size_type size() const noexcept { return items.size(); }
  
  bool empty() const noexcept { return items.empty(); }
  
  
  /// Returns whether there is an item with the specified `key`.
  bool contains(Key_t const& key) const noexcept;
  
  /// @}
  // --- END -----  Limited STL-like access  -----------------------------------
  
  
  // --- BEGIN ---  Access helpers  --------------------------------------------
  /// @name Access helpers
  /// @{
  
  /// Returns a pointer to the value of the requested `key`,
  /// or `nullptr` if none.
  Value_t const* getPtr(Key_t const& key) const;
  
  /// Returns the value of the requested `key`, or `std::nullopt` if none.
  std::optional<Value_t> get(Key_t const& key) const;
  
  /// Returns the value of the requested variable, or `defValue` if none.
  std::string get(Key_t const& key, Value_t const& defValue) const
    { return get(key).value_or(defValue); }
  
  /// @}
  // --- END -----  Access helpers  --------------------------------------------
  
  
  // --- BEGIN ---  Writing helpers  -------------------------------------------
  /**
   * @name Writing helpers
   * 
   * There are two main ways to write into this object:
   *  * bulk, for many entries at once:
   *      1. add the entries directly with `items.emplace_back()` or equivalent;
   *      2. sort the elements with `finish()`.
   *  * single entry: use `insert()` member function directly.
   * 
   */
  /// @{
  
  /// Makes sure the content is internally correctly organised.
  /// @return this object
  sbn::OrderedPairList& finish();
  
  /**
   * @brief Adds the specified key.
   * @param key the key to insert
   * @param value the value associated to that key
   * @return whether the key was inserted anew (`false` if already present)
   * 
   * The key is added to the `items`, in the correct place so that no `finish()`
   * is needed afterwards.
   * 
   * If the `key` is already present, its previous `value` is overwritten.
   * 
   * If many keys need to be added at once, it is more efficient to add them
   * directly to `items` (e.g. with `emplace_back()`) and then `finish()` the
   * addition once for all.
   */
  bool insert(Key_t key, Value_t value);
  
  /// @}
  // --- END -----  Writing helpers  -------------------------------------------
  
  
  /// Dumps the entire content of the list in human-readable form.
  void dump(std::ostream& out) const;
  
  /// Returns the entire content of the list in human-readable form.
  std::string to_string() const;
  
  
    private:
  
  /// Returns the iterator to use with `insert()` to insert the specified `key`.
  /// 
  /// If the key already exists, the iterator will point to it; otherwise it
  /// will point to the element that would be next to `key`.
  const_iterator findInsertionPoint(Key_t const& key) const;
  
}; // sbn::OrderedPairList


// -----------------------------------------------------------------------------

#endif // SBNOBJ_COMMON_METADATA_ORDEREDPAIRLIST_H
