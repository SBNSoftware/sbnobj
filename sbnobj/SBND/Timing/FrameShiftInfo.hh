/**
 * \brief Data product to shift reference frames in SBND
 *
 * \author Vu Chi Lan Nguyen (vclnguyen@ucsb.edu)
 * Object to shift timing to a specific frame after being decoded
 * Products made by FrameShift module                                                        
 */

#ifndef SBND_FRAMESHIFTINFO_HH
#define SBND_FRAMESHIFTINFO_HH

#include <stdint.h>
#include <string>
#include <array>
#include <limits> // for std::numeric_limits

namespace sbnd::timing {

  class FrameShiftInfo {

    uint16_t fTimingType; // e.g. SPECTDC = 0; PTB HLT = 1; CAEN-only = 3
    double fFrameTdcCrtt1;                                               
    double fFrameTdcBes;                                                 
    double fFrameTdcRwm;                                                 
    double fFrameHltCrtt1;                                               
    double fFrameHltBeamGate;                                            
    double fFrameApplyAtCaf;                                             

   public:

    FrameShiftInfo();

    FrameShiftInfo(uint16_t _timingType, double _frameTdcCrtt1, double _frameTdcBes, double _frameTdcRwm, double _frameHltCrtt1, double _frameHltBeamGate, double _frameApplyAtCaf);

    virtual ~FrameShiftInfo();

    uint16_t TimingType() const;
    double FrameTdcCrtt1() const;                                               
    double FrameTdcBes() const;                                                 
    double FrameTdcRwm() const;                                                 
    double FrameHltCrtt1() const;                                               
    double FrameHltBeamGate() const;                                            
    double FrameApplyAtCaf() const;                                             

    void SetTimingType(uint16_t _type);
    void SetFrameTdcCrtt1(double _frame);                                               
    void SetFrameTdcBes(double _frame);                                                 
    void SetFrameTdcRwm(double _frame);                                                 
    void SetFrameHltCrtt1(double _frame);                                               
    void SetFrameHltBeamGate(double _frame);                                            
    void SetFrameApplyAtCaf(double _frame);                                             
  };
}

#endif
