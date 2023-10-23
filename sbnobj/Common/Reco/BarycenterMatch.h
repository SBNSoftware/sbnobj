/**
 * @file   sbnobj/Common/Reco/BarycenterMatch.h
 * @brief  Container for the result of matching reconstructed OpFlashes with Pandora charge slices via the barycenter method
 * @author Jack Smedley (jsmedley@fnal.gov)
 * @date   June 21, 2023
 * 
 */

#include <limits>
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"


#ifndef BarycenterMatch_H
#define BarycenterMatch_H

namespace sbn {

  class BarycenterMatch {
  public:

  /// NaN value to initialize data members
  static constexpr float fDefault = std::numeric_limits<float>::signaling_NaN();

  /// Data members related to the slice barycetner determination
  float        fChargeTotal        { fDefault };                     ///< Total charge in slice contributing to barycenter
  float        fChargeCenterXLocal { fDefault };                     ///< Weighted mean X position of spacepoints, measured with respect to the cathode (cm)
  geo::Point_t fChargeCenter       { fDefault, fDefault, fDefault }; ///< Weighted mean spacepoint position in X,Y,Z (cm)
  geo::Point_t fChargeWidth        { fDefault, fDefault, fDefault }; ///< Weighted standard devitation of spacepoint position in X,Y,Z (cm)

  /// Data members related to matched recob::OpFlash, also reachable by association 
  float        fFlashTime          { fDefault };                     ///< Matched OpFlash time (us)
  float        fFlashFirstHit      { fDefault };                     ///< Time of first OpHit in matched OpFlash (us)
  float        fFlashPEs           { fDefault };                     ///< Total PEs in matched flash
  float        fFlashAsymmetry     { fDefault };                     ///< East-West asymmetry of PEs in matched flash
  geo::Point_t fFlashCenter        { fDefault, fDefault, fDefault }; ///< Weighted mean ophit position in Y,Z (cm)
  geo::Point_t fFlashWidth         { fDefault, fDefault, fDefault }; ///< Weighted standard devitation of ophit position in Y,Z (cm)


  /// Data members related to quality of match
  float        fDeltaY             { fDefault };                     ///< abs( Matched flash Y center - charge Y center ) (cm)
  float        fDeltaZ             { fDefault };                     ///< abs( Matched flash Z cetner - charge Z center ) (cm)
  float        fRadius             { fDefault };                     ///< Hypotenuse of DeltaY and DeltaZ, PARAMETER MINIMIZED BY MATCHING (cm)
  float        fDeltaT             { fDefault };                     ///< abs( Matched flash time - anab::T0 ) when available (us)
  float        fOverlapY           { fDefault };                     ///< Spacial overlap of flash and charge centroids in Y [>0] OR distance apart if no overlap [<0] (cm)
  float        fOverlapZ           { fDefault };                     ///< Spacial overlap of flash and charge centroids in Z [>0] OR distance apart if no overlap [<0] (cm)
  float        fDeltaZ_Trigger     { fDefault };                     ///< abs( Triggering flash Z cetner - charge Z center ) (cm)

  };
}

#endif
