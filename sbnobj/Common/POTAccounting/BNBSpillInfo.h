#ifndef sbncode_BNBSpillInfo_H
#define sbncode_BNBSpillInfo_H

/**

 * @file sbnobj/Common/POTAccounting/BNBSpillInfo.h
 * @author Joseph Zennamo, FNAL (jaz8600@fnal.gov)
 */


namespace sbn {

  class BNBSpillInfo {
  public:
    unsigned int event;

    float FOM; // Figure of Merit for BNB

    float TOR860; //!< Toroid before Mag 875, units e12 Protons
    float TOR875; //!< Toroid after Mag 875, units e12 Protons

    float LM875A; //!< Loss Monitor before the RWM, unit R/s
    float LM875B; //!< Loss Monitor after the RWM, unit R/s
    float LM875C; //!< Loss Monitor after the RWM, unit R/s

    float HP873; //!< Horizontal Position Monitor after Mag 873, units mm
    float VP873; //!< Verticle Position Monitor after Mag 873, units mm

    float HP875; //!< Horizontal Position Monitor after Mag 875, units mm
    float VP875; //!< Verticle Position Monitor after Mag 875, units mm

    float THCURR; //!< Current applied to Horn, units kiloAmperes

    // Keep the original multiwire stations from develop (since you removed them)
    float M875HS; //!< Multiwire station after Mag 875, Fit to Horizontal Sigma?
    float M875VS; //!< Multiwire station after Mag 875, Fit to Vertical Sigma?
    float M875HM; //!< Multiwire station after Mag 875, Fit to Horizontal Mean?
    float M875VM; //!< Multiwire station after Mag 875, Fit to Vertical Mean?

    float M876HS; //!< Multiwire station after Mag 876, Fit to Horizontal Sigma?
    float M876VS; //!< Multiwire station after Mag 876, Fit to Vertical Sigma?
    float M876HM; //!< Multiwire station after Mag 876, Fit to Horizontal Mean?
    float M876VM; //!< Multiwire station after Mag 876, Fit to Vertical Mean?

    // And add all your new offsets here:
    float HP875Offset;  // units mm
    float VP875Offset;  // units mm
    float VP873Offset;  // units mm
    float HPTG1Offset;  // units mm
    float HPTG2Offset;  // units mm
    float VPTG1Offset;  // units mm
    float VPTG2Offset;  // units mm

    std::vector<int> M875BB; //!< Multiwire station before Mag 875...?

    float MMBTBB_spill_time_diff; //!< time diff between MMBTBB and matched spill

    double POT() const { return TOR875; }

  };

} // end namespace sbn

#endif
