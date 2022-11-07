#ifndef SBND_CRTSTRIPHIT_CXX
#define SBND_CRTSTRIPHIT_CXX

#include "sbnobj/SBND/CRT/CRTStripHit.hh"

namespace sbnd {

  namespace crt {

    CRTStripHit::CRTStripHit()
      : channel      (0)
      , ts0          (0)
      , ts1          (0)
      , s            (0)
      , pos          (0)
      , err          (0)
      , adc1         (0)
      , adc2         (0)
      , xyz          (0, 0, 0)
      , exyz         (0, 0, 0)
    {}

    CRTStripHit::CRTStripHit(uint32_t _channel, uint32_t _ts0, uint32_t _ts1, uint32_t _s, double _pos,
			     double _err, uint16_t _adc1, uint16_t _adc2, TVector3 _xyz, TVector3 _exyz)
      : channel      (_channel)
      , ts0          (_ts0)
      , ts1          (_ts1)
      , s            (_s)
      , pos          (_pos)
      , err          (_err)
      , adc1         (_adc1)
      , adc2         (_adc2)
      , xyz          (_xyz)
      , exyz         (_exyz)
    {}

    CRTStripHit::~CRTStripHit() {}

    uint32_t CRTStripHit::Channel() const { return channel; }
    uint32_t CRTStripHit::Ts0() const { return ts0; }
    uint32_t CRTStripHit::Ts1() const { return ts1; }
    uint32_t CRTStripHit::UnixS() const { return s; }
    double   CRTStripHit::Pos() const { return pos; }
    double   CRTStripHit::Error() const { return err; }
    uint16_t CRTStripHit::ADC1() const { return adc1; }
    uint16_t CRTStripHit::ADC2() const { return adc2; }
    TVector3 CRTStripHit::XYZ() const { return xyz; }
    TVector3 CRTStripHit::XYZ_Error() const { return exyz; }
  }
}

#endif
