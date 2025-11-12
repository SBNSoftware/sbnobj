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
   * @brief A class to store reference frames in SBND Data
   * 
   * Each reference frame is in UNIX timestamp format [ns]
   * Store duplicated information from TimingInfo.hh for easier access at downstream modules.
   * 
   * Reference frames included:
   *
   * CRT T1 signal frame: 
   *  - Either from TDC or PTB HLT, TDC has higher priority if both are available
   *  - If selected, TDC CRT T1 frame is shifted to agree with HLT CRT T1 frame
   *  - Both unshifted TDC CRT T1 and HLT CRT T1 timestamps are saved in TimingInfo 
   *
   * Beam Gate frame: differs between beam vs offbeam stream
   * - Beam stream:
   *   - Either from TDC RWM or PTB HLT Gate, TDC RWM has higher priority if both are available
   *   - If selected, TDC RWM is shifted to agree with HLT Beam Gate frame
   *   - Both unshifted TDC RWM and HLT Beam Gate timestamps are saved in TimingInfo 
   * - Offbeam stream:
   *   - From PTB HLT Gate only
   *   - Saved in TimingInfo
   * 
   * ETRIG frame:
   * - Either from TDC or PTB HLT, TDC has higher priority if both are available
   * - If selected, TDC ETRIG frame is shifted to agree with HLT ETRIG frame
   * - Both unshifted TDC ETRIG and HLT ETRIG timestamps are saved in TimingInfo
   * 
   * Default frame: depends on the stream type
   * - Beam stream: use Beam Gate frame
   * - Offbeam stream: use Beam Gate frame
   * - Xmuon stream: use ETRIG frame
   * 
   * Timing Type indicates which source the frame is derived from:
   * 0 - SPEC TDC
   * 1 - PTB HLT
   * 2 - No frame found 
   * std::numeric_limits<uint16_t>::max() - Not initialized            
   *
   * Timing Channel incicates which channel the frame is derived from:
   * SPEC TDC: indicates which input channel 0 to 4
   * PTB: indicates the High Level Trigger (HLT) type
   *
   * For more information, see
   * [SBN DOCDB ???] ?????
   * Legacy -- no longer applied:
   * [SBN DocDB 43090](https://sbn-docdb.fnal.gov/cgi-bin/sso/ShowDocument?docid=43090).
   */

  class FrameShiftInfo {
  
  public:
    static constexpr uint64_t NoFrame = 0; ///< Invalid frame.    
    static constexpr uint16_t InvalidTimingType = std::numeric_limits<uint16_t>::max(); ///< Invalid timing type for reference frame
    static constexpr uint16_t InvalidTimingChannel = std::numeric_limits<uint16_t>::max(); ///< Invalid timing channel for reference frame

  private:

    uint64_t fFrameCrtt1 = NoFrame; ///< Frame for CRT T1 signal [ns]
    uint16_t fTimingTypeCrtt1 = InvalidTimingType; ///< Types of CRT T1 frame
    uint16_t fTimingChannelCrtt1 = InvalidTimingChannel; ///< Channel of CRT T1 frame

    uint64_t fFrameBeamGate = NoFrame; ///< Frame for Beam Gate [ns]
    uint16_t fTimingTypeBeamGate = InvalidTimingType; ///< Types of Beam Gate frame
    uint16_t fTimingChannelBeamGate = InvalidTimingChannel; ///< Channel of Beam Gate frame

    uint64_t fFrameEtrig = NoFrame; ///< Frame for ETRIG [ns]
    uint16_t fTimingTypeEtrig = InvalidTimingType; ///< Types of ETRIG frame
    uint16_t fTimingChannelEtrig = InvalidTimingChannel; ///< Channel of ETRIG frame

    uint64_t fFrameDefault = NoFrame; ///< Default frame depending on the stream type [ns]
    uint16_t fTimingTypeDefault = InvalidTimingType; ///< Types of default frame
    uint16_t fTimingChannelDefault = InvalidTimingChannel; ///< Channel of default frame

   public:

    /**
     * Default constructor.
     */
    FrameShiftInfo() = default;

    /**
     * Constructor to set all frames
     *
     * @param frameCrtt1 Frame for CRT T1 [ns]
     * @param timingTypeCrtt1 Timing type for CRT T1 frame
     * @param timingChannelCrtt1 Timing channel for CRT T1 frame
     *
     * @param frameBeamGate Frame for Beam Gate [ns]
     * @param timingTypeBeamGate Timing type for Beam Gate frame
     * @param timingChannelBeamGate Timing channel for Beam Gate frame
     *
     * @param frameEtrig Frame for ETRIG [ns]
     * @param timingTypeEtrig Timing type for ETRIG frame
     * @param timingChannelEtrig Timing channel for ETRIG frame
     *
     * @param frameDefault Default frame depending on the stream [ns]
     * @param timingTypeDefault Timing type for Default frame
     * @param timingChannelDefault Timing channel for Default frame
     *
     */
    FrameShiftInfo(uint64_t frameCrtt1, uint16_t timingTypeCrtt1, uint16_t timingChannelCrtt1,
                   uint64_t frameBeamGate, uint16_t timingTypeBeamGate, uint16_t timingChannelBeamGate,
                   uint64_t frameEtrig, uint16_t timingTypeEtrig, uint16_t timingChannelEtrig,
                   uint64_t frameDefault,  uint16_t timingTypeDefault, uint16_t timingChannelDefault);

    /// @name Getters
    /// @{
    uint64_t FrameCrtt1() const { return fFrameCrtt1; }
    uint16_t TimingTypeCrtt1() const { return fTimingTypeCrtt1; }
    uint16_t TimingChannelCrtt1() const { return fTimingChannelCrtt1; }

    uint64_t FrameBeamGate() const { return fFrameBeamGate; }
    uint16_t TimingTypeBeamGate() const { return fTimingTypeBeamGate; }
    uint16_t TimingChannelBeamGate() const { return fTimingChannelBeamGate; }

    uint64_t FrameEtrig() const { return fFrameEtrig; }
    uint16_t TimingTypeEtrig() const { return fTimingTypeEtrig; }
    uint16_t TimingChannelEtrig() const { return fTimingChannelEtrig; }

    uint64_t FrameDefault() const { return fFrameDefault; }
    uint16_t TimingTypeDefault() const { return fTimingTypeDefault; }
    uint16_t TimingChannelDefault() const { return fTimingChannelDefault; }
    /// @}

    /// @name Setters
    /// @{
    void SetFrameCrtt1(uint64_t frame){ fFrameCrtt1 = frame; }
    void SetTimingTypeCrtt1(uint16_t type){ fTimingTypeCrtt1 = type; }
    void SetTimingChannelCrtt1(uint16_t channel){ fTimingChannelCrtt1 = channel; }
    
    void SetFrameBeamGate(uint64_t frame){ fFrameBeamGate = frame; }
    void SetTimingTypeBeamGate(uint16_t type){ fTimingTypeBeamGate = type; }
    void SetTimingChannelBeamGate(uint16_t channel){ fTimingChannelBeamGate = channel; }

    void SetFrameEtrig(uint64_t frame){ fFrameEtrig = frame; }
    void SetTimingTypeEtrig(uint16_t type){ fTimingTypeEtrig = type; }
    void SetTimingChannelEtrig(uint16_t channel){ fTimingChannelEtrig = channel; }

    void SetFrameDefault(uint64_t frame){ fFrameDefault = frame; }
    void SetTimingTypeDefault(uint16_t type){ fTimingTypeDefault = type; }
    void SetTimingChannelDefault(uint16_t channel){ fTimingChannelDefault = channel; }
    /// @}
  };
}

#endif
