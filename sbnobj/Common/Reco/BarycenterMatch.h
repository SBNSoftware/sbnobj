/**
 * @file   sbnobj/Common/Reco/BarycenterMatch.h
 * @brief  Container for the result of matching reconstructed OpFlashes with Pandora charge slices via the barycenter method
 * @author Jack Smedley (jsmedley@fnal.gov)
 * @date   June 21, 2023
 * 
 */

#include <limits>
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"


#ifndef SBNOBJ_COMMON_RECO_BARYCENTERMATCH_H
#define SBNOBJ_COMMON_RECO_BARYCENTERMATCH_H

namespace sbn {

  class BarycenterMatch {
  public:

  /// NaN value to initialize data members
  static constexpr float fDefault = std::numeric_limits<float>::signaling_NaN();

  /// Data members related to the slice barycetner determination
  float        chargeTotal        { fDefault };                     ///< Total charge in slice contributing to barycenter
  float        chargeCenterXLocal { fDefault };                     ///< Weighted mean X position of spacepoints, measured with respect to the cathode (cm)
  geo::Point_t chargeCenter       { fDefault, fDefault, fDefault }; ///< Weighted mean spacepoint position in X,Y,Z (cm)
  geo::Point_t chargeWidth        { fDefault, fDefault, fDefault }; ///< Weighted standard devitation of spacepoint position in X,Y,Z (cm)

  /// Data members related to matched recob::OpFlash, also reachable by association 
  float        flashTime          { fDefault };                     ///< Matched OpFlash time (us)
  float        flashFirstHit      { fDefault };                     ///< Time of first OpHit in matched OpFlash (us)
  float        flashPEs           { fDefault };                     ///< Total PEs in matched flash
  float        flashAsymmetry     { fDefault };                     ///< East-West asymmetry of PEs in matched flash
  geo::Point_t flashCenter        { fDefault, fDefault, fDefault }; ///< Weighted mean ophit position in X,Y,Z [no meaingful X info for ophits] (cm)
  geo::Vector_t flashWidth        { fDefault, fDefault, fDefault }; ///< Weighted standard devitation of ophit position in X,Y,Z [no meaingful X info for ophits] (cm)


  /// Data members related to quality of match
  float        deltaY             { fDefault };                     ///< abs( Matched flash Y center - charge Y center ) (cm)
  float        deltaZ             { fDefault };                     ///< abs( Matched flash Z cetner - charge Z center ) (cm)
  float        radius             { fDefault };                     ///< Hypotenuse of DeltaY and DeltaZ, PARAMETER MINIMIZED BY MATCHING (cm)
  float        deltaT             { fDefault };                     ///< abs( Matched flash time - anab::T0 ) when available (us)
  float        overlapY           { fDefault };                     ///< Spacial overlap of flash and charge centroids in Y [>0] OR distance apart if no overlap [<0] (cm)
  float        overlapZ           { fDefault };                     ///< Spacial overlap of flash and charge centroids in Z [>0] OR distance apart if no overlap [<0] (cm)
  float        deltaZ_Trigger     { fDefault };                     ///< abs( Triggering flash Z cetner - charge Z center ) (cm)

  };
}

#endif
