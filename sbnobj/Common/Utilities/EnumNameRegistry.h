/**
 * @file   sbnobj/Common/Utilities/EnumNameRegistry.h
 * @brief  Tools to assign and retrieve names to enumerator values.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   November 19, 2026
 * 
 * 
 * Enumerator value naming system
 * ===============================
 * 
 * Usage
 * ------
 * 
 * Assuming that the system is properly set up for a scoped enumerator,
 * for example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
 * sbn::bits {
 *   enum class triggerSource { BNB, BNBoffbeam };
 * }
 * 
 * constexpr auto stream = sbn::bits::triggerSource::BNB;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * or its real-world equivalent `sbn::bits::triggerSource`, then that enumerator
 * has a "registry" of names associated with it, of type
 * `util::EnumNameRegistry` and available via `nameRegistry(stream)` or
 * explicitly `sbn::bits::nameRegistry<sbn::bits::triggerSource>({})`.
 * Users can call its interface to get its functionality.
 * In alternative, shortcuts are defined in the namespace `util` (it's an
 * inflated name and sometimes the scope already knows of another, so it may be
 * necessary to refer to it as `::util`) that are usually shorter to write.
 * For a more complete list of functions, see the
 * @ref EnumNameRegistry_FreeFunctions "free function group".
 * 
 * Here are the most prominent functionalities.
 *  - Whether an enumerator value has a registered name can be discovered with
 *    `util::EnumNameRegistry::isValue(stream)` (equivalent to
 *    `util::EnumNameRegistry::isValue()`). The usual assumption is they do.
 *  - The name of a value (a string) can be found with `util::name(stream)`
 *    (and `util::EnumNameRegistry::name()`). Often, a "local" function is also
 *    available, so that `name(stream)` is sufficient.
 *  - If it is not certain that a value has a registered name,
 *    `util::EnumNameRegistry::optName()` returns an `std::optional` object that
 *    is valid only if there is a name. There is no equivalent free function for
 *    this functionality.
 *  - Whether `"name"` is a valid name can be found with
 *    `util::isEnumName<sbn::bits::triggerSource>(name)` (equivalent to
 *    `util::EnumNameRegistry::isName()`).
 *  - The actual value of the enumerator with that `"name"` is returned by
 *    `util::fromEnumName<sbn::bits::triggerSource>(name)` (equivalent to
 *    `util::EnumNameRegistry::value()`). Attempts to fetch names that are not
 *    registered yield to undefined behaviour (typically invalid memory access).
 *  - If the name is not guaranteed to be valid, function
 *    `util::parseEnumName<sbn::bits::triggerSource>(name)` (equivalent to
 *    `util::EnumNameRegistry::optValue()`) returns a `std::optional` object
 *    that is valid only if that name is registered.
 * 
 * Lookup functions by name are case sensitive, but for most of them a
 * case-insensitive variant is also available with `AnyCase` suffix.
 * 
 * 
 * Set up
 * -------
 * 
 * The tools in here provide a small framework to assign names to enumerator
 * values, absent introspection in C++ (until... C++26).
 * 
 * From the user point of view, it should be as simple as:
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
 * sbn::bits::triggerSource stream = sbn::bits::triggerSource::BNB;
 * 
 * std::cout << "Stream: " << name(source) << std::endl;
 * 
 * sbn::bits::triggerSource offStream
 *   = ::util::bitFromName<sbn::bits::triggerSource>("BNBoffbeam");
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 * The point is that it's possible to go from the enumerator to its name,
 * and even the opposite.
 * The bit types are scoped enumerators (`enum class`), so it's easy to identify
 * them in the code; conversely, a name (as a string) can't, so `bitFromName()`
 * needs more decoration.
 * 
 * For this to actually work, the implementer of the enumerator needs to provide
 * quite some (boilerplated) information. Here it is for a reduced version of
 * `triggerSource`:
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
 * sbn::bits {
 *   
 *   enum class triggerSource { BNB, BNBoffbeam };
 *   
 *   inline constexpr auto TriggerSourceNames = ::util::makeNameRegistry<triggerSource>({
 *     { triggerSource::BNB,        "BNB"        },
 *     { triggerSource::BNBoffbeam, "BNBoffbeam" },
 *     });
 *   
 *   inline constexpr auto const& nameRegistry(triggerSource)
 *     { return TriggerSourceNames; }
 * 
 *   inline constexpr auto name(triggerSource e) { return ::util::name(e); }
 * }
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 * The `TriggerSourceNames` is an object containing all the information; it can
 * be wherever, and with whatever name.
 * `nameRegistry()` is a free function whose purpose is to associate that
 * information to `triggerSource` and fetch it. It *must* have that name and
 * *must* be in the same namespace as `triggerSource`.
 * If there are more than one enumerator in the same namespace, a templated
 * call for the shared utilities can save some future typing:
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
 * inline constexpr auto name(::util::ScopedEnum auto e)
 *   { return ::util::name(e); }
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * will serve all the scoped enumerators in the namespace, provided that they
 * have an appropriate `nameRegistry()` function.
 * 
 * 
 * Implementation description
 * ---------------------------
 * 
 * The idea is that there is
 *  1. for each enumerator, a registry that contains all the information and
 *     offers a standardised interface (here, an object of a not specific class)
 *  2. a set of centralised utilities that, given the enumerator type, can
 *     fetch the registry and perform their task (e.g. return the name of an
 *     enumerator value)
 *  3. rules that the authors need to follow to have their enumerator support
 *     these utilities.
 * 
 * The class of the registry object is not prescribed, but it needs to expose
 * the same query interface as the reference class, `EnumNameRegistry`.
 * Even the return values of the interface are not strictly fixed, as long as
 * they are convertible (for example, as a return value, `std::string_view` is
 * often interchangeable with a C string, `const char*`).
 * 
 * Let's use the `sbn::bits::triggerSource` enumerator above as an example.
 * When a user invokes one of the utilities, `name(source)`, the function
 * `name()` is looked for with the usual C++ lookup: first in the caller scope,
 * where hopefully there is nothing compatible with this call; then _if_ we have
 * defined `name(triggerSource)` in the `sbn::bits`, it will be found there
 * ("argument-dependent lookup"). That means the developers have to place a
 * `name()` for each enumerator or, as in the example above, a catch-all
 * template, which catches only the enumerators within its namespace though.
 * In principle a `name()` function could bypass the registry and, knowing about
 * `TriggerSourceNames`, use that one directly.
 * We can't use the same trick with the registry itself, so _that_ burden is
 * unmitigated.
 * 
 * The registry class itself has added complication because of a half-successful
 * attempt to let it be `constexpr`. That rules out any dynamic storage, that
 * leaves only fixed, known data size, which is a challenge considering that
 * each enumerator has its own size (which C++ does not tell me yet) and that
 * information can be inferred only at the time of initialization.
 * Because I can only use functions to deduce the size of an array (template
 * deduction is not able to), I need an intermediate function
 * (`makeNameRegistry()`) to instantiate the class template with the appropriate
 * number of name slots, that is the number of names that the caller lists.
 * 
 * Once `nameRegistry()` is available, we can write any function based on it,
 * and the namespace `::util` has its good share of them.
 * But again, if we want functions to be transparently discovered, they need
 * to be in the same namespace as the enumerator, and have one as an _argument_.
 * 
 * Note that it is not enough to parametrize `nameRegistry()` with its templated
 * enumerator type: `nameRegistry<sbn::bits::triggerSource>()` will not be found
 * om `sbn::bits` because the argument-based lookup does not apply to template
 * parameters; it needs to be `nameRegistry(sbn::bits::triggerSource::BNB)` or
 * equivalent (there is `::util::nameRegistry()` that does the lifting for us
 * if we really want `::util::nameRegistry<sbn::bits::triggerSource>()`).
 */

