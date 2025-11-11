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
  FrameShiftInfo::FrameShiftInfo(uint64_t frameCrtt1, uint16_t timingTypeCrtt1,
                                 uint64_t frameBeamGate, uint16_t timingTypeBeamGate,
                                 uint64_t frameEtrig, uint16_t timingTypeEtrig,
                                 uint64_t frameDefault,  uint16_t timingTypeDefault)
    : fFrameCrtt1(frameCrtt1), fTimingTypeCrtt1(timingTypeCrtt1),
      fFrameBeamGate(frameBeamGate), fTimingTypeBeamGate(timingTypeBeamGate),
      fFrameEtrig(frameEtrig), fTimingTypeEtrig(timingTypeEtrig),
      fFrameDefault(frameDefault), fTimingTypeDefault(timingTypeDefault)
  {}
}

#endif
