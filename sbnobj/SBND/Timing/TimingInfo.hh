/**
 * \brief Data product to store important timestamps
 *
 * \author Vu Chi Lan Nguyen (vclnguyen@ucsb.edu)
 * To save important timing info in unix timestamp format
 * Products made by FrameShift module                    
 */

#ifndef SBND_TIMINGINFO_HH
#define SBND_TIMINGINFO_HH

#include <stdint.h>
#include <string>
#include <array>
#include <limits> // for std::numeric_limits

namespace sbnd::timing {

  class TimingInfo {

    uint64_t fRawDAQHeaderTimestamp;
    uint64_t fTdcCrtt1;
    uint64_t fTdcBes;
    uint64_t fTdcRwm;
    uint64_t fTdcEtrig; //Global frame for timingType = 0
    uint64_t fHltCrtt1;
    uint64_t fHltEtrig; //Global frame for timingType = 1
    uint64_t fHltBeamGate;

   public:

    TimingInfo();

    TimingInfo(uint64_t _rawDAQHeaderTimestamp, uint64_t _tdcCrtt1, uint64_t _tdcBes, uint64_t _tdcRwm, uint64_t _tdcEtrig, uint64_t _hltCrtt1, uint64_t _hltEtrig, uint64_t _hltBeamGate);

    virtual ~TimingInfo();

    uint64_t RawDAQHeaderTimestamp() const;
    uint64_t TdcCrtt1() const;
    uint64_t TdcBes() const;
    uint64_t TdcRwm() const;
    uint64_t TdcEtrig() const; //Global frame for timingType = 0
    uint64_t HltCrtt1() const;
    uint64_t HltEtrig() const; //Global frame for timingType = 1
    uint64_t HltBeamGate() const;
 
    void SetRawDAQHeaderTimestamp(uint64_t timestamp);
    void SetTdcCrtt1(uint64_t timestamp);
    void SetTdcBes(uint64_t timestamp);
    void SetTdcRwm(uint64_t timestamp);
    void SetTdcEtrig(uint64_t timestamp); //Global frame for timingType = 0
    void SetHltCrtt1(uint64_t timestamp);
    void SetHltEtrig(uint64_t timestamp); //Global frame for timingType = 1
    void SetHltBeamGate(uint64_t timestamp);
  };
}

#endif