#ifndef SBNOBJ_COMMON_UTILITIES_ENUMNAMEREGISTRY_H
#define SBNOBJ_COMMON_UTILITIES_ENUMNAMEREGISTRY_H

// SBN libraries
#include "sbnobj/Common/Utilities/TypeTraits.h" // util::ScopedEnum

// C/C++ standard libraries
#include <algorithm> // std::copy(), std::move()
#include <array>
#include <cctype> // std::tolower()
#include <optional>
#include <string>
#include <string_view>
#include <utility> // std::pair

// -----------------------------------------------------------------------------
/* I need to move these definitions away from a namespace where `::util::name()`
 * is visible (so, `util::details` won't do), otherwise `name(e)` matches
 * both `name()` in `util` and the one that may (and should) have been defined
 * in `E`'s namespace. And since I can't forward-declare a concept, I need to
 * mix this definition and the declarations.
 */
namespace details::util {
  template <typename E>
  concept NamedEnumImpl
    = ::util::is_scoped_enum_v<E> && requires(E e){ name(e); };
  template <typename E>
  concept RegisteredEnumImpl
    = ::util::is_scoped_enum_v<E> && requires(E e){ nameRegistry(e); };
}

namespace util {
  
  /**
   * @brief A scoped enumerator (`enum class`) that can be associated to a name.
   * @tparam E the type under constraints
   * 
   * A named enumerator is a strong type (`enum class`) that can be translated
   * into a name via a `name(E)` call.
   * Argument-dependent lookup is expected to be used to identify the correct
   * `name()` function, which should be defined in the same namespace as `E`.
   * 
   * While it is expected that `name()` return value be some type of string,
   * this is not enforced by the concept.
   * 
   */
  template <typename E>
  concept NamedEnum = ::details::util::NamedEnumImpl<E>;
  
