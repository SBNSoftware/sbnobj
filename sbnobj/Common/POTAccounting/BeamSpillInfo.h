#ifndef sbncode_BeamSpillInfo_HH
#define sbncode_BeamSpillInfo_HH

#include <vector>

namespace sbn {
  class BeamSpillInfo {
  public:
    //typedef enum triggertype { kBNB, kEXT, kUnbiased, kNUMI } TriggerType; //!< Which beamline are we looking at
    
    unsigned long int spill_time_s; //!< The IFDB Beam Spill Time, unit sec
    unsigned long int spill_time_ns; //!< The IFDB Beam Spill Time, unit nsec
 
    //BeamQuaility 
    //quality//EXT
    //int EXTGates;

    //quality//BNB
    
    double TOR860; //!< Toroid before Mag 875, units e12 Protons
    double TOR875; //!< Toroid after Mag 875, units e12 Protons
    
    double LM875A; //!< Loss Monitor before the RWM, unit R/s
    double LM875B; //!< Loss Monitor after the RWM, unit R/s
    double LM875C; //!< Loss Monitor after the RWM, unit R/s
    double HP875; //!< Horizontal Position Monitor after Mag 875, units mm
    double VP875; //!< Verticle Position Monitor after Mag 875, units mm

    double HPTG1; //!< Horizontal Position Monitor at Target Station 1, units mm 
    double VPTG1; //!< Horizontal Position Monitor at Target Station 1, units mm

    double HPTG2; //!< Horizontal Position Monitor at Target Station 2, closest to target, units mm
    double VPTG2; //!< Horizontal Position Monitor at Target Station 2, closest to target, units mm
    
    double BTJT2; //!< Temperature of air exiting target, units Deg C

    double THCURR; //!< Current applied to Horn, units kiloAmperes 
    
    // https://cdcvs.fnal.gov/redmine/projects/ubraw/repository/revisions/master/entry/ubraw/BeamDAQ/MWRData.cpp
    std::vector< int > M875BB; //!< Multiwire station before Mag 875...?
    std::vector< int > M876BB; //!< Multiwire station after Mag 875...?
    std::vector< int > MMBTBB; //!< Multiwire station at the target station, 

    //quality//numi
    /* add 2 toroids, TOR101, TORTGT */
    /*
    std::vector< double > HP121;
    std::vector< double > VP121;
    std::vector< double > HPTGT;
    std::vector< double > VPTGT;
    std::vector< double > HITGT;
    std::vector< double > VITGT; 
    std::vector< double > MTGTDS; //MULTIWIRES
    double HRNDIR; // horn polarity (based on sign)
    double NSLINA; // horn current /4 
    double NSLINB; // horn current /4  
    double NSLINC; // horn current /4 
    double NSLIND; // horn current /4 
    */
  };
} // end namespace sbn

#endif
