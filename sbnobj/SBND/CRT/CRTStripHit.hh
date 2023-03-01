/**
 * \class CRTStripHit
 *
 * \brief Product to store 2D CRT "strip hit"
 *
 * \author Henry Lay (h.lay@lancaster.ac.uk)
 *
 */

#ifndef SBND_CRTSTRIPHIT_HH
#define SBND_CRTSTRIPHIT_HH

#include <stdint.h>

namespace sbnd::crt {

  class CRTStripHit {
    
    uint32_t fChannel;      // Channel ID for 1st SiPM
    uint32_t fTs0;          // T0 counter [ns] - Time relative to pulse-per-second
    uint32_t fTs1;          // T1 counter [ns] - Time relative to some beam signal
    uint32_t fUnixS;        // Unixtime of event [s]
    double   fPos;          // Lateral position within strip [cm]
    double   fErr;          // Error on lateral position [cm]
    uint16_t fADC1;         // ADC 1st SiPM
    uint16_t fADC2;         // ADC 2nd SiPM
    bool     fSaturated1;   // Did 1st SiPM record a saturated value?
    bool     fSaturated2;   // Did 2nd SiPM record a saturated value?

  public:

    CRTStripHit();
    
    CRTStripHit(uint32_t _channel, uint32_t _ts0, uint32_t _ts1, uint32_t _s, double _pos,
                double _err, uint16_t _adc1, uint16_t _adc2);

    CRTStripHit(uint32_t _channel, uint32_t _ts0, uint32_t _ts1, uint32_t _s, double _pos,
                double _err, uint16_t _adc1, uint16_t _adc2, bool _saturated1, bool _saturated2);

    virtual ~CRTStripHit();

    uint32_t Channel() const;
    uint32_t Ts0() const;
    uint32_t Ts1() const;
    uint32_t UnixS() const;
    double   Pos() const;
    double   Error() const;
    uint16_t ADC1() const;
    uint16_t ADC2() const;
    bool     Saturated1() const;
    bool     Saturated2() const;
  };
}

#endif
