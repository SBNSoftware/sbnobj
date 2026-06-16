/**
 * @file   sbnobj/Common/Reco/CorrectedOpFlashTiming.h
 * @author Alejandro Sánchez-Castillo (acastill@fnal.gov)
 * @date   Aug 27, 2025
 * 
 */

#include <limits>


#ifndef SBNOBJ_COMMON_RECO_CORRECTEDOPFLASHTIMING_H
#define SBNOBJ_COMMON_RECO_CORRECTEDOPFLASHTIMING_H

namespace sbn {
  /**
   * @brief OpFlash time information corrected for proper BNB timing reconstruction.
   */
  class CorrectedOpFlashTiming {
  public:

  // NaN value to initialize data members
  static constexpr float fDefault = std::numeric_limits<float>::signaling_NaN();

  /// @name Corrected OpFlash Times
  /// @{
  float        OpFlashT0             { fDefault };                   ///< | OpFlash Time wrt RWM time | (us)
  float        NuToFLight             { fDefault };      ///< | Nu ToF using light only | (us)
  float        NuToFCharge             { fDefault };       ///< | Nu ToF Z from tpc vertex | (us)
  float        OpFlashT0Corrected    { fDefault };       ///< | OpFlash Time wrt RWM time after light propagation corrections | (us)
  float        ParticlePropagationTime{ fDefault }; ///< | Average particle propagation time from vertex to emission point | (us)
  float        PhotonPropagationTime{ fDefault }; ///< | Average photon propagation time from emission point to detection point| (us)
  /// @}
  
  };
}

#endif
