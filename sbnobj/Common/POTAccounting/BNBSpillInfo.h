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
    //typedef enum triggertype { kBNB, kEXT, kUnbiased, kNUMI } TriggerType; //!< Which beamline are we looking at
    
    unsigned long int spill_time_s; //!< The IFDB Beam Spill Time, unit sec
    unsigned long int spill_time_ns; //!< The IFDB Beam Spill Time, unit nsec

    unsigned int event;
        
    //BeamQuaility 
    //quality//BNB
    float FOM; //Figure of Merit for BNB


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

    float VP873; //units mm; 
    float HP875Offset;//units mm
    float VP875Offset;//units mm
    float VP873Offset;//units mm
    float HPTG1Offset;//units mm
    float HPTG2Offset;//units mm
    float VPTG1Offset;//units mm
    float VPTG2Offset;//units mm


    
    // https://cdcvs.fnal.gov/redmine/projects/ubraw/repository/revisions/master/entry/ubraw/BeamDAQ/MWRData.cpp
    std::vector< int > M875BB; //!< Multiwire station before Mag 875...?
    std::vector< int > M876BB; //!< Multiwire station after Mag 875...?
    std::vector< int > MMBTBB; //!< Multiwire station at the target station, 
    
    float M875BB_spill_time_diff; //!< the time difference between M875BB and the matched spill
    float M876BB_spill_time_diff; //!< the time difference between M876BB and the matched spill
    float MMBTBB_spill_time_diff; //!< the time difference between MMBTBB and the matched spill

    double POT() const{return TOR875;}
   

    
  };
} // end namespace sbn

#endif
