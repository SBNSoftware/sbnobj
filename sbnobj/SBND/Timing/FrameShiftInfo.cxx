/**
 * @file   sbnobj/SBND/Timing/FrameShiftInfo.cxx
 * @brief  Defines data structures for SBND Frame Shift products (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *
 */

#ifndef SBND_FRAMESHIFTINFO_CXX
#define SBND_FRAMESHIFTINFO_CXX

#include "sbnobj/SBND/Timing/FrameShiftInfo.hh"

namespace sbnd::timing {
  FrameShiftInfo::FrameShiftInfo(uint64_t frameCrtt1, uint16_t timingTypeCrtt1, uint16_t timingChannelCrtt1,
                                 uint64_t frameBeamGate, uint16_t timingTypeBeamGate, uint16_t timingChannelBeamGate,
                                 uint64_t frameEtrig, uint16_t timingTypeEtrig, uint16_t timingChannelEtrig,
                                 uint64_t frameDefault,  uint16_t timingTypeDefault, uint16_t timingChannelDefault)
    : fFrameCrtt1(frameCrtt1), fTimingTypeCrtt1(timingTypeCrtt1), fTimingChannelCrtt1(timingChannelCrtt1),
      fFrameBeamGate(frameBeamGate), fTimingTypeBeamGate(timingTypeBeamGate), fTimingChannelBeamGate(timingChannelBeamGate),
      fFrameEtrig(frameEtrig), fTimingTypeEtrig(timingTypeEtrig), fTimingChannelEtrig(timingChannelEtrig),
      fFrameDefault(frameDefault), fTimingTypeDefault(timingTypeDefault), fTimingChannelDefault(timingChannelDefault)
  {}
}

#endif
