#ifndef MuonTrack_hh_
#define MuonTrack_hh_
#include <cstdint>

#include <vector>
#include <map>

namespace sbnd::comm {
  
  struct MuonTrack{

    std::vector<uint8_t> feb_id;
    std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap;
    float peshit;

    int32_t t0_us; 
                           
    float x1_pos;
    float y1_pos;
    float z1_pos;
    float x2_pos;
    float y2_pos;
    float z2_pos;

    float thetaxz;
    float thetayz;

    uint8_t tpc; 
    bool top;
    bool bottom;
    bool upstream;
    bool downstream;
    bool anode;
    bool cathode;

    MuonTrack() {}
    
  };
  
} // namespace sbnd::comm

#endif
