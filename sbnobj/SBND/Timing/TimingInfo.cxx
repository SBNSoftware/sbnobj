#ifndef SBND_TIMINGINFO_CXX
#define SBND_TIMINGINFO_CXX

#include "sbnobj/SBND/Timing/TimingInfo.hh"

namespace sbnd::timing {

  TimingInfo::TimingInfo()
    : fRawDAQHeaderTimestamp(0)
    ,  fTdcCrtt1(0)
    ,  fTdcBes(0)
    ,  fTdcRwm(0)
    ,  fTdcEtrig(0)
    ,  fHltCrtt1(0)
    ,  fHltEtrig(0) 
    ,  fHltBeamGate(0)
    {}

  TimingInfo::TimingInfo(uint64_t _rawDAQHeaderTimestamp, uint64_t _tdcCrtt1, uint64_t _tdcBes, uint64_t _tdcRwm, uint64_t _tdcEtrig, uint64_t _hltCrtt1, uint64_t _hltEtrig, uint64_t _hltBeamGate)
    : fRawDAQHeaderTimestamp(_rawDAQHeaderTimestamp)
    ,  fTdcCrtt1(_tdcCrtt1)
    ,  fTdcBes(_tdcBes)
    ,  fTdcRwm(_tdcRwm)
    ,  fTdcEtrig(_tdcEtrig)
    ,  fHltCrtt1(_hltCrtt1)
    ,  fHltEtrig(_hltEtrig) 
    ,  fHltBeamGate(_hltBeamGate)
    {}

  TimingInfo::~TimingInfo() {}

  uint64_t TimingInfo::RawDAQHeaderTimestamp() const { return fRawDAQHeaderTimestamp; }
  uint64_t TimingInfo::TdcCrtt1() const { return fTdcCrtt1; }
  uint64_t TimingInfo::TdcBes() const { return fTdcRwm; }
  uint64_t TimingInfo::TdcRwm() const { return fTdcRwm; }
  uint64_t TimingInfo::TdcEtrig() const { return fTdcEtrig; }
  uint64_t TimingInfo::HltCrtt1() const { return fHltCrtt1; }
  uint64_t TimingInfo::HltEtrig() const { return fHltEtrig; }
  uint64_t TimingInfo::HltBeamGate() const { return fHltBeamGate; }

  void TimingInfo::SetRawDAQHeaderTimestamp(uint64_t _timestamp){ fRawDAQHeaderTimestamp = _timestamp; }
  void TimingInfo::SetTdcCrtt1(uint64_t _timestamp){ fTdcCrtt1 = _timestamp; }
  void TimingInfo::SetTdcBes(uint64_t _timestamp){ fTdcBes = _timestamp; }
  void TimingInfo::SetTdcRwm(uint64_t _timestamp){ fTdcRwm = _timestamp; }
  void TimingInfo::SetTdcEtrig(uint64_t _timestamp){ fTdcEtrig = _timestamp; }
  void TimingInfo::SetHltCrtt1(uint64_t _timestamp){ fHltCrtt1 = _timestamp; }
  void TimingInfo::SetHltEtrig(uint64_t _timestamp){ fHltEtrig = _timestamp; }
  void TimingInfo::SetHltBeamGate(uint64_t _timestamp){ fHltBeamGate = _timestamp; }
}

#endif
