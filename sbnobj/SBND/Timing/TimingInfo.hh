/*
 * @file   sbnobj/SBND/Timing/TimingInfo.hh
 * @brief  Defines data structures for SBND Timing Product (docdb#43090).
 * @author Vu Chi Lan Nguyen
 * @date   August 29, 2025
 *
 */

#ifndef SBND_TIMINGINFO_HH
#define SBND_TIMINGINFO_HH

#include <stdint.h>
#include <string>
#include <array>
#include <limits> 

namespace sbnd::timing {

  /*
   * @brief A struct to store important timestamps in SBND Data
   * 
   * Each timestamp is in UNIX Timestamp Format [ns]
   *             
   */

  class TimingInfo {

    uint64_t fRawDAQHeaderTimestamp; ///< Timestamp when the event is built by the event builder at DAQ-level
    uint64_t fTdcCrtt1; ///< Timestamp of BNB stream CRT T1 Reset recorded by the SPEC-TDC
    uint64_t fTdcBes; ///< Timestamp of BES signal sent by MFTU recorded by the SPEC-TDC
    uint64_t fTdcRwm; ///< Timestamp of RWM signal recorded by the SPEC-TDC
    uint64_t fTdcEtrig; ///< Timestamp of Event Trigger (ETRIG) sent by the PTB recorded by the SPEC-TDC 
    uint64_t fHltCrtt1; ///< Timestamp of BNB and Offbeam stream CRT T1 Reset High Level Trigger (HLT) created by the PTB
    uint64_t fHltEtrig; ///< Timestamp of ETRIG HLT created by the PTB
    uint64_t fHltBeamGate; ///< Timestamp of Beam Gate Acceptance HLT created by the PTB

   public:

    /*
     * Default constructor.
     */
    TimingInfo();

    /*
     * Constructor to set all timestamps
     *
     * @param _rawDAQHeaderTimestamp Raw DAQ Timestamp in UNIX format [ns]
     * @param _tdcCrtt1 CRT T1 Timestamp in UNIX format [ns]
     * @param _tdcBes BES Timestamp recorded by TDC in UNIX format [ns]
     * @param _tdcRwm RWM Timestamp recorded by TDC in UNIX format [ns]
     * @param _tdcEtrig ETRIG Timestamp recorded by TDC in UNIX format [ns]
     * @param _hltCrtt1 CRT T1 Timestamp created by PTB in UNIX format [ns]
     * @param _hltEtrig ETRIG Timestamp created by PTB in UNIX format [ns]
     * @param _hltBeamGate Beam Gate Timestamp created by PTB in UNIX format [ns]
     */
    TimingInfo(uint64_t _rawDAQHeaderTimestamp, uint64_t _tdcCrtt1, uint64_t _tdcBes, uint64_t _tdcRwm, uint64_t _tdcEtrig, uint64_t _hltCrtt1, uint64_t _hltEtrig, uint64_t _hltBeamGate);

    /**
     * Destructor
     */
    virtual ~TimingInfo();

    /**
     * Getters
     */
    uint64_t RawDAQHeaderTimestamp() const;
    uint64_t TdcCrtt1() const;
    uint64_t TdcBes() const;
    uint64_t TdcRwm() const;
    uint64_t TdcEtrig() const;
    uint64_t HltCrtt1() const;
    uint64_t HltEtrig() const;
    uint64_t HltBeamGate() const;
 
    /**
     * Setters
     */
    void SetRawDAQHeaderTimestamp(uint64_t timestamp);
    void SetTdcCrtt1(uint64_t timestamp);
    void SetTdcBes(uint64_t timestamp);
    void SetTdcRwm(uint64_t timestamp);
    void SetTdcEtrig(uint64_t timestamp);
    void SetHltCrtt1(uint64_t timestamp);
    void SetHltEtrig(uint64_t timestamp);
    void SetHltBeamGate(uint64_t timestamp);
  };
}

#endif
