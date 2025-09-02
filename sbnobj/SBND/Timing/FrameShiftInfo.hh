/*
 * @file   sbnobj/SBND/Timing/FrameShiftInfo.hh
 * @brief  Defines data structures for SBND Frame Shift products (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *
 */

#ifndef SBND_FRAMESHIFTINFO_HH
#define SBND_FRAMESHIFTINFO_HH

#include <stdint.h>
#include <string>
#include <array>
#include <limits>

namespace sbnd::timing {

  /*
   * @brief A struct to shifts across different reference frames in SBND Data
   * 
   * Each shift is in [ns]
   *             
   */

  class FrameShiftInfo {

    uint16_t fTimingType; ///< Types of decoded frames: 0 - SPEC TDC ETRIG, 1 - HLT ETRIG, 2 - Do Nothing
    double fFrameTdcCrtt1; ///< Shift from decoded frame to SPEC-TDC CRT T1 [ns]
    double fFrameTdcBes; ///< Shift from decoded frame to SPEC-TDC BES [ns]
    double fFrameTdcRwm; ///< Shift from decoded frame to SPEC-TDC RWM [ns]
    double fFrameHltCrtt1; ///< Shift from decoded frame to HLT CRT T1 [ns]
    double fFrameHltBeamGate; ///< Shift from decoded frame to HLT Beam Gate [ns]
    double fFrameApplyAtCaf; ///< Frame to shift to when running at CAF stage

   public:

    /**
     * Default constructor.
     */
    FrameShiftInfo();

    /*
     * Constructor to set all timestamps
     *
     * @param _timingType Types of decoded frames
     * @param _frameTdcCrtt1 Shift from decoded frame to SPEC-TDC CRT T1 [ns]
     * @param _frameTdcBes Shift from decoded frame to SPEC-TDC BES [ns]
     * @param _frameTdcRwm Shift from decoded frame to SPEC-TDC RWM [ns]
     * @param _frameHltCrtt1 Shift from decoded frame to HLT CRT T1 [ns]
     * @param _frameHltBeamGate Shift from decoded frame to HLT Beam Gate [ns]
     * @param _frameApplyAtCaf Frame to shift to when running at CAF stage
     */
    FrameShiftInfo(uint16_t _timingType, double _frameTdcCrtt1, double _frameTdcBes, double _frameTdcRwm, double _frameHltCrtt1, double _frameHltBeamGate, double _frameApplyAtCaf);

    /**
     * Destructor
     */
    virtual ~FrameShiftInfo();

    /**
     * Getters
     */
    uint16_t TimingType() const;
    double FrameTdcCrtt1() const;                                               
    double FrameTdcBes() const;                                                 
    double FrameTdcRwm() const;                                                 
    double FrameHltCrtt1() const;                                               
    double FrameHltBeamGate() const;                                            
    double FrameApplyAtCaf() const;                                             

    /**
     * Getters
     */
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
