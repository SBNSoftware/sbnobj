/**
 * @file   sbnobj/Common/Reco/LightCalo.h
 * @brief  Defines data structures for light calorimetry products.
 * @author Lynn Tung 
 * @date   December 2nd, 2025
 *
 */

#ifndef sbnobj_LightCalo_H
#define sbnobj_LightCalo_H

#include <limits>

namespace sbn{

  /**
   * @brief A simple class to store reconstructed charge, light, and visible energy.
   */

  struct LightCalo {
  public:

    // NaN value to initialize data members
    static constexpr double nan = std::numeric_limits<double>::signaling_NaN();

    /// @name Reconstructed charge, light, and visible energy data members.
    /// @{
    double charge = nan;   ///< Total charge in a reconstructed interaction (recob::Slice) [# of electrons]
    double light  = nan;   ///< Total light  in a reconstructed interaction (recob::Slice + recob::OpFlash) [# of photons]
    double energy = nan;   ///< Total visible energy (sum of charge+light) for a reconstructed interaction [GeV]
    int    bestplane = -1; ///< Plane that was used for the total charge
    /// @}

    /**
     * Default constructor.
     */
    LightCalo() = default;
  };
}

#endif