  // ---------------------------------------------------------------------------
  /**
   * @brief A scoped enumerator (`enum class`) associated to a name registry.
   * @tparam Enum the type under constraints
   * @see `NamedEnum`
   * 
   * The object of type `Enum` is guaranteed to respond to a `nameRegistry()`
   * call, to return the registry of the names of its values.
   * Argument-dependent lookup is expected to be used to identify the correct
   * `name()` function, which should be defined in the same namespace as `E`.
   * 
   * That registry is the foundation of the services provided in this library.
   * 
   * @note While enumerators modelling `RegisteredEnum` will likely model also
   *       `NamedEnum`, a `name()` function needs to be still defined in the
   *       appropriate place for that to happen, and conversely an enumerator
   *       can model `NamedEnum` by means of a crafted `name()` function without
   *       having a name registry following the conventions of this library
   *       (`NamedEnum` is defined in this library, anyway).
   * 
   */
  template <typename Enum>
  concept RegisteredEnum = ::details::util::RegisteredEnumImpl<Enum>;
  
  // ---------------------------------------------------------------------------
  
} // namespace util


namespace util {

  /// Common definitions for `EnumNameRegistry` templates of any size.
  template <ScopedEnum E, typename NameType = const char*>
  struct EnumNameRegistryDefs {
    using Enum_t = E; ///< Type of the enumerator being wrapped.
    using Name_t = NameType; ///< Type of stored name of the enumerator values.
    using Pair_t = std::pair<Enum_t, Name_t>; ///< A pair value/name.

    /// Empty name, used as return value in case of error.
    static constexpr Name_t EmptyName{};
    
    /// Returns a case-sanitized version of name.
    static std::string toAnyCase(Name_t const& name);
    
  }; // EnumNameRegistryDefs


