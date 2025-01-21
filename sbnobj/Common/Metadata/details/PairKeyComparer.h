/**
 * @file   sbnobj/Common/Metadata/details/PairKeyComparer.h
 * @brief  Object holding a list of pairs.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   January 16, 2025
 * @see    sbnobj/Common/Metadata/OrderedPairList.h
 */

#ifndef SBNOBJ_COMMON_METADATA_DETAILS_PAIRKEYCOMPARER
#define SBNOBJ_COMMON_METADATA_DETAILS_PAIRKEYCOMPARER


// C/C++ standard libraries
#include <functional> // std::less
#include <utility> // std::get(), std::less, std::declval(), ...
#include <type_traits> // std::true_type, ...


// -----------------------------------------------------------------------------
namespace sbn::details {
  
  /// Trait: `true` if `T` responds to `std::get<0>()`.
  template <typename T, typename Enable = void>
  struct hasFirst;
  
  
  /// Compares (`std::less`) two values via the first element of each.
  struct PairKeyComparer;
  
  /*
   * --- BEGIN --- Metaprogramming fury ----------------------------------------
   *
   * The goal is to sort and match a list of pairs by their first element
   * ("key").
   * 
   * Sorting itself does not require almost any art, since pairs sort by key
   * first. Lookup by key only, in the other end, requires to deal with the
   * second pair element.
   * 
   * The idea here is to have a comparison operator that sorts pairs and keys,
   * reacting to all combinations of `{ pair, key } < { pair, key }`.
   * In this way algorithms like `std::binary_search()` can use `pair < key` to
   * search for a specific key, without having to turn it into a pair (which
   * would be problematic).
   * 
   * So the following implementation is a trait that detects if an argument has
   * a "first" element (responding to `std::get<0>()`) and a comparison object
   * that detects via that traits when the arguments have a key, strips the rest
   * and then performs the comparison.
   */
  
  template <typename T, typename Enable /* = void */>
  struct hasFirst: std::false_type {};
  
  template <typename T>
  struct hasFirst<T, std::void_t<decltype(std::get<0>(std::declval<T>()))>>
    : std::true_type {};
  
  template <typename T>
  constexpr bool hasFirst_v = hasFirst<T>::value;
  
  
  // ---------------------------------------------------------------------------
  /// Compares (`std::less`) two values via the first element of each.
  struct PairKeyComparer {
    
    /// Extracts the key of the argument.
    template <typename T>
    static auto&& keyOf(T&& v)
      {
        if constexpr(hasFirst_v<T>) return std::get<0>(std::forward<T>(v));
        else return v;
      }
    
    /// Returns whether `a`'s key is smaller than `b`'s.
    template <typename A, typename B>
    static bool cmp(A const& a, B const& b)
      { return std::less{}(keyOf(a), keyOf(b)); }
    
    /// Returns whether `a`'s key is smaller than `b`'s.
    template <typename A, typename B>
    bool operator() (A const& a, B const& b) const
      { return cmp(a, b); }
    
  }; // PairKeyComparer
  
  
  // ---------------------------------------------------------------------------
  
} // sbn::details


#endif // #define SBNOBJ_COMMON_METADATA_DETAILS_PAIRKEYCOMPARER
