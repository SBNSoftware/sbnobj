/**
 * @file   sbnobj/Common/Trigger/BeamBits.h
 * @brief  Definitions of the trigger bits for SBN.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   May 19, 2021
 * 
 * Link with `sbnobj::Common_Trigger`.
 */

#ifndef SBNOBJ_COMMON_TRIGGER_BEAMBITS_H
#define SBNOBJ_COMMON_TRIGGER_BEAMBITS_H

// SBN libraries
#include "sbnobj/Common/Utilities/EnumNameRegistry.h" // support for enumerators

// C/C++ standard libraries
#include <ostream>
#include <stdexcept> // std::runtime_error
#include <string>
#include <vector>
#include <typeinfo>
#include <type_traits> // std::underlying_type_t


// -----------------------------------------------------------------------------
/**
 * @brief Simple utilities to deal with bit enumerators.
 * 
 * A few simple concepts:
 * * a bit is identified by its position (integral number: `0`, `1`, `2`...)
 * * representation of a bit is via a enumerator (`enum class`)
 * * bits may be associated with a name (`name()`)
 * * to test bits, `mask()`, `value()` and `hasBitSet()` help with the
 *   conversions between `enum class` and the underlying integral type
 * 
 */
namespace sbn::bits {
  
  // --- BEGIN -- Generic bit functions ----------------------------------------
  /// @name Generic bit functions
  /// @{
  
  /// Type for bit masks.
  /// @note This is a glorified integral type.
  template <::util::ScopedEnum Enum>
  struct mask_t {
    using bits_t = Enum; ///< Enumeration type of the bits.
    using maskbits_t = std::underlying_type_t<Enum>; ///< Bit data type.
    maskbits_t bits { 0 };
    operator maskbits_t() const { return bits; }
  }; // mask_t

  /// Converts a integral type into a mask.
  template <::util::ScopedEnum Enum>
  mask_t<Enum> makeMask(typename mask_t<Enum>::maskbits_t bits) noexcept;
  
  
  /// Returns the value of specified `bit` (conversion like `enum` to `int`).
  template <::util::ScopedEnum Enum>
  constexpr auto value(Enum bit);
  
  /// Returns a mask with all specified bits set.
  template <::util::ScopedEnum Enum, typename... OtherBits>
  constexpr mask_t<Enum> mask(Enum bit, OtherBits... otherBits);
  
  /// Returns whether the specified `bit` is set in `bitMask`.
  template <::util::ScopedEnum Enum>
  constexpr bool hasBitSet(mask_t<Enum> bitMask, Enum bit);
  
  /// Returns the name of the specified `bit`.
  /// @throws std::runtime_error if bit is not known
  template <::util::RegisteredEnum Enum>
  std::string name(Enum bit);
  
  /// Alias for `sbn::bits::name()`.
  /// @deprecated Use `sbn::bits::name()` instead.
  [[deprecated("Use `sbn::bits::name()` instead")]]
  std::string bitName(::util::RegisteredEnum auto bit) { return name(bit); }

  /**
   * @brief Returns the bit value of a given name, if present.
   * @tparam Enum (mandatory) the type of bits to read
   * @param name the name of the bit
   * @param caseSensitive (default: `true`): whether to match the case of `name`
   * @return optional value of the matched bit, or an invalid state if not found
   */
  template <::util::RegisteredEnum Enum>
  std::optional<Enum> parse(std::string_view name, bool caseSensitive = true);

  /// Returns a list of the names of all the bits set in `mask`.
  /// Mask is interpreted as made of only bits of type `Enum`.
  template <::util::RegisteredEnum Enum>
  std::vector<std::string> names(mask_t<Enum> mask);
  
  /// Inserts the name of `bit` into `out` stream [template]
  std::ostream& operator<< (std::ostream& out, ::util::NamedEnum auto bit)
    { return out << name(bit); }
  
