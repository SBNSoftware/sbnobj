/**
 * @file   sbnobj/SBND/Timing/FrameShiftInfo.cxx
 * @brief  Defines data structures for SBND Frame Shift products (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *
 */

#ifndef SBND_FRAMSHIFTINFO_CXX
#define SBND_FRAMSHIFTINFO_CXX

#include "sbnobj/SBND/Timing/FrameShiftInfo.hh"

namespace sbnd::timing {

  FrameShiftInfo::FrameShiftInfo()
    : fTimingType(99)
    ,  fFrameTdcCrtt1(0)                                               
    ,  fFrameTdcBes(0)                                                
    ,  fFrameTdcRwm(0)                                                 
    ,  fFrameHltCrtt1(0)                                               
    ,  fFrameHltBeamGate(0)                                            
    ,  fFrameApplyAtCaf(0)                                             
    {}

  FrameShiftInfo::FrameShiftInfo(uint16_t _timingType, double _frameTdcCrtt1, double _frameTdcBes, double _frameTdcRwm, double _frameHltCrtt1, double _frameHltBeamGate, double _frameApplyAtCaf)
    : fTimingType(_timingType)
    ,  fFrameTdcCrtt1(_frameTdcCrtt1)                                               
    ,  fFrameTdcBes(_frameTdcBes)                                                
    ,  fFrameTdcRwm(_frameTdcRwm)                                                 
    ,  fFrameHltCrtt1(_frameHltCrtt1)                                               
    ,  fFrameHltBeamGate(_frameHltBeamGate)                                            
    ,  fFrameApplyAtCaf(_frameApplyAtCaf)                                             
    {}

  FrameShiftInfo::~FrameShiftInfo() {}

  uint16_t FrameShiftInfo::TimingType() const { return fTimingType; }
  double FrameShiftInfo::FrameTdcCrtt1() const { return fFrameTdcCrtt1; }
  double FrameShiftInfo::FrameTdcBes() const { return fFrameTdcBes; }
  double FrameShiftInfo::FrameTdcRwm() const { return fFrameTdcRwm; }
  double FrameShiftInfo::FrameHltCrtt1() const { return fFrameHltCrtt1; }
  double FrameShiftInfo::FrameHltBeamGate() const { return fFrameHltBeamGate; }
  double FrameShiftInfo::FrameApplyAtCaf() const { return fFrameApplyAtCaf; }

  void FrameShiftInfo::SetTimingType(uint16_t _type){ fTimingType = _type; }
  void FrameShiftInfo::SetFrameTdcCrtt1(double _frame){ fFrameTdcCrtt1 = _frame; }
  void FrameShiftInfo::SetFrameTdcBes(double _frame){ fFrameTdcBes = _frame; }
  void FrameShiftInfo::SetFrameTdcRwm(double _frame){ fFrameTdcRwm = _frame; }
  void FrameShiftInfo::SetFrameHltCrtt1(double _frame){ fFrameHltCrtt1 = _frame; }
  void FrameShiftInfo::SetFrameHltBeamGate(double _frame){ fFrameHltBeamGate = _frame; }
  void FrameShiftInfo::SetFrameApplyAtCaf(double _frame){ fFrameApplyAtCaf = _frame; }
}

#endif
