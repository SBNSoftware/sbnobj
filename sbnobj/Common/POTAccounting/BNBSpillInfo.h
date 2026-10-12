#ifndef sbncode_BNBSpillInfo_H
#define sbncode_BNBSpillInfo_H

/**

 * @file sbnobj/Common/POTAccounting/BNBSpillInfo.h
 * @author Joseph Zennamo, FNAL (jaz8600@fnal.gov)
 */
#include <vector>

namespace sbn {

  class BNBSpillInfo {
  public:

    unsigned long int spill_time_s; //!< The IFDB Beam Spill Time, unit sec
    unsigned long int spill_time_ns; //!< The IFDB Beam Spill Time, unit nsec

    unsigned int event;

    float FOM; ///! Figure of Merit for BNB

    float PreFitFOM; // Figure of Merit for BNB, use prefit horizontal
                     // sigma values (M875HS, M875VS) or (M875HS, M875VS)

    float NoMultiWireFOM; // Figure of Merit for BNB, use scalex=scaley=1
                          // (no multiwire fit) method from microboone

    // Beam-quality result for this spill (sbncode/BeamSpillInfoRetriever/getFOM.h,
    // BNBFOMFill.h): the figure of merit to cut on and how it was obtained.
    // Missing values are -999.
    float FOM_best = -999; //!< best FOM of the spill, in [0, 1]; -999 if none can be formed
    int fom_source = -1; //!< width used for FOM_best: 1/2 fitted M876/M875 profile, 3/4 M876/M875 database width, 5 nominal; -1 no FOM
    unsigned int fom_status = 0; //!< bit mask of `sbn::fomstatus` (getFOM.h): missing inputs, substitutions, recoveries
    float tor_used = -999; //!< intensity used for the FOM, units Protons: TOR860, or TOR875 after a TOR860 drop-out
    float hpos_tgt = -999; //!< horizontal beam position at the target centre, units mm
    float hang_tgt = -999; //!< horizontal beam angle at the target, units mrad
    float vpos_tgt = -999; //!< vertical beam position at the target centre, units mm
    float vang_tgt = -999; //!< vertical beam angle at the target, units mrad
    float tgt_sigx = -999; //!< horizontal beam width at the target used for the FOM, units mm; -999: nominal width
    float tgt_sigy = -999; //!< vertical beam width at the target used for the FOM, units mm; -999: nominal width
    unsigned int fom_version = 0; //!< version of the beam-quality algorithm (`sbn::FOMVersion`); 0: not computed

    float TOR860; //!< Toroid before Mag 875, units e12 Protons
    float TOR875; //!< Toroid after Mag 875, units e12 Protons

    float LM875A; //!< Loss Monitor before the RWM, unit R/s
    float LM875B; //!< Loss Monitor after the RWM, unit R/s
    float LM875C; //!< Loss Monitor after the RWM, unit R/s

    float HP873; //!< Horizontal Position Monitor after Mag 873, units mm
    float VP873; //!< Verticle Position Monitor after Mag 873, units mm

    float HP875; //!< Horizontal Position Monitor after Mag 875, units mm
    float VP875; //!< Verticle Position Monitor after Mag 875, units mm

    float HPTG1; //!< Horizontal Position Monitor at Target Station 1, units mm 
    float VPTG1; //!< Horizontal Position Monitor at Target Station 1, units mm

    float HPTG2; //!< Horizontal Position Monitor at Target Station 2, closest to target, units mm
    float VPTG2; //!< Horizontal Position Monitor at Target Station 2, closest to target, units mm

    float BTJT2; //!< Temperature of air exiting target, units Deg C

    float THCURR; //!< Current applied to Horn, units kiloAmperes 

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


    std::vector< int > M876BB; //!< Multiwire station after Mag 875...?
    std::vector< int > MMBTBB; //!< Multiwire station at the target station, 

    float M875BB_spill_time_diff; //!< the time difference between M875BB and the matched spill
    float M876BB_spill_time_diff; //!< the time difference between M876BB and the matched spill
    float MMBTBB_spill_time_diff; //!< time diff between MMBTBB and matched spill


    double POT() const { return TOR875; }

  };

} // end namespace sbn

#endif
