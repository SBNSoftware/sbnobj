#ifndef ToF_hh_
#define ToF_hh_

#include <cstdint>
#include <string>

using namespace std;

namespace sbnd::ToF{
  
struct ToF {
      float tof = -9999;
      bool frm_trk = false;
      bool frm_hit = false;
      float crt_time = -9999; 
      float pmt_time = -9999;
      std::string crt_tagger = "N/A";
      int crt_hit_id = -9999;
      int crt_trk_id = -9999;
      int pmt_hit_id = -9999;
      int pmt_flash_id = -9999;
      int flash_tpc_id = -9999;
};

}

#endif
