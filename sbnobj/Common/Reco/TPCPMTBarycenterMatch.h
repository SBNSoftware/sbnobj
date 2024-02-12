/**
 * @file   sbnobj/Common/Reco/TPCPMTBarycenterMatch.h
 * @author Jack Smedley (jsmedley@fnal.gov)
 * @date   June 21, 2023
 * 
 */

#include <limits>
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"


#ifndef SBNOBJ_COMMON_RECO_TPCPMTBARYCENTERMATCH_H
#define SBNOBJ_COMMON_RECO_TPCPMTBARYCENTERMATCH_H

namespace sbn {
  /**
   * @brief Information on matching of a reconstructed TPC object with a optical flash via barycenter matching algorithm.
   */
  class TPCPMTBarycenterMatch {
  public:

  // NaN value to initialize data members
  static constexpr float fDefault = std::numeric_limits<float>::signaling_NaN();

  /// @name Data members related to the slice barycenter determination
  /// @{
  float        chargeTotal        { fDefault };                     ///< Total charge in slice contributing to barycenter (integrated ADC counts)
  float        chargeCenterXLocal { fDefault };                     ///< Weighted mean X position of spacepoints, measured with respect to the cathode (cm)
  geo::Point_t chargeCenter       { fDefault, fDefault, fDefault }; ///< Weighted mean spacepoint position in X,Y,Z (cm)
  geo::Vector_t chargeWidth       { fDefault, fDefault, fDefault }; ///< Weighted standard devitation of spacepoint position in X,Y,Z (cm)
  /// @}


  /// @name Data members related to matched recob::OpFlash, also reachable by association 
  /// @{
  float        flashTime          { fDefault };                     ///< Matched OpFlash time (us)
  float        flashFirstHit      { fDefault };                     ///< Time of first OpHit in matched OpFlash (us)
  float        flashPEs           { fDefault };                     ///< Total PEs in matched flash
  float        flashAsymmetry     { fDefault };                     ///< East-West asymmetry of PEs in matched flash
  geo::Point_t flashCenter        { fDefault, fDefault, fDefault }; ///< Weighted mean ophit position in X,Y,Z [no meaingful X info for ophits] (cm)
  geo::Vector_t flashWidth        { fDefault, fDefault, fDefault }; ///< Weighted standard devitation of ophit position in X,Y,Z [no meaingful X info for ophits] (cm)
  /// @}


  /// @name Data members related to quality of match
  /// @{
  float        deltaY             { fDefault };                     ///< | Matched flash Y center - charge Y center | (cm)
  float        deltaZ             { fDefault };                     ///< | Matched flash Z center - charge Z center | (cm)
  float        radius             { fDefault };                     ///< Hypotenuse of DeltaY and DeltaZ (cm)
  float        deltaT             { fDefault };                     ///< | Matched flash time - anab::T0 | when available (us)
  float        overlapY           { fDefault };                     ///< Spatial overlap of flash and charge centroids in Y [>0] OR distance apart if no overlap [<0] (cm)
  float        overlapZ           { fDefault };                     ///< Spatial overlap of flash and charge centroids in Z [>0] OR distance apart if no overlap [<0] (cm)
  float        deltaZ_Trigger     { fDefault };                     ///< | Triggering flash Z center - charge Z center | (cm)
  float        deltaY_Trigger     { fDefault };                     ///< | Triggering flash Y center - charge Y center | (cm)
  float        radius_Trigger     { fDefault };                     ///< Hypotenuse of DeltaY_Trigger and DeltaZ_Trigger (cm)
  /// @}

  };
}

#endif
