#ifndef sbncode_NuMISpillInfo_H
#define sbncode_NuMISpillInfo_H

/*
  NuMI spill information for POT accounting work (work in progress)
*/

#include <vector>

namespace sbn {
  class NuMISpillInfo {
  public:
    std::vector< double > HP121;
    std::vector< double > VP121;
    std::vector< double > HPTGT;
    std::vector< double > VPTGT;
    std::vector< double > HITGT;
    std::vector< double > VITGT; 
    std::vector< double > MTGTDS; //MULTIWIRES
    float HRNDIR; // horn polarity (based on sign)
    float NSLINA; // horn current /4 
    float NSLINB; // horn current /4  
    float NSLINC; // horn current /4 
    float NSLIND; // horn current /4 
    float TRTGTD;
    float TR101D;
  };
}

#endif
