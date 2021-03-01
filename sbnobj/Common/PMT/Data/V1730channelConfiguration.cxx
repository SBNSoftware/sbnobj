/**
 * @file   sbnobj/Common/PMT/Data/V1730channelConfiguration.cxx
 * @brief  Information from the configuration of a V1730 PMT readout board.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 18, 2021
 * @see    sbnobj/Common/PMT/Data/V1730channelConfiguration.h
 */

// library header
#include "sbnobj/Common/PMT/Data/V1730channelConfiguration.h"

// C/C++ standard libraries
#include <ostream>
#include <cassert>


//------------------------------------------------------------------------------
static_assert(sbn::V1730channelConfiguration::DefaultDumpVerbosity <= sbn::V1730channelConfiguration::MaxDumpVerbosity);

//------------------------------------------------------------------------------
void sbn::V1730channelConfiguration::dump(std::ostream& out,
  std::string const& indent, std::string const& firstIndent,
  unsigned int verbosity /* = MaxDumpVerbosity */
) const{
  
  do { // fake look for easy break: `goto` in disguise
    
    // start a new line with indentation:
    auto const outnl
      = [&out,&indent]() -> std::ostream& { return out << '\n' << indent; };
    
    unsigned int level = 0U;
    
    // --- verbosity: 0+ -------------------------------------------------------
    out << firstIndent
      << "board channel #" << channelNo
      << " (" << (enabled? "enabled": "disabled") << ")"
      ;
    if (hasChannelID()) out << ", offline ID: " << channelID;
    
    if (++level > verbosity) break;
    // --- verbosity: 1+ -------------------------------------------------------
    out << ", baseline: " << baseline << ", threshold: " << threshold
      << " (delta=" << relativeThreshold() << ")"
      ;
    
    if (++level > verbosity) break;
    // --- verbosity: 2+ -------------------------------------------------------
    
    assert(level == MaxDumpVerbosity + 1U);
    
    // this is more debug information than anything else: verbosity was too high
    outnl() << "No more information available (reached level " << level << ").";
  
  } while(false);
  
  out << "\n";
  
} // sbn::V1730channelConfiguration::dump()


//------------------------------------------------------------------------------