  /**
   * @brief Storage of enumerator names, and some lookup functionality embedded.
   * @tparam Enum (scoped) enumerator to define the names of
   * @tparam N number of entries in the name table
   * @tparam NameType type used for enumerator value names
   * 
   * This object establishes and maintains a bidirectional relation between
   * an enumerator and its name.
   * 
   * The class provides lookup by enumerator value and by enumerator name, the
   * latter both case-sensitive and case-unsensitive (`NameAnyCase` methods).
   * For lookup by name, the result may be given as `std::optional` (empty if
   * no enumerator value matches the name) or reference (undefined behaviour if
   * no value), and the presence can be simply checked (`isName()`).
   * In general all enumerator values are expected to have been given a name,
   * so the interface is less forgiving and flexible; if an enumerator does not
   * have a name, a reference to `EmptyName` will be returned, and that's it.
   * 
   * This class is the backbone of the user free functions:
   *  * `util::name()` shortcut for `name()` here
   *  * `util::isEnumName<>()` shortcut for `isName()` here (case-sensitive)
   *  * `util::fromEnumName<>()` shortcut for `value()` here (case-sensitive)
   *  * `util::parseEnumName<>()` shortcut for `optValue()` here (case-sensitive)
   *  * `util::nameRegistry()` will return an instance of a this class
   * 
   * ### Construction
   * 
   * An object of this type is constructed by specifying all the enumerator
   * value names. Note that there is no forcing all of the values to have a name
   * (although it is recommended, since there is not much interface to check
   * if a valid enumerator value is not included), and there is no forcing for
   * having only one name per value: that is, aliases are possible, the first
   * name of a value is the one reported by `name()` but `value()` will match
   * the others too.
   * 
   * A simple example:
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
   * namespace food {
   *   
   *   enum class Fruit { Apple, Banana, Cherry };
   *   
   *   inline constexpr auto FruitNames = util::makeNameRegistry<Fruit>({
   *     { Fruit::Apple, "apple" },
   *     { Fruit::Banana, "banana" },
   *     { Fruit::Cherry, "cherry" },
   *   });
   *   
   * }
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   * (note that additional functions may and should be defined in this
   * namespace: see the documentation of `EnumNameRegistry.h`)
   * 
   * 
   * @note It is possible that most of this machinery could work also with
   *       common, unscoped enumerators (`enum`). That was not tested.
   *       It is also possible that it works with other string types rather
   *       than `const char*` (maybe `std::string_view`). Definitely not tested!
   *       And there may be some `constexpr` constraints preventing that from
   *       working.
   */
  template <ScopedEnum Enum, std::size_t N, typename NameType = const char*>
  class EnumNameRegistry: public EnumNameRegistryDefs<Enum, NameType> {
    
    using Base_t = EnumNameRegistryDefs<Enum, NameType>; ///< Base type.
    
      public:

    // import definitions
    using Enum_t = typename Base_t::Enum_t;
    using Name_t = typename Base_t::Name_t;
    using Pair_t = typename Base_t::Pair_t;
    
    /// Constructor: copies enumerator (value, name) pairs in the given order.
    // @{
    constexpr EnumNameRegistry(Pair_t const (&names)[N]);
    constexpr EnumNameRegistry(Pair_t (&&names)[N]);
    // @}
    
    
    // --- BEGIN ---  Container interface  -------------------------------------
    /// @name Registry as container.
    /// @{
    /// Returns the number of registered names
    /// (may be different from the number of enumerator values).
    static constexpr std::size_t size() { return N; }
    
    /// Returns a (constant) iterator to the first value/name pair.
    constexpr auto begin() const { return fNames.begin(); }
    
    /// Returns a (constant) iterator past the end of value/name pairs.
    constexpr auto end() const { return fNames.end(); }
    
    // ---  END  ---  Container interface  -------------------------------------
    
    
    // --- BEGIN ---  Lookup by value  -----------------------------------------
    /// @name Lookup from value
    /// @{
    /**
     * @brief Returns whether an enumerator value has a registered name.
     * @see `isName(), `value()`, `optValue()`
     * 
     * The `name` needs to be exactly equal to the enumerator value's
     * (no additional blanks, same case).
     */
    constexpr bool isValue(Enum_t value) const;
    
