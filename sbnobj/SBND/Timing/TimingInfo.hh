/**
 * @file   sbnobj/SBND/Timing/TimingInfo.hh
 * @brief  Defines data structures for SBND Timing products (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *
 */

#ifndef SBND_TIMINGINFO_HH
#define SBND_TIMINGINFO_HH

#include <stdint.h>
#include <limits>

namespace sbnd::timing {

  static constexpr uint64_t kInvalidTimestamp = std::numeric_limits<uint64_t>::max(); ///< Invalid timestamp

  /**
   * @brief A class to store important timestamps in SBND Data
   * 
   * Each timestamp is in UNIX Timestamp Format [ns]
   *             
   * For more information, see
   * [SBN DocDB 43090](https://sbn-docdb.fnal.gov/cgi-bin/sso/ShowDocument?docid=43090).
   */

  class TimingInfo {
  
    uint64_t fRawDAQHeaderTimestamp = kInvalidTimestamp; ///< Timestamp when the event is built by the event builder at DAQ-level
    uint64_t fTdcCrtt1 = kInvalidTimestamp; ///< Timestamp of BNB stream CRT T1 Reset recorded by the SPEC-TDC
    uint64_t fTdcBes = kInvalidTimestamp; ///< Timestamp of BES signal sent by MFTU recorded by the SPEC-TDC
    uint64_t fTdcRwm = kInvalidTimestamp; ///< Timestamp of RWM signal recorded by the SPEC-TDC
    uint64_t fTdcEtrig = kInvalidTimestamp; ///< Timestamp of Event Trigger (ETRIG) sent by the PTB recorded by the SPEC-TDC 
    uint64_t fHltCrtt1 = kInvalidTimestamp; ///< Timestamp of BNB and Offbeam stream CRT T1 Reset High Level Trigger (HLT) created by the PTB
    uint64_t fHltEtrig = kInvalidTimestamp; ///< Timestamp of ETRIG HLT created by the PTB
    uint64_t fHltBeamGate = kInvalidTimestamp; ///< Timestamp of Beam Gate Acceptance HLT created by the PTB

   public:

    /**
     * Default constructor.
     */
    TimingInfo() = default;

    /**
     * Constructor to set all timestamps
     *
     * @param rawDAQHeaderTimestamp Raw DAQ Timestamp in UNIX format [ns]
     * @param tdcCrtt1 CRT T1 Timestamp in UNIX format [ns]
     * @param tdcBes BES Timestamp recorded by TDC in UNIX format [ns]
     * @param tdcRwm RWM Timestamp recorded by TDC in UNIX format [ns]
     * @param tdcEtrig ETRIG Timestamp recorded by TDC in UNIX format [ns]
     * @param hltCrtt1 CRT T1 Timestamp created by PTB in UNIX format [ns]
     * @param hltEtrig ETRIG Timestamp created by PTB in UNIX format [ns]
     * @param hltBeamGate Beam Gate Timestamp created by PTB in UNIX format [ns]
     */
    TimingInfo(uint64_t rawDAQHeaderTimestamp, uint64_t tdcCrtt1, uint64_t tdcBes, uint64_t tdcRwm, uint64_t tdcEtrig, uint64_t hltCrtt1, uint64_t hltEtrig, uint64_t hltBeamGate);

    /// @name Getters
    /// @{
    uint64_t RawDAQHeaderTimestamp() const { return fRawDAQHeaderTimestamp; }
    uint64_t TdcCrtt1() const { return fTdcCrtt1; }
    uint64_t TdcBes() const { return fTdcBes; }
    uint64_t TdcRwm() const { return fTdcRwm; }
    uint64_t TdcEtrig() const { return fTdcEtrig; }
    uint64_t HltCrtt1() const { return fHltCrtt1; }
    uint64_t HltEtrig() const { return fHltEtrig; }
    uint64_t HltBeamGate() const { return fHltBeamGate; }
    /// @}
 
    /// @name Setters
    /// @{
    void SetRawDAQHeaderTimestamp(uint64_t timestamp){ fRawDAQHeaderTimestamp = timestamp; }
    void SetTdcCrtt1(uint64_t timestamp){ fTdcCrtt1 = timestamp; }
    void SetTdcBes(uint64_t timestamp){ fTdcBes = timestamp; }
    void SetTdcRwm(uint64_t timestamp){ fTdcRwm = timestamp; }
    void SetTdcEtrig(uint64_t timestamp){ fTdcEtrig = timestamp; }
    void SetHltCrtt1(uint64_t timestamp){ fHltCrtt1 = timestamp; }
    void SetHltEtrig(uint64_t timestamp){ fHltEtrig = timestamp; }
    void SetHltBeamGate(uint64_t timestamp){ fHltBeamGate = timestamp; }
    /// @}

  };
}

#endif
