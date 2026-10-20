/**
 * @file   sbnobj/Common/CRT/CRTHitT0TaggingTruthInfo.hh
 * @author Francesco Poppi (poppi@bo.infn.it)
 * @date   January 2025
 */

#ifndef SBNOBJ_COMMON_CRTHitT0TaggingTruthInfo_hh_
#define SBNOBJ_COMMON_CRTHitT0TaggingTruthInfo_hh_

// C/C++ standard libraries
#include <limits>

// -----------------------------------------------------------------------------
namespace sbn::crt { 
  struct CRTHitT0TaggingTruthInfo;
}
/**
 * @brief Truth information on the matching between CRT and TPC tracks.
 * 
 */
struct sbn::crt::CRTHitT0TaggingTruthInfo {
  static constexpr double NoCoordinate = std::numeric_limits<double>::lowest();
  static constexpr int NoId = std::numeric_limits<int>::lowest();
  static constexpr int NoPdg = std::numeric_limits<int>::lowest();

  /// Verify that the truth level information of the track were correctly retrieved.
  /// Default is false.
  bool truthFound = false;

  /// Turth level information of the match.
  /// Default is false. For MC this information is filled if MC truth is available.
  bool truthMatch = false;

  /// Truth information of the particle Geant4Id.
  int truthG4TrackId = NoId;

  /// Truth information of the particle Pdg code.
  int truthTrackPdgCode = NoPdg;

  /// Truth information if the particle is associated with the neutrino interaction
  /// or not (information from generator). Default is false.
  bool truthIsNu = false;

  // --- END ---- Data members -------------------------------------------------
    
}; // sbn::crt::CRTHitT0TaggingTruthInfo

// -----------------------------------------------------------------------------


#endif // SBNOBJ_COMMON_CRTHitT0TaggingTruthInfo_hh_