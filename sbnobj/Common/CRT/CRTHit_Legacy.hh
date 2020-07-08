/**
 * \class CRTData
 *
 * \ingroup crt
 *
 * \brief CRT Hit Info
 *
 * \author $Author: David Lorca $
 *
 * NOTE! THIS IS PURELY LEGACY HEADERS FOR THE PREV NAMESPACES! 
 * DO NOT MAKE CHANGES HERE! GO TO CRTTrack.hh
 *
 *
 */

#ifndef CRTHit_LEGACY_hh_
#define CRTHit_LEGACY_hh_

#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <utility>

namespace sbnd {
namespace crt {

    struct CRTHit{

      std::vector<uint8_t> feb_id;
      std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap;
      float peshit;
     
      uint32_t ts0_s;
      int8_t ts0_s_corr;
      
      uint32_t ts0_ns;
      int32_t ts0_ns_corr;
      int32_t ts1_ns;
     
      int plane;

      float x_pos;
      float x_err;
      float y_pos;
      float y_err;
      float z_pos;
      float z_err;

      std::string tagger;

      CRTHit() {}

    };

} // namespace crt
} // namespace sbnd

namespace icarus {
namespace crt {

    struct CRTHit{

      std::vector<uint8_t> feb_id;
      std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap;
      float peshit;
     
      uint32_t ts0_s;
      int8_t ts0_s_corr;
      
      uint32_t ts0_ns;
      int32_t ts0_ns_corr;
      int32_t ts1_ns;
     
      int plane;

      float x_pos;
      float x_err;
      float y_pos;
      float y_err;
      float z_pos;
      float z_err;

      std::string tagger;

      CRTHit() {}

    };

} // namespace crt
} // namespace icarus

#endif