  /// @}
  // --- END ---- Generic bit functions ----------------------------------------
  
  
  // --- BEGIN -- Beam bits ----------------------------------------------------
  /// @name Beam bits
  /// @{
  
  /// Type of beam or beam gate or other trigger source.
  enum class triggerSource: unsigned int {
    Unknown,     ///< Type of beam unknown.
    BNB,         ///< Type of beam: BNB.
    NuMI,        ///< Type of beam: NuMI.
    OffbeamBNB,  ///< Type of Offbeam: BNB.
    OffbeamNuMI, ///< Type of Offbeam: NuMI.
    Calib,       ///< Type of source: calibration trigger.
    // ==> add here if more are needed <==
    NBits    ///< Number of bits currently supported.
  }; // triggerSource

  /// Type of mask with `triggerSource` bits.
  using triggerSourceMask = mask_t<triggerSource>;
  
  /// Location or locations generating a trigger.
  enum class triggerLocation: unsigned int {
    CryoEast,    ///< A trigger happened in the east cryostat.
    CryoWest,    ///< A trigger happened in the west cryostat.
    TPCEE,       ///< A trigger happened in the east cryostat, east TPC.
    TPCEW,       ///< A trigger happened in the east cryostat, west TPC.
    TPCWE,       ///< A trigger happened in the west cryostat, east TPC.
    TPCWW,       ///< A trigger happened in the west cryostat, west TPC.
    // ==> add here if more are needed <==
    NBits    ///< Number of bits currently supported.
  }; // triggerLocation

  /// Type of mask with `triggerLocation` bits.
  using triggerLocationMask = mask_t<triggerLocation>;

  /// Type(s) of trigger logic being satisfied.
  enum class triggerLogic: unsigned int {
    PMTAnalogSum,    ///< Discriminated PMT signal sum above threshold.
    PMTPairMajority, ///< Minimum number of discriminated PMT above threshold.
    // ==> add here if more are needed <==
    NBits    ///< Number of bits currently supported.
  }; // triggerLocation

  /// Type of mask with `triggerLogic` bits.
  using triggerLogicMask = mask_t<triggerLogic>;

  /// Type representing the type(s) of this trigger.
  enum class triggerType: unsigned int {
    Majority,    ///< A minimum number of close-by PMT pairs above threshold was reached.
    MinimumBias, ///< Data collected at gate opening with no further requirement imposed.
    // ==> add here if more are needed <==
    NBits    ///< Number of bits currently supported.
  }; // triggerType

  /// Type of mask with `triggerType` bits.
  using triggerTypeMask = mask_t<triggerType>;
  
  /// Trigger window mode
  enum class triggerWindowMode: unsigned int {
    Separated,             ///< Separated, non-overlapping contiguous window.
    Overlapping,           ///< Overlapping windows.
    SeparatedPlusAdders,   ///< OR of `Separated` and `Adders`.
    OverlappingPlusAdders, ///< OR of `Overlapping` and `Adders`.
    Adders,                ///< Trigger from adders.
    //==> add here if more are needed <==
    NBits     ///< Number of Bits currently supported
  };
  
