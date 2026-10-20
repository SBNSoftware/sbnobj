/**
 * @file   sbnobj/Common/Metadata/JobEnvironmentInfo.cxx
 * @brief  Information from the execution environment of the job.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   January 16, 2025
 * @see    sbnobj/Common/Metadata/JobEnvironmentInfo.h
 */

// library header
#include "sbnobj/Common/Metadata/JobEnvironmentInfo.h"

// C/C++ standard libraries
#include <ostream>
#include <sstream>


// -----------------------------------------------------------------------------
// ---  sbn::JobEnvironmentInfo  -----------------------------------------------
// -----------------------------------------------------------------------------
void sbn::JobEnvironmentInfo::dump(std::ostream& out) const {
  
  out << "Process name: '" << processName << "'";
  
  out << "\n\nRelease of art framework: " << artVersion;
  
  out << "\n\nSource repository versions (" << sources.size() << ")\n"
    << std::string(80, '-') << "\n\n";
  sources.dump(out);
  
  out << "\n\nEnvironment variables (" << variables.size() << ")\n"
    << std::string(80, '-') << "\n\n";
  variables.dump(out);
  
} // sbn::JobEnvironmentInfo::dump()


// -----------------------------------------------------------------------------
std::string sbn::JobEnvironmentInfo::to_string() const {
  
  std::ostringstream sstr;
  dump(sstr);
  return sstr.str();
  
}


// -----------------------------------------------------------------------------
// ---  free functions  --------------------------------------------------------
// -----------------------------------------------------------------------------
std::ostream& sbn::operator<<
  (std::ostream& out, JobEnvironmentInfo const& info)
  { info.dump(out); return out; }


// -----------------------------------------------------------------------------
