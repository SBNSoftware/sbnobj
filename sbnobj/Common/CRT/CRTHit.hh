/**
 * \class CRTData
 *
 * \ingroup crt
 *
 * \brief CRT Hit Info
 *
 * \author $Author: David Lorca $
 *
 */

#ifndef CRTHit_hh_
#define CRTHit_hh_

#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <utility>

namespace sbn::crt {

    struct CRTHit{

      std::vector<uint8_t> feb_id; ///< FEB address 
      std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap; ///< Saves signal hit information (FEB, local-channel and PE) .
      float         peshit; ///< Total photo-electron (PE) in a crt hit.
     
      uint64_t       ts0_s; ///< Second-only part of timestamp T0.
      int8_t    ts0_s_corr; ///< [Honestly, not sure at this point, it was there since long time (BB)]
      
      uint64_t      ts0_ns; ///< Timestamp T0 (from White Rabbit), in UTC absolute time scale in nanoseconds from the Epoch.
      int8_t   ts0_ns_corr; ///< [Honestly, not sure at this point, it was there since long time (BB)]
      int64_t       ts1_ns; ///< Timestamp T1 ([signal time w.r.t. Trigger time]), in UTC absolute time scale in nanoseconds from the Epoch.
     
      int            plane; ///< Name of the CRT wall (in the form of numbers).

      float          x_pos; ///< position in x-direction (cm).
      float          x_err; ///< position uncertainty in x-direction (cm).
      float          y_pos; ///< position in y-direction (cm).
      float          y_err; ///< position uncertainty in y-direction (cm).
      float          z_pos; ///< position in z-direction (cm).
      float          z_err; ///< position uncertainty in z-direction (cm).

      std::string   tagger; ///< Name of the CRT wall (in the form of strings).

      CRTHit() {}

      int64_t ts0() const { return static_cast<int64_t>(ts0_s) * 1'000'000'000LL + ts0_ns; }
      int64_t ts1() const { return static_cast<int64_t>(ts0_s) * 1'000'000'000LL + ts1_ns; }
    };

} // namespace sbn::crt

#endif