    /// Returns the name of the enumerator `value`.
    /// Undefined behaviour if there is no name for `value`.
    constexpr Name_t const& name(Enum_t value) const;

    /// Returns the name of the enumerator `value`, if available.
    constexpr std::optional<Name_t> optName(Enum_t value) const;

    /// Alias of `name()`.
    constexpr Name_t const& operator [](Enum_t value) const
      { return name(value); }
    
    /// @}
    // ---  END  ---  Lookup by value  -----------------------------------------
    
    // --- BEGIN ---  Lookup by name  ------------------------------------------
    /// @name Lookup from name
    /// @{
    /**
     * @brief Returns whether an enumerator value with that `name` is present.
     * @see `isValue()`, `value()`
     * 
     * The `name` needs to be exactly equal to the enumerator value's
     * (no additional blanks, same case).
     */
    constexpr bool isName(Name_t const& name) const;
    
    /**
     * @brief Returns the enumerator `value` matching the specified `name`.
     * @see `isName()`, `valueAnyCase()`
     * 
     * The `name` needs to be exactly the enumerator value's
     * (no additional blanks, same case).
     * Undefined behaviour if there is no enumerator value named `name`.
     * Use `isName()` or `optValue()` if unsure!
     */
    constexpr Enum_t value(Name_t const& name) const;
    
    /// Returns the enumerator value matching the specified `name` if available.
    /// @see `isValue()`, `optValueAnyCase()`
    constexpr std::optional<Enum_t> optValue(Name_t const& name) const;

    /**
     * @brief Returns whether an enumerator value with this `name` is present.
     * @see `isName()`, `valueAnyCase()`
     * 
     * The `name` needs to be the enumerator value's, no additional blanks,
     * but matching is performed in lower case (i.e. case insensitive).
     */
    constexpr bool isNameAnyCase(Name_t const& name) const;
    
    /**
     * @brief Returns the enumerator value `e` matching the specified `name`.
     * @see `isNameAnyCase()`, `optValueAnyCase()`, `value()`
     * 
     * The `name` needs to be the enumerator value's, no additional blanks,
     * but matching is performed in lower case (i.e. case insensitive).
     * In case of multiple matches, exact match is preferred, otherwise the
     * choice is deterministic but not prescribed.
     * Undefined behaviour if there is no enumerator value named `name`.
     * Use `isNameAnyCase()` or `optValueAnyCase()` if unsure!
     */
    constexpr Enum_t valueAnyCase(Name_t const& name) const;
    
    /**
     * @brief Returns the enumerator value `e` matching the specified `name`.
     * @see `optValue()`
     * 
     * The `name` needs to be the enumerator value's, no additional blanks,
     * but matching is performed in lower case (i.e. case insensitive).
     * If there is no enumerator value named `name`, an empty optional is
     * returned.
     */
    constexpr std::optional<Enum_t> optValueAnyCase(Name_t const& name) const;
    
    /// Alias of `value()` (case-sensitive).
    constexpr Enum_t operator[](Name_t const& name) const
      { return value(name); }
    
    /// @}
    // ---  END  ---  Lookup by name  ------------------------------------------
    
    
      private:
    
    std::array<Pair_t, N> fNames; ///< Names of all supported enumerator values.

    /// Returns the matching value, or `nullptr` if not found.
    constexpr Pair_t const* findByValue(Enum_t value) const;

    /// Returns the matching name, or `nullptr` if not found.
    constexpr Pair_t const* findByName(Name_t const& name) const;

    /// Returns the matching case-insensitive name, or `nullptr` if not found.
    constexpr Pair_t const* findByNameAnyCase(Name_t const& name) const;

    /// Returns the name of the pair, with the convention of `name()`.
    constexpr Name_t const& returnName(Pair_t const* pair) const;

