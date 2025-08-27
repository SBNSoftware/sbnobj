/**
 * @file   sbnobj/SBND/OpFlashTiming/CorrectedOpFlashTiming.h
 * @author Alejandro Sánchez-Castillo (acastill@fnal.gov)
 * @date   Aug 27, 2025
 * 
 */

#include <limits>


#ifndef SBNOBJ_SBND_OPFLASHTIMING_CORRECTEDOPFLASHTIMING_H
#define SBNOBJ_SBND_OPFLASHTIMING_CORRECTEDOPFLASHTIMING_H

namespace sbnd::OpFlashTiming {
  /**
   * @brief OpFlash time information corrected for proper BNB timing reconstruction.
   */
  class CorrectedOpFlashTiming {
  public:

  // NaN value to initialize data members
  static constexpr float fDefault = std::numeric_limits<float>::signaling_NaN();

  /// @name Data members related to quality of match
  /// @{
  float        OpFlashT0             { fDefault };                   ///< | OpFlash Time wrt RWM time | (ns)
  float        UpstreamTime_lightonly             { fDefault };      ///< | Nu upstream wall time reconstructed using light only | (ns)
  float        UpstreamTime_tpczcorr             { fDefault };       ///< | Nu upstream wall time reconstructed using light and Z from tpc vertex | (ns)
  float        UpstreamTime_propcorr             { fDefault };       ///< | Nu upstream wall time reconstructed using light propagation correction from tpc information | (ns)
  float        UpstreamTime_propcorr_tpczcorr    { fDefault };       ///< | Nu upstream wall time reconstructed using light propagation correction from tpc information and z correction from tpc vertex | (ns)

  /// @}

  };
}

#endif
