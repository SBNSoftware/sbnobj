/**
 * @file   sbnobj/Common/PMT/Data/V1730channelConfiguration.h
 * @brief  Information from the configuration of a V1730 PMT readout board.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 18, 2021
 * @see    sbnobj/Common/PMT/Data/V1730channelConfiguration.cxx
 */

#ifndef SBNOBJ_COMMON_PMT_DATA_V1730CHANNELCONFIGURATION_H
#define SBNOBJ_COMMON_PMT_DATA_V1730CHANNELCONFIGURATION_H

// LArSoft libraries
#include <cstdint>  // uint16_t in OpDetWaveform.h
#include "lardataobj/RawData/OpDetWaveform.h" // raw::Channel_t

// C/C++ standard libraries
#include <iosfwd> // std::ostream
#include <string>
#include <limits>


//------------------------------------------------------------------------------
namespace sbn {
  
  struct V1730channelConfiguration;
  
  /// Prints the configuration into a stream with default verbosity.
  std::ostream& operator<<
    (std::ostream& out, sbn::V1730channelConfiguration const& config);
  
} // namespace sbn

/**
 * @brief Class containing configuration for a V1730 channel.
 * 
 * This is an informative class containing configuration of a V1730 channel
 * extracted from some other source (typically, DAQ) made readily available
 * to the users.
 * 
 * This class does not include any configuration extraction code.
 * 
 * The class is default-constructible only, and its content needs to be added
 * element by element.
 * 
 */
struct sbn::V1730channelConfiguration {
  
  /// Special value for unassigned channel ID.
  static constexpr auto NoChannelID
    = std::numeric_limits<raw::Channel_t>::max();
  
  // --- BEGIN -- Data members -------------------------------------------------
  
  // NOTE when adding data members, remember to add an element to the comparison
  
  /// Number of the channel on the board (0-15).
  short unsigned int channelNo = std::numeric_limits<short unsigned int>::max();
  
  /// Offline channel ID.
  raw::Channel_t channelID = NoChannelID;
  
  /// Baseline (`BaselineCh<N+1>`).
  short signed int baseline = 0;
  
  /// Threshold (`triggerThreshold<N>`).
  short signed int threshold = 0;
  
  /// Channel is enabled (`enable`).
  bool enabled = false;
  
  // --- END ---- Data members -------------------------------------------------
  
  
  // --- BEGIN -- Derived quantities -------------------------------------------
  
  /// Returns whether the channel ID is set.
  bool hasChannelID() const;
  
  /// Threshold relative to the baseline (ticks).
  short signed int relativeThreshold() const;
  
  // --- END ---- Derived quantities -------------------------------------------
  
  
#if __cplusplus < 202004L
  //@{
  /// Comparison: all fields need to have the same values.
  bool operator== (V1730channelConfiguration const& other) const;
  bool operator!= (V1730channelConfiguration const& other) const
    { return ! this->operator== (other); }
  //@}
#else
# error "With C++20 support, enable the default comparison operators"
  // probably the compiler will be generating these anyway, so don't bother
//   bool operator== (V1730channelConfiguration const& other) const = default;
//   bool operator!= (V1730channelConfiguration const& other) const = default;
#endif
  
  // -- BEGIN -- Dump facility -------------------------------------------------
  /// Maximum supported verbosity level supported by `dump()`.
  static constexpr unsigned int MaxDumpVerbosity = 1U;
  
  /// Default verbosity level for `dump()`.
  static constexpr unsigned int DefaultDumpVerbosity = MaxDumpVerbosity;
  
  
  /**
   * @brief Dumps the content of the configuration into `out` stream.
   * @param out stream to dump the information into
   * @param indent indentation string
   * @param firstIndent special indentation string for the first line
   * @param verbosity (default: `DefaultDumpVerbosity`) level of verbosity
   * 
   * The indentation string is prepended to each new line of the dump.
   * The first line indentation string is prepended before the first line of
   * the dump. The dump ends on a new empty line.
   * 
   * The amount of information printed depends on the `verbosity` level:
   * 
   * * `0`: channel number and whether it is enabled or not (also off-line
   *     channel ID if available)
   * * `1`: also baseline and threshold
   * 
   */
  void dump(std::ostream& out,
    std::string const& indent, std::string const& firstIndent,
    unsigned int verbosity = MaxDumpVerbosity
    ) const;
  
  /**
   * @brief Dumps the content of the configuration into `out` stream.
   * @param out stream to dump the information into
   * @param indent indentation level
   * @see `dump(std::ostream&, std::string const&, std::string const&, unsigned int) const`
   * 
   * Version of `dump()` with same first indentation level as the rest, and
   * default verbosity.
   */
  void dump(std::ostream& out, std::string const& indent = "") const
    { dump(out, indent, indent); }
  
  /**
   * @brief Dumps the content of the configuration into `out` stream.
   * @param out stream to dump the information into
   * @param indent (default: none) indentation string
   * @see `dump(std::ostream&, std::string const&, std::string const&, unsigned int) const`
   * 
   * Version of `dump()` with the specified `verbosity` level and same first
   * indentation level as the rest.
   */
  void dump(std::ostream& out,
    unsigned int verbosity,
    std::string const& indent = ""
    ) const
    { dump(out, indent, indent, verbosity); }
  
  // -- END ---- Dump facility -------------------------------------------------
  
}; // sbn::V1730channelConfiguration



//------------------------------------------------------------------------------
//---  Inline implementation
//------------------------------------------------------------------------------
inline bool sbn::V1730channelConfiguration::hasChannelID() const
  { return channelID != NoChannelID; }


//------------------------------------------------------------------------------
inline short signed int sbn::V1730channelConfiguration::relativeThreshold
  () const
  { return baseline - threshold; }


//------------------------------------------------------------------------------
inline bool sbn::V1730channelConfiguration::operator==
  (sbn::V1730channelConfiguration const& other) const
{
  if (channelNo != other.channelNo) return false;
  if (channelID != other.channelID) return false;
  if (baseline  != other.baseline ) return false;
  if (threshold != other.threshold) return false;
  if (enabled   != other.enabled  ) return false;
  
  return true;
} // sbn::V1730channelConfiguration::operator==()


//------------------------------------------------------------------------------
inline std::ostream& sbn::operator<<
  (std::ostream& out, sbn::V1730channelConfiguration const& config)
  { config.dump(out); return out; }


//------------------------------------------------------------------------------

#endif // SBNOBJ_COMMON_PMT_DATA_V1730CHANNELCONFIGURATION_H
