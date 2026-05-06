/**
 * @file   sbnobj/SBND/Timing/FrameShiftInfo.hh
 * @brief  Defines data structures for SBND Frame Shift products
 * @author Vu Chi Lan Nguyen
 *
 */

#ifndef SBND_FRAMESHIFTINFO_HH
#define SBND_FRAMESHIFTINFO_HH

#include <stdint.h>
#include <limits>

#include "sbnobj/SBND/Timing/TimingInfo.hh"

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
   * [SBN DocDB 46654](https://sbn-docdb.fnal.gov/cgi-bin/sso/ShowDocument?docid=46654).
   */

  enum TimingType : uint16_t {
    kSPECTDCType,
    kPTBHLTType,
    kNoShiftType,
    kInvalidType = std::numeric_limits<uint16_t>::max()
  };

  static constexpr uint16_t kInvalidChannel = std::numeric_limits<uint16_t>::max();

  class FrameShiftInfo {

    uint64_t fFrameCrtt1         = kInvalidTimestamp; ///< Frame for CRT T1 signal [ns]
    uint16_t fTimingTypeCrtt1    = kInvalidType; ///< Types of CRT T1 frame
    uint16_t fTimingChannelCrtt1 = kInvalidChannel; ///< Channel of CRT T1 frame

    uint64_t fFrameBeamGate         = kInvalidTimestamp; ///< Frame for Beam Gate [ns]
    uint16_t fTimingTypeBeamGate    = kInvalidType; ///< Types of Beam Gate frame
    uint16_t fTimingChannelBeamGate = kInvalidChannel; ///< Channel of Beam Gate frame

    uint64_t fFrameEtrig         = kInvalidTimestamp; ///< Frame for ETRIG [ns]
    uint16_t fTimingTypeEtrig    = kInvalidType; ///< Types of ETRIG frame
    uint16_t fTimingChannelEtrig = kInvalidChannel; ///< Channel of ETRIG frame

    uint64_t fFrameDefault         = kInvalidTimestamp; ///< Default frame depending on the stream type [ns]
    uint16_t fTimingTypeDefault    = kInvalidType; ///< Types of default frame
    uint16_t fTimingChannelDefault = kInvalidChannel; ///< Channel of default frame

   public:

    /**
     * @brief Default constructor.
     */
    FrameShiftInfo() = default;

    /**
     * @brief Constructs the object with all frame timestamps and metadata.
     *
     * @param[in] frameCrtt1 Frame for CRT T1 [ns].
     * @param[in] timingTypeCrtt1 Timing type for CRT T1 frame.
     * @param[in] timingChannelCrtt1 Timing channel for CRT T1 frame.
     *
     * @param[in] frameBeamGate Frame for Beam Gate [ns].
     * @param[in] timingTypeBeamGate Timing type for Beam Gate frame.
     * @param[in] timingChannelBeamGate Timing channel for Beam Gate frame.
     *
     * @param[in] frameEtrig Frame for ETRIG [ns].
     * @param[in] timingTypeEtrig Timing type for ETRIG frame.
     * @param[in] timingChannelEtrig Timing channel for ETRIG frame.
     *
     * @param[in] frameDefault Default frame depending on the stream [ns].
     * @param[in] timingTypeDefault Timing type for default frame.
     * @param[in] timingChannelDefault Timing channel for default frame.
     *
     */
    FrameShiftInfo(uint64_t frameCrtt1, uint16_t timingTypeCrtt1, uint16_t timingChannelCrtt1,
                   uint64_t frameBeamGate, uint16_t timingTypeBeamGate, uint16_t timingChannelBeamGate,
                   uint64_t frameEtrig, uint16_t timingTypeEtrig, uint16_t timingChannelEtrig,
                   uint64_t frameDefault,  uint16_t timingTypeDefault, uint16_t timingChannelDefault);

    /// @name Getters
    /// @{
    /// @brief Returns the CRT T1 reference frame timestamp [ns].
    uint64_t FrameCrtt1() const { return fFrameCrtt1; }
    /// @brief Returns the timing source type for the CRT T1 frame.
    uint16_t TimingTypeCrtt1() const { return fTimingTypeCrtt1; }
    /// @brief Returns the timing source channel for the CRT T1 frame.
    uint16_t TimingChannelCrtt1() const { return fTimingChannelCrtt1; }

    /// @brief Returns the Beam Gate reference frame timestamp [ns].
    uint64_t FrameBeamGate() const { return fFrameBeamGate; }
    /// @brief Returns the timing source type for the Beam Gate frame.
    uint16_t TimingTypeBeamGate() const { return fTimingTypeBeamGate; }
    /// @brief Returns the timing source channel for the Beam Gate frame.
    uint16_t TimingChannelBeamGate() const { return fTimingChannelBeamGate; }

    /// @brief Returns the ETRIG reference frame timestamp [ns].
    uint64_t FrameEtrig() const { return fFrameEtrig; }
    /// @brief Returns the timing source type for the ETRIG frame.
    uint16_t TimingTypeEtrig() const { return fTimingTypeEtrig; }
    /// @brief Returns the timing source channel for the ETRIG frame.
    uint16_t TimingChannelEtrig() const { return fTimingChannelEtrig; }

    /// @brief Returns the default reference frame timestamp [ns].
    uint64_t FrameDefault() const { return fFrameDefault; }
    /// @brief Returns the timing source type for the default frame.
    uint16_t TimingTypeDefault() const { return fTimingTypeDefault; }
    /// @brief Returns the timing source channel for the default frame.
    uint16_t TimingChannelDefault() const { return fTimingChannelDefault; }
    /// @}

    /// @name Setters
    /// @{
    /// @brief Sets the CRT T1 reference frame timestamp [ns].
    /// @param[in] frame CRT T1 frame timestamp.
    void SetFrameCrtt1(uint64_t frame){ fFrameCrtt1 = frame; }
    /// @brief Sets the timing source type for the CRT T1 frame.
    /// @param[in] type Timing type value.
    void SetTimingTypeCrtt1(uint16_t type){ fTimingTypeCrtt1 = type; }
    /// @brief Sets the timing source channel for the CRT T1 frame.
    /// @param[in] channel Timing channel value.
    void SetTimingChannelCrtt1(uint16_t channel){ fTimingChannelCrtt1 = channel; }
    
    /// @brief Sets the Beam Gate reference frame timestamp [ns].
    /// @param[in] frame Beam Gate frame timestamp.
    void SetFrameBeamGate(uint64_t frame){ fFrameBeamGate = frame; }
    /// @brief Sets the timing source type for the Beam Gate frame.
    /// @param[in] type Timing type value.
    void SetTimingTypeBeamGate(uint16_t type){ fTimingTypeBeamGate = type; }
    /// @brief Sets the timing source channel for the Beam Gate frame.
    /// @param[in] channel Timing channel value.
    void SetTimingChannelBeamGate(uint16_t channel){ fTimingChannelBeamGate = channel; }

    /// @brief Sets the ETRIG reference frame timestamp [ns].
    /// @param[in] frame ETRIG frame timestamp.
    void SetFrameEtrig(uint64_t frame){ fFrameEtrig = frame; }
    /// @brief Sets the timing source type for the ETRIG frame.
    /// @param[in] type Timing type value.
    void SetTimingTypeEtrig(uint16_t type){ fTimingTypeEtrig = type; }
    /// @brief Sets the timing source channel for the ETRIG frame.
    /// @param[in] channel Timing channel value.
    void SetTimingChannelEtrig(uint16_t channel){ fTimingChannelEtrig = channel; }

    /// @brief Sets the default reference frame timestamp [ns].
    /// @param[in] frame Default frame timestamp.
    void SetFrameDefault(uint64_t frame){ fFrameDefault = frame; }
    /// @brief Sets the timing source type for the default frame.
    /// @param[in] type Timing type value.
    void SetTimingTypeDefault(uint16_t type){ fTimingTypeDefault = type; }
    /// @brief Sets the timing source channel for the default frame.
    /// @param[in] channel Timing channel value.
    void SetTimingChannelDefault(uint16_t channel){ fTimingChannelDefault = channel; }
    /// @}
  };
}

#endif
