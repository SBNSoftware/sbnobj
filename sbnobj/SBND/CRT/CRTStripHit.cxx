#ifndef SBND_CRTSTRIPHIT_CXX
#define SBND_CRTSTRIPHIT_CXX

#include "sbnobj/SBND/CRT/CRTStripHit.hh"

#include <limits>

namespace sbnd {

  namespace crt {

    CRTStripHit::CRTStripHit()
      : fChannel      (std::numeric_limits<uint32_t>::max())
      , fTs0          (std::numeric_limits<double>::lowest())
      , fTs1          (std::numeric_limits<double>::lowest())
      , fUnixS        (std::numeric_limits<uint32_t>::max())
      , fPos          (std::numeric_limits<double>::lowest())
      , fErr          (std::numeric_limits<double>::lowest())
      , fADC1         (std::numeric_limits<uint16_t>::max())
      , fADC2         (std::numeric_limits<uint16_t>::max())
      , fSaturated1   (false)
      , fSaturated2   (false)
    {}

    CRTStripHit::CRTStripHit(uint32_t _channel, double _ts0, double _ts1, uint32_t _s, double _pos,
                             double _err, uint16_t _adc1, uint16_t _adc2, uint16_t _saturation_level)
      : fChannel      (_channel)
      , fTs0          (_ts0)
      , fTs1          (_ts1)
      , fUnixS        (_s)
      , fPos          (_pos)
      , fErr          (_err)
      , fADC1         (_adc1)
      , fADC2         (_adc2)
    {
      fSaturated1 = fADC1 >= _saturation_level;
      fSaturated2 = fADC2 >= _saturation_level;
    }

    CRTStripHit::CRTStripHit(uint32_t _channel, double _ts0, double _ts1, uint32_t _s, double _pos,
                             double _err, uint16_t _adc1, uint16_t _adc2, bool _saturated1, bool _saturated2)
      : fChannel      (_channel)
      , fTs0          (_ts0)
      , fTs1          (_ts1)
      , fUnixS        (_s)
      , fPos          (_pos)
      , fErr          (_err)
      , fADC1         (_adc1)
      , fADC2         (_adc2)
      , fSaturated1   (_saturated1)
      , fSaturated2   (_saturated2)
    {}

    CRTStripHit::~CRTStripHit() {}

    uint32_t CRTStripHit::Channel() const { return fChannel; }
    double   CRTStripHit::Ts0() const { return fTs0; }
    double   CRTStripHit::Ts1() const { return fTs1; }
    uint32_t CRTStripHit::UnixS() const { return fUnixS; }
    double   CRTStripHit::Pos() const { return fPos; }
    double   CRTStripHit::Error() const { return fErr; }
    uint16_t CRTStripHit::ADC1() const { return fADC1; }
    uint16_t CRTStripHit::ADC2() const { return fADC2; }
    bool     CRTStripHit::Saturated1() const { return fSaturated1; }
    bool     CRTStripHit::Saturated2() const { return fSaturated2; }
  }
}

#endif