  /// Enabled gates in the trigger configuration. See register 0X00050008 in docdb SBN-doc-23778-v1
  enum class gateSelection: unsigned int {
    GateBNB,                     ///<Enable receiving BNB early warning signal (gatedBES) to open BNB gates
    DriftGateBNB,                ///<Enable BNB early-early warning signal ($1D) for light out-of-time in BNB gates
    GateNuMI,                    ///<Enable NuMI early warning signal (MIBS$74) to open NuMI gates
    DriftGateNuMI,               ///<Enable receiving NuMI early-early warning signal ($AD) for light out-of-time in NuMI gates
    GateOffbeamBNB,              ///<Enable Offbeam gate for BNB
    DriftGateOffbeamBNB,         ///<Enable Offbeam drift gate BNB (for light out-of-time in offbeam gates)
    GateOffbeamNuMI,             ///<Enable Offbeam gate for NuMI
    DriftGateOffbeamNuMI,        ///<Enable Offbeam drift gate NuMI (for light out-of-time in offbeam gates)
    GateCalibration,             ///<Enable Calibration gate
    DriftGateCalibration,        ///<Enable Calibration drift gate (for light out-of-time in calibration gates)
    MinbiasGateBNB,              ///<Enable MinBias triggers for the BNB stream
    MinbiasGateNuMI,             ///<Enable MinBias triggers for the NuMI stream
    MinbiasGateOffbeamBNB,       ///<Enabke MinBias triggers for the Offbeam BNB stream
    MinbiasGateOffbeamNuMI,      ///<Enable MinBias triggers for the Offbeam NuMI stream
    MinbiasGateCalibration,      ///<Enable MinBias triggers for the Calibration stream
    MinbiasDriftGateBNB,         ///<Enable light out-of-time for MinBias triggers in BNB stream
    MinbiasDriftGateNuMI,        ///<Enable light out-of-time for MinBias triggers in NuMI stream
    MinbiasDriftGateOffbeamBNB,  ///<Enable light out-of-time for MinBias triggers in Offbeam BNB stream
    MinbiasDriftGateOffbeamNuMI, ///<Enable light out-of-time for MinBias triggers in Offbeam NuMI stream
    MinbiasDriftGateCalibration, ///<Enable light out-of-time for MinBias triggers in Calibration stream
    // ==> add here if more are needed <==
    NBits
  }; // gateSelection

  using gateSelectionMask = mask_t<gateSelection>;


  /// @}
  // --- END ---- Beam bits ----------------------------------------------------

} // namespace sbn::bits

namespace sbn { // import symbol
  
  using bits::triggerSource;
  using bits::triggerSourceMask;
  using bits::triggerType;
  using bits::triggerTypeMask;
  using bits::triggerLogic;
  using bits::triggerLogicMask;
  using bits::triggerLocation;
  using bits::triggerLocationMask;
  using bits::triggerWindowMode;
  using bits::gateSelection;
  
} // namespace sbn


// -----------------------------------------------------------------------------
// ---  enumerator names
// -----------------------------------------------------------------------------
//
// `nameRegistry()` functions must live in the namespace where their enumerators
// are defined (see `EnumNameRegistry.h`). The registry itself can be anywhere,
// and it's better not clutter that namespace; however it is defined `auto`
// and it can't be detached into a implementation file.
//
namespace sbn::bits {
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  namespace details {
    inline constexpr auto triggerSourceNames = ::util::makeNameRegistry<triggerSource>({
      { triggerSource::Unknown,     "unknown"     },
      { triggerSource::BNB,         "BNB"         },
      { triggerSource::NuMI,        "NuMI"        },
      { triggerSource::OffbeamBNB,  "OffbeamBNB"  },
      { triggerSource::OffbeamNuMI, "OffbeamNuMI" },
      { triggerSource::Calib,       "Calib"       },
      { triggerSource::NBits,       "<invalid>"   },
      // some aliases
      { triggerSource::OffbeamBNB,  "BNBoffbeam"  },
      { triggerSource::OffbeamNuMI, "NuMIoffbeam" },
      { triggerSource::Calib,       "Calibration" },
    });
  }
  
  inline constexpr auto const& nameRegistry(triggerSource)
    { return details::triggerSourceNames; }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  namespace details {
    inline constexpr auto triggerLocationNames = ::util::makeNameRegistry<triggerLocation>({
      { triggerLocation::CryoEast, "Cryo E"    },
      { triggerLocation::CryoWest, "Cryo W"    },
      { triggerLocation::TPCEE,    "TPC EE"    },
      { triggerLocation::TPCEW,    "TPC EW"    },
      { triggerLocation::TPCWE,    "TPC WE"    },
      { triggerLocation::TPCWW,    "TPC WW"    },
      { triggerLocation::NBits,    "<invalid>" },
    });
  }

