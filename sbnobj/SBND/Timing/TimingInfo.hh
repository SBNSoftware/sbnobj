/**
 * @file   sbnobj/SBND/Timing/TimingInfo.hh
 * @brief  Defines data structures for SBND Timing products
 * @author Vu Chi Lan Nguyen
 *
 */

#ifndef SBND_TIMINGINFO_HH
#define SBND_TIMINGINFO_HH

#include <stdint.h>
#include <limits>

namespace sbnd::timing {

  static constexpr uint64_t kSecondInNanoseconds = 1'000'000'000ULL;           ///< 1s = 1,000,000,000ns
  static constexpr uint64_t kInvalidTimestamp    = std::numeric_limits<uint64_t>::max(); ///< Invalid timestamp

  /**
   * @brief A class to store important timestamps in SBND Data
   * 
   * Each timestamp is in UNIX Timestamp Format [ns]
   *             
   * For more information, see
   * [SBN DocDB 46654](https://sbn-docdb.fnal.gov/cgi-bin/sso/ShowDocument?docid=46654).
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
      * @brief Default constructor.
     */
    TimingInfo() = default;

    /**
      * @brief Constructs the object with all key timing timestamps.
     *
      * @param[in] rawDAQHeaderTimestamp Raw DAQ timestamp in UNIX format [ns].
      * @param[in] tdcCrtt1 CRT T1 timestamp recorded by the TDC [ns].
      * @param[in] tdcBes BES timestamp recorded by the TDC [ns].
      * @param[in] tdcRwm RWM timestamp recorded by the TDC [ns].
      * @param[in] tdcEtrig ETRIG timestamp recorded by the TDC [ns].
      * @param[in] hltCrtt1 CRT T1 timestamp produced by the PTB HLT [ns].
      * @param[in] hltEtrig ETRIG timestamp produced by the PTB HLT [ns].
      * @param[in] hltBeamGate Beam Gate timestamp produced by the PTB HLT [ns].
     */
    TimingInfo(uint64_t rawDAQHeaderTimestamp, uint64_t tdcCrtt1, uint64_t tdcBes, uint64_t tdcRwm, uint64_t tdcEtrig, uint64_t hltCrtt1, uint64_t hltEtrig, uint64_t hltBeamGate);

    /// @name Getters
    /// @{
        /// @brief Returns the raw DAQ header timestamp [ns].
    uint64_t RawDAQHeaderTimestamp() const { return fRawDAQHeaderTimestamp; }
        /// @brief Returns the TDC CRT T1 timestamp [ns].
    uint64_t TdcCrtt1() const { return fTdcCrtt1; }
        /// @brief Returns the TDC BES timestamp [ns].
    uint64_t TdcBes() const { return fTdcBes; }
        /// @brief Returns the TDC RWM timestamp [ns].
    uint64_t TdcRwm() const { return fTdcRwm; }
        /// @brief Returns the TDC ETRIG timestamp [ns].
    uint64_t TdcEtrig() const { return fTdcEtrig; }
        /// @brief Returns the PTB HLT CRT T1 timestamp [ns].
    uint64_t HltCrtt1() const { return fHltCrtt1; }
        /// @brief Returns the PTB HLT ETRIG timestamp [ns].
    uint64_t HltEtrig() const { return fHltEtrig; }
        /// @brief Returns the PTB HLT Beam Gate timestamp [ns].
    uint64_t HltBeamGate() const { return fHltBeamGate; }
    /// @}
 
    /// @name Setters
    /// @{
        /// @brief Sets the raw DAQ header timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetRawDAQHeaderTimestamp(uint64_t timestamp){ fRawDAQHeaderTimestamp = timestamp; }
        /// @brief Sets the TDC CRT T1 timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetTdcCrtt1(uint64_t timestamp){ fTdcCrtt1 = timestamp; }
        /// @brief Sets the TDC BES timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetTdcBes(uint64_t timestamp){ fTdcBes = timestamp; }
        /// @brief Sets the TDC RWM timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetTdcRwm(uint64_t timestamp){ fTdcRwm = timestamp; }
        /// @brief Sets the TDC ETRIG timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetTdcEtrig(uint64_t timestamp){ fTdcEtrig = timestamp; }
        /// @brief Sets the PTB HLT CRT T1 timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetHltCrtt1(uint64_t timestamp){ fHltCrtt1 = timestamp; }
        /// @brief Sets the PTB HLT ETRIG timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetHltEtrig(uint64_t timestamp){ fHltEtrig = timestamp; }
        /// @brief Sets the PTB HLT Beam Gate timestamp.
        /// @param[in] timestamp Timestamp in UNIX format [ns].
    void SetHltBeamGate(uint64_t timestamp){ fHltBeamGate = timestamp; }
    /// @}

  };
}

#endif
