/**
 * @file   sbnobj/Common/CRT/CRTHitT0TaggingInfo.hh
 * @author Francesco Poppi (poppi@bo.infn.it)
 * @date   January 2025
 */

#ifndef SBNOBJ_COMMON_CRTHitT0TaggingInfo_hh_
#define SBNOBJ_COMMON_CRTHitT0TaggingInfo_hh_

// C/C++ standard libraries
#include <limits>
#include "larcorealg/Geometry/GeometryCore.h"
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"
// -----------------------------------------------------------------------------
namespace sbn::crt { 
  /// @brief How was the track fitted when matched with a CRT hit.

  enum class CRTTaggingMethod {
    crtHits = 0, ///< matching performed using single CRT Hits 
    crtTracks = 1 ///< matching performed using CRTTracks
  };

  enum class CRTTaggingTrackFit { 
    pca = 0, ///< Track fitted with PCA method
    startEnd = 1, ///< Track fitted from Start-End vector
    kalman = 2, ///< Track fitted using Kalman Filter
    others = 9 ///< Track direction evaluated in other mehods
  };
      
  struct CRTHitT0TaggingInfo;
}
/**
 * @brief Additional information on the matching between CRT and TPC tracks.
 * 
 */
struct sbn::crt::CRTHitT0TaggingInfo {
  
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
  // to add a notation "Hit" in the member which matches tracks with single hits.
  // We might at some point do more discussion and see if this can work for both.

  /// Distance of closest approach between track extension and CRT hit [cm]
  double Distance = NoDistance;

  /// Matched CRT Hit sub detector 
  // e.g. ICARUS case: 0 Top, 1 Side, 2 Bottom
  int Sys = NoCRT;

  /// Matched CRT Hit region
  // e.g. ICARUS case: 30-34 Top CRT, 40-48 Side CRT, 50 Bottom CRT
  int Region = NoCRT;

  /// Matched CRT Hit time w.r.t. trigger [ns]
  double Time = NoTime;

  /// Distance distinguished into its components DX, DY, DZ [cm]
  double DeltaX = NoDistance;
  double DeltaY = NoDistance;
  double DeltaZ = NoDistance;

  /// Extrapolated Track Projection Crossing Point onto the CRT Plane
  double CrossX = NoDistance;
  double CrossY = NoDistance;
  double CrossZ = NoDistance;

  /// Fix Coordinate for the CRT Plane
  // e.g. ICARUS case:
  // For Top CRT region 30 Y coordinate is constant: plane=0
  // For Top CRT region 31/32 and Side CRT 40/41/42/43/44/45 X coordinate is constant: plane=1
  // For Top CRT region 33/34 and Side CRT 46/47 Z coordinate is constant: plane=2
  int Plane = NoPlane;

  // PCA Fit Fir Eigenvector
  geo::Vector_t PCAEigenVector = {-1., -1., -1.};

  CRTTaggingTrackFit fitType;
  CRTTaggingMethod  taggingMethod;
  
  // --- END ---- Data members -------------------------------------------------
    
}; // sbn::crt::CRTHitT0TaggingInfo


// -----------------------------------------------------------------------------


#endif // SBNOBJ_COMMON_CRTHitT0TaggingInfo_hh_