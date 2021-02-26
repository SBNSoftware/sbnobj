/**
 * @file   sbnobj/Common/PMT/Data/PMTconfiguration.h
 * @brief  Information from the configuration of PMT readout.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 18, 2021
 * @see    sbnobj/Common/PMT/Data/PMTconfiguration.cxx
 */

#ifndef SBNOBJ_COMMON_PMT_DATA_PMTCONFIGURATION_H
#define SBNOBJ_COMMON_PMT_DATA_PMTCONFIGURATION_H

// SBN libraries
#include "sbnobj/Common/PMT/Data/V1730Configuration.h"

// C/C++ standard libraries
#include <iosfwd> // std::ostream
#include <string>
#include <vector>


//------------------------------------------------------------------------------
namespace sbn {
  
  struct PMTconfiguration;
  
  /// Prints the configuration into a stream with default verbosity.
  std::ostream& operator<<
    (std::ostream& out, sbn::PMTconfiguration const& config);
  
} // namespace sbn

/**
 * @brief Class containing configuration for PMT readout.
 * 
 * This is an informative class containing configuration of all V1730 boards
 * extracted from some other source (typically, DAQ) made readily available
 * to the users.
 * 
 * This class does not include any configuration extraction code.
 * 
 * The class is default-constructible only, and its content needs to be added
 * element by element.
 * 
 */
struct sbn::PMTconfiguration {
  
  // --- BEGIN -- Data members -------------------------------------------------
  
  // NOTE when adding data members, remember to add an element to the comparison
  
  /// Configuration of all PMT readout boards.
  std::vector<sbn::V1730Configuration> boards;
  
  // --- END ---- Data members -------------------------------------------------
  
#if __cplusplus < 202004L
  //@{
  /// Comparison: all fields need to have the same values.
  bool operator== (PMTconfiguration const& other) const;
  bool operator!= (PMTconfiguration const& other) const
    { return ! this->operator== (other); }
  //@}
#else
# error "With C++20 support, enable the default comparison operators"
  // probably the compiler will be generating these anyway, so don't bother
//   bool operator== (PMTconfiguration const& other) const = default;
//   bool operator!= (PMTconfiguration const& other) const = default;
#endif
  
  // -- BEGIN -- Dump facility -------------------------------------------------
  /// Maximum supported verbosity level supported by `dump()`.
  static constexpr unsigned int MaxDumpVerbosity
    = V1730Configuration::MaxDumpVerbosity + 1U;
  
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
   * * `0`: only the number of boards in the configuration
   * * `1`: information on each board, as in `V1730Configuration::dump()` with
   *        verbosity one level smaller than the value of `verbosity` argument
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
  
}; // sbn::PMTconfiguration



//------------------------------------------------------------------------------
//---  Inline implementation
//------------------------------------------------------------------------------
inline bool sbn::PMTconfiguration::operator==
  (sbn::PMTconfiguration const& other) const
{
  
  if (boards != other.boards) return false;
  
  return true;
} // sbn::PMTconfiguration::operator==()


//------------------------------------------------------------------------------
inline std::ostream& sbn::operator<<
  (std::ostream& out, sbn::PMTconfiguration const& config)
  { config.dump(out); return out; }


//------------------------------------------------------------------------------

#endif // SBNOBJ_COMMON_PMT_DATA_PMTCONFIGURATION_H
