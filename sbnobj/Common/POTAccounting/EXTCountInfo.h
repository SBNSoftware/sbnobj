#ifndef sbncode_EXTCountInfo_H
#define sbncode_EXTCountInfo_H

/**

 * @file sbnobj/Common/POTAccounting/EXTCountInfo.h
 * @author Joseph Zennamo, FNAL (jaz8600@fnal.gov)
 */

#include <vector>

namespace sbn {
  class EXTCountInfo {
  public:

    int gates_since_last_trigger;
    bool isBNBOffBeam;
    bool isNuMIOffBeam;
    bool isMajority; //< Does trigger pass scintillation-based trigger?
    bool isMinBias;  //< Is this a non-scintillation-based trigger?

  };
} // end namespace sbn

#endif
