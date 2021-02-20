/**
 * @file   sbnobj/ICARUS/PMT/Data/PMTconfiguration.cxx
 * @brief  Information from the configuration of a V1730 PMT readout board.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 18, 2021
 * @see    sbnobj/ICARUS/PMT/Data/PMTconfiguration.h
 */


// library header
#include "sbnobj/ICARUS/PMT/Data/PMTconfiguration.h"

// C/C++ standard libraries
#include <ostream>
#include <cassert>


//------------------------------------------------------------------------------
static_assert(icarus::PMTconfiguration::DefaultDumpVerbosity <= icarus::PMTconfiguration::MaxDumpVerbosity);

//------------------------------------------------------------------------------
void icarus::PMTconfiguration::dump(std::ostream& out,
  std::string const& indent, std::string const& firstIndent,
  unsigned int verbosity /* = MaxDumpVerbosity */
) const{
  
  do { // fake look for easy break: `goto` in disguise
    
    // start a new line with indentation:
    auto const outnl
      = [&out,&indent]() -> std::ostream& { return out << '\n' << indent; };
    
    unsigned int level = 0U;
    
    
    // --- verbosity: 0+ -------------------------------------------------------
    std::size_t const nReadoutBoards = boards.size();
    out << firstIndent
      << nReadoutBoards << " readout board configurations"
      ;
    
    if (++level > verbosity) break;
    // --- verbosity: 1+ -------------------------------------------------------
    out << ":"
      << "\n"; // since V1730Configuration::dump() ends line...
    for (std::size_t iBoard = 0U; iBoard != nReadoutBoards; ++iBoard) {
      
      icarus::V1730Configuration const& boardConfig
        = boards[iBoard];
      out << indent << "[B" << iBoard << "]: ";
      boardConfig.dump(out, indent + "  ", "", verbosity - 1U);
      
    } // for
    
    if (++level > verbosity) break;
    // --- verbosity: 2+ -------------------------------------------------------
    
    // nothing special here, but still counts
    
    if (++level > verbosity) break;
    // --- verbosity: 3+ -------------------------------------------------------
    
    // nothing special here, but still counts
    
    if (++level > verbosity) break;
    // --- verbosity: 4+ -------------------------------------------------------
    assert(level == MaxDumpVerbosity + 1U);
    
    // this is more debug information than anything else: verbosity was too high
    outnl() << "No more information available (reached level " << level << ").";
  
  } while(false);
  
  out << "\n";
  
} // icarus::PMTconfiguration::dump()


//------------------------------------------------------------------------------
