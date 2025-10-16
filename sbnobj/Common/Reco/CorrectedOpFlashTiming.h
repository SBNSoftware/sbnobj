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
  float        OpFlashT0             { fDefault };                   ///< | OpFlash Time wrt RWM time | (ns)
  float        UpstreamTime_lightonly             { fDefault };      ///< | Nu upstream wall time reconstructed using light only | (ns)
  float        UpstreamTime_tpczcorr             { fDefault };       ///< | Nu upstream wall time reconstructed using light and Z from tpc vertex | (ns)
  float        UpstreamTime_propcorr_tpczcorr    { fDefault };       ///< | Nu upstream wall time reconstructed using light propagation correction from tpc information and z correction from tpc vertex | (ns)
  
  /// @}

  /// @name Data members related to the slice-flash match
  /// @{
  float        FMScore             { fDefault };                   ///< | OpFlash Time wrt RWM time | (ns)

  /// @}

  /// @name Data members related to the slice match
  /// @{
  float        SliceNuScore             { fDefault };                   ///< | OpFlash Time wrt RWM time | (ns)

  /// @}

  };
}

#endif
