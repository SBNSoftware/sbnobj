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

  FrameShiftInfo::FrameShiftInfo(uint16_t timingType, double frameTdcCrtt1, double frameTdcBes, double frameTdcRwm, double frameHltCrtt1, double frameHltBeamGate, double frameApplyAtCaf)
    : fTimingType(timingType)
    ,  fFrameTdcCrtt1(frameTdcCrtt1)                                               
    ,  fFrameTdcBes(frameTdcBes)                                                
    ,  fFrameTdcRwm(frameTdcRwm)                                                 
    ,  fFrameHltCrtt1(frameHltCrtt1)                                               
    ,  fFrameHltBeamGate(frameHltBeamGate)                                            
    ,  fFrameApplyAtCaf(frameApplyAtCaf)                                             
    {}
}

#endif
