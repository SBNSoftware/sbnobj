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

#include "TVector3.h"
#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <iostream>

namespace sbn::crt {

    struct CRTHit{

      std::vector<uint8_t> feb_id; ///< FEB address
      std::map< uint8_t, std::vector<std::pair<int,float> > > pesmap; ///< Saves signal hit information (FEB, local-channel and PE) .
      float         peshit; ///< Total photo-electron (PE) in a crt hit.

      uint64_t       ts0_s; ///< Second-only part of timestamp T0.
      double    ts0_s_corr; ///< [Honestly, not sure at this point, it was there since long time (BB)]

      double        ts0_ns; ///< Timestamp T0 (from White Rabbit), in UTC absolute time scale in nanoseconds from the Epoch.
      double   ts0_ns_corr; ///< [Honestly, not sure at this point, it was there since long time (BB)]         Used as a placeholder for the t1 difference between strips (Henry 10.10.2022)
      double        ts1_ns; ///< Timestamp T1 ([signal time w.r.t. Trigger time]), in UTC absolute time scale in nanoseconds from the Epoch.

      int            plane; ///< Name of the CRT wall (in the form of numbers).

      float          x_pos; ///< position in x-direction (cm).
      float          x_err; ///< position uncertainty in x-direction (cm).
      float          y_pos; ///< position in y-direction (cm).
      float          y_err; ///< position uncertainty in y-direction (cm).
      float          z_pos; ///< position in z-direction (cm).
      float          z_err; ///< position uncertainty in z-direction (cm).

      std::string   tagger; ///< Name of the CRT wall (in the form of strings).
      uint32_t    channel0; ///< SiPM channel from one of the SiPMs in strip 0.
      uint32_t    channel1; ///< SiPM channel from one of the SiPMs in strips1 1.

      std::array<uint16_t, 4>  raw_adcs; ///< The 4 ADC values contributing to the 3D hit
      std::array<uint16_t, 4>      adcs; ///< The 4 ADC values contributing to the 3D hit (pedestal subtracted)
      std::array<uint16_t, 4> corr_adcs; ///< The 4 ADC values contributing to the 3D hit, following corrections for attenuation along strip

      CRTHit() {}
      CRTHit(const std::vector<uint8_t> &_feb_id, const double &_pe, const double &_t0, const double &_t1, const double &_diff, const uint64_t _ts0_s,
	     const TVector3 &_pos, const TVector3 &_err, const std::string &_tagger, const uint32_t &_channel0, const uint32_t &_channel1, const std::array<uint16_t, 4> _raw_adcs,
	     const std::array<uint16_t, 4> _adcs, const std::array<uint16_t, 4> _corr_adcs)
	: feb_id(_feb_id)
	, peshit(_pe)
	, ts0_s(_ts0_s)
	, ts0_ns(_t0)
	, ts0_ns_corr(_diff)
	, ts1_ns(_t1)
	, x_pos(_pos.X())
	, x_err(_err.X())
	, y_pos(_pos.Y())
	, y_err(_err.Y())
	, z_pos(_pos.Z())
	, z_err(_err.Z())
	, tagger(_tagger)
	, channel0(_channel0)
	, channel1(_channel1)
	, raw_adcs(_raw_adcs)
	, adcs(_adcs)
	, corr_adcs(_corr_adcs)
      {}

      int64_t ts0() const { return static_cast<int64_t>(ts0_s) * 1'000'000'000LL + static_cast<int64_t>(ts0_ns); }
      int64_t ts1() const { return static_cast<int64_t>(ts0_s) * 1'000'000'000LL + static_cast<int64_t>(ts1_ns); }
    };

} // namespace sbn::crt

#endif