    /// Returns the name of the pair, with the convention of `optName()`.
    constexpr std::optional<Name_t> returnOptName(Pair_t const* pair) const;

    /// Returns the value of the pair, with the convention of `value()`.
    constexpr Enum_t returnValue(Pair_t const* pair) const;

    /// Returns the value of the pair, with the convention of `optValue()`.
    constexpr std::optional<Enum_t> returnOptValue(Pair_t const* pair) const;

  }; // EnumNameRegistry


  // --- BEGIN ---  Free function interface  -----------------------------------
  /**
   * @name Free enumerator name functions
   * @anchor EnumNameRegistry_FreeFunctions
   * 
   * These functions all rely on `nameRegistry(Enum)` being available for
   * the enumerator type they need (that is, it must model `RegisteredEnum`);
   * that function should be shipped with the enumerator.
   * A minimal initialization could be:
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
   * namespace food {
   *   
   *   enum class Fruit { Apple, Banana, Cherry };
   *   
   *   inline constexpr auto FruitNames = util::makeNameRegistry<Fruit>({
   *     { Fruit::Apple,  "apple"  },
   *     { Fruit::Banana, "banana" },
   *     { Fruit::Cherry, "cherry" },
   *   });
   *   
   *   constexpr auto const& nameRegistry(Fruit) { return FruitNames; }
   *   
   * }
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   * 
   * They can be called "from anywhere", but most of them require to specify the
   * enumerator type they are working on.
   * For example:
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
   * constexpr auto banana = util::fromEnumNameAnyCase<food::Fruit>("Banana");
   * std::cout << "Here is a " << util::name(banana) << "." << std::endl;
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   * which should print `Here is a banana.`, lower case because that's how the
   * name was registered.
   * 
   * If `food::name(Fruit)` function were defined (same place where
   * `nameRegistry()` should), `name(banana)` would work just as well.
   * That definition may be:
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
   * namespace food {
   *   constexpr decltype(auto) name(Fruit fruit) { return util::name(fruit); }
   * }
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   * (`decltype(auto)` is safer in case the return type of `util::name()`
   * changes, but a plain `std::string_view` should be just as fine).
   */
  /// @{
  
  /**
   * @brief Constructs a new `EnumNameRegistry` with the specified names.
   * @tparam Enum the (scoped) enumerator type being dressed
   * @tparam NameType (default: `const char*`) the type to store the names
   * @tparam N the number of entries (autodetected)
   * @param names pairs of the enumerator (value, name) to be registered
   * @return an appropriate `EnumNameRegistry` object, appropriately filled
   * @see `EnumNameRegistry`, `EnumNameRegistry.h`
   * 
   * A new instance of `EnumNameRegistry` is returned, storing each of the names
   * specified in the argument. For more details, see the documentation of
   * that class and its constructors, and the outline in the header
   * documentation.
   * 
   * The example:
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{.cpp}
   * namespace food {
   *   
   *   enum class Fruit { Apple, Banana, Cherry };
   *   
   *   inline constexpr auto FruitNames = util::makeNameRegistry<Fruit>({
   *     { Fruit::Apple,  "apple"  },
   *     { Fruit::Banana, "banana" },
   *     { Fruit::Cherry, "cherry" },
   *   });
   *   
   * }
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   * 
   * Note that while the `NameType` parameter is the type the names will be
   * stored with in the returned object, the type of the names in the argument
   * is a no-nonsense C-string type (`const char*`).
   * 
   * This function exists to auto-detect the number of entries from its
   * argument.
   * 
   */
  template <ScopedEnum Enum, typename NameType = const char*, std::size_t N>
  constexpr EnumNameRegistry<Enum, N, NameType> makeNameRegistry
    (std::pair<Enum, const char*> const (&names)[N]);

  /// Returns the name of the specified enumerator value.
  constexpr bool isValue(RegisteredEnum auto value);
  
