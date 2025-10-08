/**
 * @file   sbnobj/SBND/Timing/TimingInfo.cxx
 * @brief  Defines data structures for SBND Timing Product (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *       
 */

#ifndef SBND_TIMINGINFO_CXX
#define SBND_TIMINGINFO_CXX

#include "sbnobj/SBND/Timing/TimingInfo.hh"

namespace sbnd::timing {

  TimingInfo::TimingInfo(uint64_t rawDAQHeaderTimestamp, uint64_t tdcCrtt1, uint64_t tdcBes, uint64_t tdcRwm, uint64_t tdcEtrig, uint64_t hltCrtt1, uint64_t hltEtrig, uint64_t hltBeamGate)
    : fRawDAQHeaderTimestamp(rawDAQHeaderTimestamp)
    ,  fTdcCrtt1(tdcCrtt1)
    ,  fTdcBes(tdcBes)
    ,  fTdcRwm(tdcRwm)
    ,  fTdcEtrig(tdcEtrig)
    ,  fHltCrtt1(hltCrtt1)
    ,  fHltEtrig(hltEtrig) 
    ,  fHltBeamGate(hltBeamGate)
    {}
}

#endif
