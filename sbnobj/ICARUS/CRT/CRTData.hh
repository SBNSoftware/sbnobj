#ifndef ICCRTData_hh_
#define ICCRTData_hh_

#include <cstdint>

/// icarus::crt::CRTData flag mnemonics
namespace icarus::crt::CRTDataFlags {
  static constexpr uint32_t TS0Present   = 0x0001; ///< TS0 counter was restarted in time
  static constexpr uint32_t TS1Present   = 0x0002; ///< TS1 counter was restarted in time
  static constexpr uint32_t TS0Reference = 0x0004; ///< This hit is a T0 reference signal
  static constexpr uint32_t TS1Reference = 0x0008; ///< This hit is a T1 reference signal
}

namespace icarus::crt {

  struct CRTData {

      uint8_t  fMac5    { 0 }; ///< FEB address following numbering convention common for both data and MC.
      uint32_t fEntry;         ///< Hit index for given FEB in an event (starts from 0 for each event).
      uint64_t fTs0     { 0 }; ///< Absolute hit timestamp [ns]
      uint64_t fTs1     { 0 }; ///< Trigger time, not well defined as of Apr 14, 2021.
      uint16_t fAdc[64] {};    ///< ADC readout for each channel. CAEN (Bern) CRT FEBs use only indices 0-31.

      uint32_t fFlags    { 0 }; ///< DAQ uses 8 bits, remaining bits reserved for future use
      uint64_t fThisPollStart         { 0 };
      uint64_t fLastPollStart         { 0 };
      uint32_t fHitsInPoll            { 0 };

      uint32_t fCoinc                   { 0 };

      uint64_t fLastAcceptedTimestamp  { 0 };
      uint16_t fLostHits               { 0 };


      bool IsOverflow_TS0()  const { return !(fFlags & CRTDataFlags::TS0Present); }
      bool IsOverflow_TS1()  const { return !(fFlags & CRTDataFlags::TS1Present); }
      bool IsReference_TS0() const { return   fFlags & CRTDataFlags::TS0Reference; }
      bool IsReference_TS1() const { return   fFlags & CRTDataFlags::TS1Reference; }
      
  };

} // namespace icarus::crt


#endif
