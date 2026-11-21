/**
 * @file   sbnobj/Common/Utilities/TypeTraits.h
 * @brief  Traits and concepts for SBN data types.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   November 19, 2026
 * 
 * This is a header-only library.
 * 
 */

#ifndef SBNOBJ_COMMON_UTILITIES_TYPETRAITS_H
#define SBNOBJ_COMMON_UTILITIES_TYPETRAITS_H


// C/C++ standard libraries
#include <type_traits>

namespace util {
  
  // ---------------------------------------------------------------------------
#if defined __cpp_lib_is_scoped_enum // C++23
# error "Update code to use std::is_scoped_enum instead of sbn::bits::is_scoped_enum"
#else
  /// Type trait: `E` is a scoped enumerator (`enum class`).
  template<typename E>
  using is_scoped_enum
    = std::bool_constant<std::is_enum_v<E> && !std::is_convertible_v<E, int>>;
    
  /// Whether type `E` is a scoped enumerator (`enum class`).
  template<typename E>
  inline constexpr bool is_scoped_enum_v = is_scoped_enum<E>::value;
#endif
  
  // ---------------------------------------------------------------------------
  
  /// A scoped enumerator (`enum class`).
  /// When you leave and then come back, it's still there.
  template <typename E>
  concept ScopedEnum = util::is_scoped_enum_v<E>;
  
  // ---------------------------------------------------------------------------
  
} // namespace util


#endif // SBNOBJ_COMMON_UTILITIES_TYPETRAITS_H
