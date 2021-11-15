#ifndef MuonTrack_hh_
#define MuonTrack_hh_
#include <cstdint>

#include <vector>

namespace sbnd::comm {
  
  struct MuonTrack{

    int32_t t0_us; 
                           
    float x1_pos;
    float y1_pos;
    float z1_pos;
    float x2_pos;
    float y2_pos;
    float z2_pos;

    float theta_xz;
    float theta_yz;

    uint8_t tpc; 
    int type;

    MuonTrack() {}
    
  };
  
} // namespace sbnd::comm

#endif
