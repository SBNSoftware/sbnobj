/**
 * @file   sbnobj/Common/PMT/Data/V1730Configuration.cxx
 * @brief  Information from the configuration of a V1730 PMT readout board.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 18, 2021
 * @see    sbnobj/Common/PMT/Data/V1730Configuration.h
 */

// library header
#include "sbnobj/Common/PMT/Data/V1730Configuration.h"

// C/C++ standard libraries
#include <ostream>
#include <cassert>


//------------------------------------------------------------------------------
static_assert(sbn::V1730Configuration::DefaultDumpVerbosity <= sbn::V1730Configuration::MaxDumpVerbosity);

//------------------------------------------------------------------------------
void sbn::V1730Configuration::dump(std::ostream& out,
  std::string const& indent, std::string const& firstIndent,
  unsigned int verbosity /* = MaxDumpVerbosity */
) const{
  
  do {
    // fake look for easy break: `goto` in disguise;
    // `break` will add a final `'\n'`, `return` will not.
    
    // start a new line with indentation:
    auto const outnl
      = [&out,&indent]() -> std::ostream& { return out << '\n' << indent; };
    
    unsigned int level = 0U;
    
    
    // --- verbosity: 0+ -------------------------------------------------------
    out << firstIndent
      << "board name: '" << boardName << "' (ID: " << boardID
      << "; fragment ID: " << fragmentID << "), "
      << nChannels << " configured channels"
      ;
    
    if (++level > verbosity) break;
    // --- verbosity: 1+ -------------------------------------------------------
    outnl()
      << "waveform: " << bufferLength << " ticks (" << bufferTime()
      << " us), post-trigger fraction: " << (postTriggerFrac*100.0)
      << "% (" << preTriggerTime() << " + " << postTriggerTime() << " us)"
      ;
    out << '\n';
    for (std::size_t iChannel = 0U; iChannel < nChannels; ++iChannel) {
      
      sbn::V1730channelConfiguration const& channel = channels[iChannel];
      
      out << indent << "[" << iChannel << "] ";
      channel.dump(out, indent + "  ", "", verbosity - 1U);
      
    } // for channels
    // ends on new line
    
    if (++level > verbosity) return;
    // --- verbosity: 2+ -------------------------------------------------------
    
    out << indent // absorb the newline from the previous level
      << "fragment timestamp "
      << (useTimeTagForTimeStamp? "follows": "does not follow")
      << " the Trigger Time Tag"
      ;
    
    if (++level > verbosity) break;
    // --- verbosity: 3+ -------------------------------------------------------
    
    assert(level == MaxDumpVerbosity + 1U);
    
    // this is more debug information than anything else: verbosity was too high
    outnl() << "No more information available (reached level " << level << ").";
  
  } while(false);
  
  out << "\n";
  
} // sbn::V1730Configuration::dump()


//------------------------------------------------------------------------------