  /// Returns the name of the specified enumerator value.
  constexpr std::string_view name(RegisteredEnum auto value);
  
  /// Returns whether the enumerator `Enum` has a value registered with `name`.
  template <RegisteredEnum Enum>
  constexpr bool isEnumName(std::string_view name);

  /// Returns whether the enumerator `Enum` has a value registered with `name`
  /// (case insensitive).
  template <RegisteredEnum Enum>
  constexpr bool isEnumNameAnyCase(std::string_view name);

  /// Returns the enumerator with the specified `name`.
  /// Same protocol as `EnumNameRegistry::value()`.
  template <RegisteredEnum Enum>
  constexpr Enum fromEnumName(std::string_view name);
  
  /// Returns the enumerator with the specified `name`.
  /// Same protocol as `EnumNameRegistry::valueAnyCase()`.
  template <RegisteredEnum Enum>
  constexpr Enum fromEnumNameAnyCase(std::string_view name);
  
  /// Returns the enumerator with the specified `name`.
  /// Same protocol as `EnumNameRegistry::optValue()`.
  template <RegisteredEnum Enum>
  constexpr std::optional<Enum> parseEnumName(std::string_view name);
  
  /// Returns the enumerator with the specified `name`.
  /// Same protocol as `EnumNameRegistry::optValueAnyCase()`.
  template <RegisteredEnum Enum>
  constexpr std::optional<Enum> parseEnumNameAnyCase(std::string_view name);
  
  /**
   * @brief Returns an iterable with all registered names.
   * 
   * Depending on the registry content, there may be multiple, even duplicate,
   * or no entries for a single value, and their order is not prescribed.
   * The type of each name is not imposed, but it can be reasonably expected
   * to be the same as the one in the name registry.
   */
  template <RegisteredEnum Enum>
  auto allEnumNames();
  
  
  /// @}
  // ---  END  ---  Free function interface  -----------------------------------
}

// -----------------------------------------------------------------------------
// ---  Template implementation
// -----------------------------------------------------------------------------
// --- util::EnumNameRegistry
// ---
template <util::ScopedEnum Enum, typename NameType>
constexpr NameType util::EnumNameRegistryDefs<Enum, NameType>::EmptyName;

template <util::ScopedEnum Enum, typename NameType>
std::string util::EnumNameRegistryDefs<Enum, NameType>::toAnyCase
  (Name_t const& NaMe)
{
  std::string_view src{ NaMe };
  std::string name;
  name.reserve(src.size());
  for (auto itDest = back_inserter(name); auto const c: src)
    *(itDest++) = std::tolower(c);
  return name;
}

