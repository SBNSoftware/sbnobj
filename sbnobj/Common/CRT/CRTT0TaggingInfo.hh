/**
 * @file   sbnobj/Common/CRT/CRTT0TaggingInfo.hh
 * @author Francesco Poppi (poppi@bo.infn.it)
 * @date   January 2025
 */

#ifndef SBNOBJ_COMMON_CRTT0TaggingInfo_hh_
#define SBNOBJ_COMMON_CRTT0TaggingInfo_hh_

// C/C++ standard libraries
#include <limits>

// -----------------------------------------------------------------------------
namespace sbn::crt { 
  /// @brief How was the track fitted when matched with a CRT hit.

  enum class CRTTaggingMethod {
    crtHits = 0, // matching performed using single CRT Hits (ICARUS like)
    crtTracks = 1 // matching performed using CRTTracks (SBND like)
  };

  enum class CRTTaggingTrackFit { 
    pca = 0, // Track fitted with PCA method
    startEnd = 1, // Track fitted from Start-End vector
    kalman = 2, // Track fitted using Kalman Filter
    others = 9 // Track direction evaluated in other mehods
  };
      
  struct CRTT0TaggingInfo;
}
/**
 * @brief Additional information on the matching between CRT and TPC tracks.
 * 
 */
struct sbn::crt::CRTT0TaggingInfo {
  
  /// Magic value denoting the absence of DCA information.
  static constexpr double NoDistance = std::numeric_limits<double>::lowest();
  static constexpr double NoTime = std::numeric_limits<double>::lowest();

  /// Magic value denoting the absence of CRTs.
  static constexpr int NoCRT = std::numeric_limits<int>::lowest();

  /// Magic value denoting the absence of CRT Plane.
  static constexpr int NoPlane = std::numeric_limits<int>::lowest();

  // --- BEGIN -- Data members -------------------------------------------------
  
  // Francesco: following a discussion with Henry Lay, we decided that is good
  // to have a common object to store additional information, but at the moment
  // the matching approach is different, ICARUS uses single CRT Hits to track
  // matching, while SBND uses CRTTracks. Due to this difference, we decided
  // to add a notation "singleHit" in the member which will differ between 
  // ICARUS and SBND. SBND, once ready, will add their members adding as a
  // prefix something like crtTracks. We might at some point do more discussion
  // and see if we can merge the final addition information even more.

  /// Distance of closest approach between track extension and CRT hit [cm]
  double singleHitDistance = NoDistance;

  /// Matched CRT Hit sub detector 
  // e.g. ICARUS case: 0 Top, 1 Side, 2 Bottom
  int singleHitSys = NoCRT;

  /// Matched CRT Hit region
  // e.g. ICARUS case: 30-34 Top CRT, 40-48 Side CRT, 50 Bottom CRT
  int singleHitRegion = NoCRT;

  /// Matched CRT Hit time w.r.t. trigger [ns]
  double singleHitTime = NoTime;

  /// Distance distinguished into its components DX, DY, DZ [cm]
  double singleHitDeltaX = NoDistance;
  double singleHitDeltaY = NoDistance;
  double singleHitDeltaZ = NoDistance;

  /// Extrapolated Track Projection Crossing Point onto the CRT Plane
  double singleHitCrossX = NoDistance;
  double singleHitCrossY = NoDistance;
  double singleHitCrossZ = NoDistance;

  /// Fix Coordinate for the CRT Plane
  // e.g. ICARUS case:
  // For Top CRT region 30 Y coordinate is constant: plane=0
  // For Top CRT region 31/32 and Side CRT 40/41/42/43/44/45 X coordinate is constant: plane=1
  // For Top CRT region 33/34 and Side CRT 46/47 Z coordinate is constant: plane=2
  int singleHitPlane = NoPlane;

  CRTTaggingTrackFit fitType;
  CRTTaggingMethod  taggingMethod;


  /// Turth level information of the match.
  /// Default is false for both data and MC. For MC this information is filled if MC truth is available.
  bool truthMatch = false;

  // --- END ---- Data members -------------------------------------------------
    
}; // sbn::crt::CRTT0TaggingInfo


// -----------------------------------------------------------------------------


#endif // SBNOBJ_COMMON_CRTT0TaggingInfo_hh_