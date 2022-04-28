#ifndef sbncode_NuMISpillInfo_H
#define sbncode_NuMISpillInfo_H

/*
  NuMI spill information for POT accounting work (work in progress)
*/

#include <vector>

namespace sbn {
  class NuMISpillInfo {
  public:
    // In all lists -- the first is the average of a couple bunches,
    // then the last 6 are the elements per-bunch
    std::vector< double > HP121; //!< List of Horizontal position at start per-bunch
    std::vector< double > VP121; //!< List of Vertical position at start per-bunch
    std::vector< double > HPTGT; //!< List of Horizontal position at target per-bunch
    std::vector< double > VPTGT; //!< List of Vertical position at target per-bunch
    std::vector< double > HITGT; //!< List of Horizontal-Monitor intensity at target per-bunch
    std::vector< double > VITGT;  //!< List of Vertical-Monitor intensity at tartget per bunch
    std::vector< double > MTGTDS; //MULTIWIRES
    float HRNDIR; // horn polarity (based on sign)
    float NSLINA; // horn current /4 
    float NSLINB; // horn current /4  
    float NSLINC; // horn current /4 
    float NSLIND; // horn current /4 
    float TRTGTD; //!< Best monitored POT at Target
    float TR101D; //!< Best monitored POT at Start
    float TORTGT; //!< Other monitored POT at Target
    float TOR101; //!< Other monitored POT at Start
    float time; //!< Time of device used to lookup spill

    unsigned long int spill_time_s; //!< The IFDB Beam Spill Time, unit sec
    unsigned long int spill_time_ns; //!< The IFDB Beam Spill Time, unit nsec

    unsigned int event;
    unsigned int daq_gates;

    double POT() const{return TRTGTD;}
  };
}

#endif