// -----------------------------------------------------------------------------
// --- util::EnumNameRegistry
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr util::EnumNameRegistry<Enum, N, NameType>::EnumNameRegistry
  (Pair_t const (&names)[N])
{
  std::copy(names, names+N, fNames.begin());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr util::EnumNameRegistry<Enum, N, NameType>::EnumNameRegistry
  (Pair_t (&&names)[N])
{
  std::move(names, names+N, fNames.begin());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr bool util::EnumNameRegistry<Enum, N, NameType>::isValue
  (Enum_t value) const
{
  return findByValue(value);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::name
  (Enum_t value) const -> Name_t const&
{
  return returnName(findByValue(value));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::optName
  (Enum_t value) const -> std::optional<Name_t>
{
  return returnOptName(findByValue(value));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr bool util::EnumNameRegistry<Enum, N, NameType>::isName
  (Name_t const& name) const
{
  return findByName(name);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::value
  (Name_t const& name) const -> Enum_t
{
  return returnValue(findByName(name));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::optValue
  (Name_t const& name) const -> std::optional<Enum_t>
{
  return returnOptValue(findByName(name));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr bool util::EnumNameRegistry<Enum, N, NameType>::isNameAnyCase
  (Name_t const& name) const
{
  return findByNameAnyCase(name);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::valueAnyCase
  (Name_t const& name) const -> Enum_t
{
  return returnValue(findByNameAnyCase(name));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::optValueAnyCase
  (Name_t const& name) const -> std::optional<Enum_t>
{
  return returnOptValue(findByNameAnyCase(name));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::findByValue
  (Enum_t value) const -> Pair_t const*
{
  for (auto const& p: fNames) if (p.first == value) return &p;
  return nullptr;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::findByName
  (Name_t const& name) const -> Pair_t const*
{
  std::string_view const cname{ name }; // name for comparison
  for (auto const& p: fNames) if (p.second == cname) return &p;
  return nullptr;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::findByNameAnyCase
  (Name_t const& name) const -> Pair_t const*
{
  if (auto const ptr = findByName(name)) return ptr; // check unchanged first
  auto const cname = Base_t::toAnyCase(name); // name for comparison
  for (auto const& p: fNames)
    if (Base_t::toAnyCase(p.second) == cname) return &p;
  return nullptr;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::returnName
  (Pair_t const* pair) const -> Name_t const&
{
  return pair? pair->second: Base_t::EmptyName;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::returnOptName
  (Pair_t const* pair) const -> std::optional<Name_t>
{
  return pair? std::optional(pair->second): std::nullopt;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::returnValue
  (Pair_t const* pair) const -> Enum_t
{
  return pair->first;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::ScopedEnum Enum, std::size_t N, typename NameType>
constexpr auto util::EnumNameRegistry<Enum, N, NameType>::returnOptValue
  (Pair_t const* pair) const -> std::optional<Enum_t>
{
  return pair? std::optional(pair->first): std::nullopt;
}


// -----------------------------------------------------------------------------
// ---  free functions
// ---
template <util::ScopedEnum Enum, typename NameType, std::size_t N>
constexpr util::EnumNameRegistry<Enum, N, NameType> util::makeNameRegistry
  (std::pair<Enum, const char*> const (&names)[N])
{
  return EnumNameRegistry<Enum, N, NameType>{ names };
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
constexpr bool util::isValue(RegisteredEnum auto value) {
  return nameRegistry(value).isValue(value);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
constexpr std::string_view util::name(RegisteredEnum auto value) {
  return nameRegistry(value).name(value);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::RegisteredEnum Enum>
constexpr bool util::isEnumName(std::string_view name) {
  return nameRegistry(Enum{}).isName(name.data());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::RegisteredEnum Enum>
constexpr bool util::isEnumNameAnyCase(std::string_view name) {
  return nameRegistry(Enum{}).isNameAnyCase(name.data());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::RegisteredEnum Enum>
constexpr Enum util::fromEnumName(std::string_view name) {
  return nameRegistry(Enum{}).value(name.data());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::RegisteredEnum Enum>
constexpr Enum util::fromEnumNameAnyCase(std::string_view name) {
  return nameRegistry(Enum{}).valueAnyCase(name.data());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::RegisteredEnum Enum>
constexpr std::optional<Enum> util::parseEnumName(std::string_view name) {
  return nameRegistry(Enum{}).optValue(name.data());
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template <util::RegisteredEnum Enum>
constexpr std::optional<Enum> util::parseEnumNameAnyCase(std::string_view name)
{
  return nameRegistry(Enum{}).optValueAnyCase(name.data());
}

// -----------------------------------------------------------------------------
template <util::RegisteredEnum Enum>
auto util::allEnumNames() {
  auto const& registry = nameRegistry(Enum{});
  using Registry_t = std::decay_t<decltype(registry)>;
  std::array<typename Registry_t::Name_t, Registry_t::size()> names;
  auto itName = begin(names);
  for (auto const& pair: registry) *(itName++) = pair.second;
  return names;
} // util::allEnumNames()


// -----------------------------------------------------------------------------

#endif // SBNOBJ_COMMON_UTILITIES_ENUMNAMEREGISTRY_H
