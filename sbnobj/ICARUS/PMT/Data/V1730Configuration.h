/**
 * @file   sbnobj/ICARUS/PMT/Data/V1730Configuration.h
 * @brief  Information from the configuration of a V1730 PMT readout board.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 18, 2021
 * @see    sbnobj/ICARUS/PMT/Data/V1730Configuration.cxx
 */

#ifndef SBNOBJ_ICARUS_PMT_DATA_V1730CONFIGURATION_H
#define SBNOBJ_ICARUS_PMT_DATA_V1730CONFIGURATION_H


// ICARUS libraries
#include "sbnobj/ICARUS/PMT/Data/V1730channelConfiguration.h"

// C/C++ standard libraries
#include <iosfwd> // std::ostream
#include <vector>
#include <string>


//------------------------------------------------------------------------------
namespace icarus {
  
  struct V1730Configuration;
  
  /// Prints the configuration into a stream with default verbosity.
  std::ostream& operator<<
    (std::ostream& out, icarus::V1730Configuration const& config);
  
} // namespace icarus

/**
 * @brief Class containing configuration for a V1730 board.
 * 
 * This is an informative class containing configuration of a V1730 board
 * extracted from some other source (typically, DAQ) made readily available
 * to the users.
 * 
 * This class does not include any configuration extraction code.
 * 
 * The class is default-constructible only, and its content needs to be added
 * element by element.
 * 
 */
struct icarus::V1730Configuration {
  
  // --- BEGIN -- Data members -------------------------------------------------
  
  // NOTE when adding data members, remember to add an element to the comparison
  
  /// Name (mnemonic) of the board.
  std::string boardName;
  
  /// Numeric ID of the board (`board_id`).
  unsigned int boardID = std::numeric_limits<unsigned int>::max();
  
  /// DAQ fragment ID.
  unsigned int fragmentID = std::numeric_limits<unsigned int>::max();
  
  /// Ticks in each buffer (`recordLength`).
  unsigned int bufferLength = 0U;
  
  /// Fraction of the waveform _after_ the trigger signal (`postPercent`).
  float postTriggerFrac = 0.0f;
  
  /// Number of channels (`nChannels`).
  unsigned int nChannels = 0U;
  
  /// Configuration of each channel.
  std::vector<icarus::V1730channelConfiguration> channels;
  
  // --- END ---- Data members -------------------------------------------------
  
  
  // --- BEGIN -- Derived quantities -------------------------------------------
  
  /// Ticks in the waveform before the trigger.
  unsigned int preTriggerTicks() const;
  
  /// Ticks in the waveform after the trigger.
  unsigned int postTriggerTicks() const;
  
  /// Duration of the waveform [us].
  float bufferTime() const;
  
  /// Time in the waveform before the trigger [us].
  float preTriggerTime() const;
  
  /// Time in the waveform after the trigger [us].
  float postTriggerTime() const;
  
  // --- END ---- Derived quantities -------------------------------------------
  
  
#if __cplusplus < 202004L
  //@{
  /// Comparison: all fields need to have the same values.
  bool operator== (V1730Configuration const& other) const;
  bool operator!= (V1730Configuration const& other) const
    { return ! this->operator== (other); }
  //@}
#else
# error "With C++20 support, enable the default comparison operators"
  // probably the compiler will be generating these anyway, so don't bother
//   bool operator== (V1730Configuration const& other) const = default;
//   bool operator!= (V1730Configuration const& other) const = default;
#endif
  
  // -- BEGIN -- Dump facility -------------------------------------------------
  /// Maximum supported verbosity level supported by `dump()`.
  static constexpr unsigned int MaxDumpVerbosity
    = V1730channelConfiguration::MaxDumpVerbosity + 1U;
  
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
   * * `0`: name of the board, board and fragment ID, number of channels
   * * `1`: waveform length and post-trigger fraction;
   * *   information on each channel, one per line, as with
   * *   `V1730channelConfiguration::dump() with verbosity one level smaller
   * *   than the value of `verbosity` argument
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
  
  
  /// Convert a number of ticks into a time interval in microseconds.
  static float ticks2us(int ticks) { return ticks * 0.002f; }

}; // icarus::V1730Configuration



//------------------------------------------------------------------------------
//---  Inline implementation
//------------------------------------------------------------------------------
inline unsigned int icarus::V1730Configuration::preTriggerTicks() const
  { return static_cast<unsigned int>((1.0f - postTriggerFrac) * bufferLength); }


//------------------------------------------------------------------------------
inline unsigned int icarus::V1730Configuration::postTriggerTicks() const
  { return static_cast<unsigned int>(postTriggerFrac * bufferLength); }


//------------------------------------------------------------------------------
inline float icarus::V1730Configuration::bufferTime() const
  { return ticks2us(bufferLength); }


//------------------------------------------------------------------------------
inline float icarus::V1730Configuration::preTriggerTime() const
  { return ticks2us(preTriggerTicks()); }


//------------------------------------------------------------------------------
inline float icarus::V1730Configuration::postTriggerTime() const
  { return ticks2us(postTriggerTicks()); }


//------------------------------------------------------------------------------
inline bool icarus::V1730Configuration::operator==
  (icarus::V1730Configuration const& other) const
{
  
  if (boardName       != other.boardName      ) return false;
  if (boardID         != other.boardID        ) return false;
  if (fragmentID      != other.fragmentID     ) return false;
  if (bufferLength    != other.bufferLength   ) return false;
  if (postTriggerFrac != other.postTriggerFrac) return false;
  if (nChannels       != other.nChannels      ) return false;
  if (channels        != other.channels       ) return false;
  
  return true;
} // icarus::V1730Configuration::operator==()


//------------------------------------------------------------------------------
inline std::ostream& icarus::operator<<
  (std::ostream& out, icarus::V1730Configuration const& config)
  { config.dump(out); return out; }


//------------------------------------------------------------------------------

#endif // SBNOBJ_ICARUS_PMT_DATA_V1730CONFIGURATION_H
