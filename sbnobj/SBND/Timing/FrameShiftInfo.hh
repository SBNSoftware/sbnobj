/**
 * @file   sbnobj/SBND/Timing/FrameShiftInfo.hh
 * @brief  Defines data structures for SBND Frame Shift products (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *
 */

#ifndef SBND_FRAMESHIFTINFO_HH
#define SBND_FRAMESHIFTINFO_HH

#include <stdint.h>
#include <limits>

namespace sbnd::timing {

  /**
   * @brief A class to store the shifts across different time reference frames in SBND Data
   * 
   * Each shift is in [ns]
   *             
   * For more information, see
   * [SBN DocDB 43090](https://sbn-docdb.fnal.gov/cgi-bin/sso/ShowDocument?docid=43090).
   */

  class FrameShiftInfo {
  
  public:
    static constexpr uint16_t InvalidTimingType = 99; ///< Invalid timing type for decoded frame
    static constexpr uint64_t NoShift = 0; ///< No shift.    

  private:

    uint16_t fTimingType = InvalidTimingType; ///< Types of decoded frames: 0 - SPEC TDC ETRIG, 1 - HLT ETRIG, 2 - Do Nothing
    double fFrameTdcCrtt1 = NoShift; ///< Shift from decoded frame to SPEC-TDC CRT T1 [ns]
    double fFrameTdcBes = NoShift; ///< Shift from decoded frame to SPEC-TDC BES [ns]
    double fFrameTdcRwm = NoShift; ///< Shift from decoded frame to SPEC-TDC RWM [ns]
    double fFrameHltCrtt1 = NoShift; ///< Shift from decoded frame to HLT CRT T1 [ns]
    double fFrameHltBeamGate = NoShift; ///< Shift from decoded frame to HLT Beam Gate [ns]
    double fFrameApplyAtCaf = NoShift; ///< Frame to shift to when running at CAF stage

   public:

    /**
     * Default constructor.
     */
    FrameShiftInfo() = default;

    /**
     * Constructor to set all frames
     *
     * @param timingType Types of decoded frames
     * @param frameTdcCrtt1 Shift from decoded frame to SPEC-TDC CRT T1 [ns]
     * @param frameTdcBes Shift from decoded frame to SPEC-TDC BES [ns]
     * @param frameTdcRwm Shift from decoded frame to SPEC-TDC RWM [ns]
     * @param frameHltCrtt1 Shift from decoded frame to HLT CRT T1 [ns]
     * @param frameHltBeamGate Shift from decoded frame to HLT Beam Gate [ns]
     * @param frameApplyAtCaf Frame to shift to when running at CAF stage
     */
    FrameShiftInfo(uint16_t timingType, double frameTdcCrtt1, double frameTdcBes, double frameTdcRwm, double frameHltCrtt1, double frameHltBeamGate, double frameApplyAtCaf);

    /// @name Getters
    /// @{
    uint16_t TimingType() const { return fTimingType; }
    double FrameTdcCrtt1() const { return fFrameTdcCrtt1; }
    double FrameTdcBes() const { return fFrameTdcBes; }
    double FrameTdcRwm() const { return fFrameTdcRwm; }
    double FrameHltCrtt1() const { return fFrameHltCrtt1;}
    double FrameHltBeamGate() const { return fFrameHltBeamGate; }
    double FrameApplyAtCaf() const { return fFrameApplyAtCaf; }
    /// @}

    /// @name Setters
    /// @{
    void SetTimingType(uint16_t type){ fTimingType = type; }
    void SetFrameTdcCrtt1(double frame){ fFrameTdcCrtt1 = frame; }
    void SetFrameTdcBes(double frame){ fFrameTdcBes = frame; }                     
    void SetFrameTdcRwm(double frame){ fFrameTdcRwm = frame; }
    void SetFrameHltCrtt1(double frame){ fFrameHltCrtt1 = frame; }
    void SetFrameHltBeamGate(double frame){ fFrameHltBeamGate = frame; }
    void SetFrameApplyAtCaf(double frame){ fFrameApplyAtCaf = frame; }
    /// @}
  };
}

#endif