  inline constexpr auto const& nameRegistry(triggerLocation)
    { return details::triggerLocationNames; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  namespace details {
    inline constexpr auto triggerLogicNames = ::util::makeNameRegistry<triggerLogic>({
      { triggerLogic::PMTPairMajority, "PMT pair majority" },
      { triggerLogic::PMTAnalogSum,    "PMT analog sum"    },
      { triggerLogic::NBits,           "<invalid>"         },
    });
  }

  inline constexpr auto const& nameRegistry(triggerLogic)
    { return details::triggerLogicNames; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  namespace details {
    inline constexpr auto triggerTypeNames = ::util::makeNameRegistry<triggerType>({
      { triggerType::Majority,    "majority"     },
      { triggerType::MinimumBias, "minimum bias" },
      { triggerType::NBits,       "<invalid>"    },
    });
  }

  inline constexpr auto const& nameRegistry(triggerType)
    { return details::triggerTypeNames; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  namespace details {
    inline constexpr auto triggerWindowModeNames = ::util::makeNameRegistry<triggerWindowMode>({
      { triggerWindowMode::Separated,             "Separated Window"   },
      { triggerWindowMode::Overlapping,           "Overlapping Window" },
      { triggerWindowMode::SeparatedPlusAdders,   "Separated Both"     },
      { triggerWindowMode::OverlappingPlusAdders, "Overlapping Both"   },
      { triggerWindowMode::Adders,                "Adders"             },
      { triggerWindowMode::NBits,                 "<invalid>"          },
    });
  }

  inline constexpr auto const& nameRegistry(triggerWindowMode)
    { return details::triggerWindowModeNames; }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  namespace details {
    inline constexpr auto gateSelectionNames = ::util::makeNameRegistry<gateSelection>({
      { gateSelection::GateBNB,                     "GateBNB"                     },
      { gateSelection::DriftGateBNB,                "DriftGateBNB"                },
      { gateSelection::GateNuMI,                    "GateNuMI"                    },
      { gateSelection::DriftGateNuMI,               "DriftGateNuMI"               },
      { gateSelection::GateOffbeamBNB,              "GateOffbeamBNB"              },
      { gateSelection::DriftGateOffbeamBNB,         "DriftGateOffbeamBNB"         },
      { gateSelection::GateOffbeamNuMI,             "GateOffbeamNuMI"             },
      { gateSelection::DriftGateOffbeamNuMI,        "DriftGateOffbeamNuMI"        },
      { gateSelection::GateCalibration,             "GateCalibration"             },
      { gateSelection::DriftGateCalibration,        "DriftGateCalibration"        },
      { gateSelection::MinbiasGateBNB,              "MinbiasGateBNB"              },
      { gateSelection::MinbiasGateNuMI,             "MinbiasGateNuMI"             },
      { gateSelection::MinbiasGateOffbeamBNB,       "MinbiasGateOffbeamBNB"       },
      { gateSelection::MinbiasGateOffbeamNuMI,      "MinbiasGateOffbeamNuMI"      },
      { gateSelection::MinbiasGateCalibration,      "MinbiasGateCalibration"      },
      { gateSelection::MinbiasDriftGateBNB,         "MinbiasDriftGateBNB"         },
      { gateSelection::MinbiasDriftGateNuMI,        "MinbiasDriftGateNuMI"        },
      { gateSelection::MinbiasDriftGateOffbeamBNB,  "MinbiasDriftGateOffbeamBNB"  },
      { gateSelection::MinbiasDriftGateOffbeamNuMI, "MinbiasDriftGateOffbeamNuMI" },
      { gateSelection::MinbiasDriftGateCalibration, "MinbiasDriftGateCalibration" },
      { gateSelection::NBits,                       "NBits"                       },
    });
  }

  inline constexpr auto const& nameRegistry(gateSelection)
    { return details::gateSelectionNames; }
    
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  
} // namespace sbn::bits


// -----------------------------------------------------------------------------
// ---  inline and template implementation
// -----------------------------------------------------------------------------
template <::util::ScopedEnum Enum>
auto sbn::bits::makeMask  (typename mask_t<Enum>::maskbits_t bits) noexcept
  -> mask_t<Enum>
  { return { bits }; }


// -----------------------------------------------------------------------------
template <util::ScopedEnum Enum>
constexpr auto sbn::bits::value(Enum bit)
  { return static_cast<std::underlying_type_t<Enum>>(bit); }


// -----------------------------------------------------------------------------
template <util::ScopedEnum Enum, typename... OtherBits>
constexpr auto sbn::bits::mask(Enum bit, OtherBits... otherBits)
  -> mask_t<Enum>
{
  unsigned int m { 1U << value(bit) };
  if constexpr(sizeof...(OtherBits) > 0U) m |= mask(otherBits...);
  return { m };
} // sbn::mask()


// -----------------------------------------------------------------------------
template <::util::ScopedEnum Enum>
constexpr bool sbn::bits::hasBitSet(mask_t<Enum> bitMask, Enum bit)
  { return bitMask & mask(bit); }


// -----------------------------------------------------------------------------
template <::util::RegisteredEnum Enum>
std::string sbn::bits::name(Enum bit) {
  if (auto const name = nameRegistry(bit).optName(bit); name)
    return std::string{ name.value() };
  // sbnobj must not depend on larcorealg, else we'd used lar::debug::demangle()
  using namespace std::string_literals;
  throw std::runtime_error{
    "sbn::bits::name("s + typeid(std::decay_t<Enum>).name() + "{ "s
    + std::to_string(value(bit)) + " }): unknown bit"s
    };
} // sbn::bits::name()


// -----------------------------------------------------------------------------
template <::util::RegisteredEnum Enum>
std::vector<std::string> sbn::bits::names(mask_t<Enum> mask) {
  auto const& allNames = ::util::allEnumNames<Enum>();
  return std::vector<std::string>{ begin(allNames), end(allNames) };
} // sbn::bits::names()


// -----------------------------------------------------------------------------
template <::util::RegisteredEnum Enum>
std::optional<Enum> sbn::bits::parse
  (std::string_view name, bool caseSensitive /* = true */)
{
  return caseSensitive? ::util::parseEnumName<Enum>(name)
    : ::util::parseEnumNameAnyCase<Enum>(name);
} // sbn::bits::parse()


// -----------------------------------------------------------------------------
namespace icarus::trigger {

  /// @name Bit definitions specific to ICARUS trigger
  /// @{

  using triggerLocation = sbn::triggerLocation;
  using triggerSource   = sbn::triggerSource;

  static constexpr std::size_t kEast             = sbn::bits::value<triggerLocation>(triggerLocation::CryoEast);
  static constexpr std::size_t kWest             = sbn::bits::value<triggerLocation>(triggerLocation::CryoWest);
  static constexpr std::size_t kNTriggerLocation = sbn::bits::value<triggerLocation>(triggerLocation::NBits);

  static constexpr std::size_t kBNB            = sbn::bits::value<triggerSource>(triggerSource::BNB);
  static constexpr std::size_t kNuMI           = sbn::bits::value<triggerSource>(triggerSource::NuMI);
  static constexpr std::size_t kOffBeamBNB     = sbn::bits::value<triggerSource>(triggerSource::OffbeamBNB);
  static constexpr std::size_t kOffBeamNuMI    = sbn::bits::value<triggerSource>(triggerSource::OffbeamNuMI);
  static constexpr std::size_t kCalibration    = sbn::bits::value<triggerSource>(triggerSource::Calib);
  static constexpr std::size_t kNTriggerSource = sbn::bits::value<triggerSource>(triggerSource::NBits);

  /// @}
  
} // namespace icarus::trigger


// -----------------------------------------------------------------------------

#endif // SBNOBJ_COMMON_TRIGGER_BEAMBITS_H
