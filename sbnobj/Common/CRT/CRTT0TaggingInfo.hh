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
namespace sbn::crt { struct CRTT0TaggingInfo; }
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
  
  /// Distance of closest approach between track extension and CRT hit [cm]
  double trackCrtHitDistance = NoDistance;

  /// Matched CRT Hit sub detector 
  // e.g. ICARUS case: 0 Top, 1 Side, 2 Bottom
  int crtSys = NoCRT;

  /// Matched CRT Hit region
  // e.g. ICARUS case: 30-34 Top CRT, 40-48 Side CRT, 50 Bottom CRT
  int crtRegion = NoCRT;

  /// Matched CRT Hit time w.r.t. trigger [ns]
  double crtTime = NoTime;

  /// Distance distinguished into its components DX, DY, DZ [cm]
  double deltaX = NoDistance;
  double deltaY = NoDistance;
  double deltaZ = NoDistance;

  /// Extrapolated Track Projection Crossing Point onto the CRT Plane
  double crossX = NoDistance;
  double crossY = NoDistance;
  double crossZ = NoDistance;

  /// Fix Coordinate for the CRT Plane
  // e.g. ICARUS case:
  // For Top CRT region 30 Y coordinate is constant: plane=0
  // For Top CRT region 31/32 and Side CRT 40/41/42/43/44/45 X coordinate is constant: plane=1
  // For Top CRT region 33/34 and Side CRT 46/47 Z coordinate is constant: plane=2
  int plane=NoPlane;  

  // --- END ---- Data members -------------------------------------------------
    
}; // sbn::crt::CRTT0TaggingInfo


// -----------------------------------------------------------------------------


#endif // SBNOBJ_COMMON_CRTT0TaggingInfo_hh_