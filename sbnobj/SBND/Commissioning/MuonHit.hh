#ifndef MuonHit_hh_
#define MuonHit_hh_

#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <utility>

namespace    {

    struct MuonHit{

      std::vector<uint8_t> feb_id;
      std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap;
      float peshit;

      uint8_t tpc;

      float x_pos;
      float y_pos;
      float z_pos;


      MuonHit() {}

    };

} // namespace sbnd::comm

#endif