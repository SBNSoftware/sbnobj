/**
 * @file   sbnobj/Common/Metadata/JobEnvironmentInfo.h
 * @brief  Information from the execution environment of the job.
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   January 16, 2025
 * @see    sbnobj/Common/Metadata/JobEnvironmentInfo.cxx
 */


#ifndef SBNOBJ_COMMON_METADATA_JOBENVIRONMENTINFO_H
#define SBNOBJ_COMMON_METADATA_JOBENVIRONMENTINFO_H

// SBN libraries
#include "sbnobj/Common/Metadata/OrderedPairList.h"

// C/C++ standard libraries
#include <optional>
#include <string>
#include <tuple> // std::pair
#include <vector>
#include <iosfwd> // std::ostream


// -----------------------------------------------------------------------------
namespace sbn {
  struct JobEnvironmentInfo;
  
  /// Dump of a `JobEnvironmentInfo` object into a C++ output stream.
  std::ostream& operator<< (std::ostream& out, JobEnvironmentInfo const& info);
  
}

// -----------------------------------------------------------------------------
/**
 * @brief Information from the execution environment of the job.
 * 
 * Current information includes:
 *  * a complete snapshot of the environment variables (`getenv()`);
 *  * _art_ version;
 *  * a list of GIT tag for the package sources.
 * 
 * Future extensions should include:
 *  * A list of packages recognised as SciSoft stack packages, their versions,
 *    qualifiers and paths. Probably not worth until build system is revamped.
 * 
 */
struct sbn::JobEnvironmentInfo {
  
  std::string processName; ///< Name of the _art_ process for the job.
  
  std::string artVersion; ///< Version of _art_.
  
  sbn::OrderedPairList sources; ///< Version of the source repositories.
  
  sbn::OrderedPairList variables; ///< Environment variables.
  
  
  /// Dumps the entire content of the environment in human-readable form.
  void dump(std::ostream& out) const;
  
  /// Returns the entire content of the environment in human-readable form.
  std::string to_string() const;
  
}; // sbn::JobEnvironmentInfo



// -----------------------------------------------------------------------------

#endif // SBNOBJ_COMMON_METADATA_JOBENVIRONMENTINFO_H
