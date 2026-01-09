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

      static constexpr float kInvalidF = std::numeric_limits<float>::lowest();
      static constexpr double kInvalidD = std::numeric_limits<double>::lowest();

      std::vector<uint8_t> feb_id; ///< FEB address
      std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap; ///< Saves signal hit information (FEB, local-channel and PE) .
      float         peshit{kInvalidF}; ///< Total photo-electron (PE) in a crt hit.

      uint64_t       ts0_s{-1}; ///< Second-only part of timestamp T0.
      double    ts0_s_corr{kInvalidD}; ///< [Honestly, not sure at this point, it was there since long time (BB)]
      double        ts0_ns{kInvalidD}; ///< Timestamp T0 (from White Rabbit), in UTC absolute time scale in nanoseconds from the Epoch.
      double   ts0_ns_corr{kInvalidD}; ///< [Honestly, not sure at this point, it was there since long time (BB)]

      double        ts1_ns{kInvalidD}; ///< Timestamp T1 ([signal time w.r.t. Trigger time]), 

      int            plane{-1}; ///< Name of the CRT wall (in the form of numbers).

      float          x_pos{kInvalidF}; ///< position in x-direction (cm).
      float          x_err{kInvalidF}; ///< position uncertainty in x-direction (cm).
      float          y_pos{kInvalidF}; ///< position in y-direction (cm).
      float          y_err{kInvalidF}; ///< position uncertainty in y-direction (cm).
      float          z_pos{kInvalidF}; ///< position in z-direction (cm).
      float          z_err{kInvalidF}; ///< position uncertainty in z-direction (cm).

      std::string   tagger; ///< Name of the CRT wall (in the form of strings).

      int64_t ts0() const { return static_cast<int64_t>(ts0_s) * 1'000'000'000LL + static_cast<int64_t>(ts0_ns); }
      // T1 is a relative time not a timestamp, so we don't need second-part.
      // nano-second part is enough and we saved entire time there.
      int64_t ts1() const { return static_cast<int64_t>(ts1_ns); }

    };

} // namespace sbn::crt

#endif
