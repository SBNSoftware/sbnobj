#ifndef ICCRTData_hh_
#define ICCRTData_hh_

#include <cstdint>

namespace icarus::crt {

  struct CRTData {

      uint8_t  fMac5    { 0 }; ///< FEB address following numbering convention common for both data and MC.
      uint32_t fEntry;         ///< Hit index for given FEB in an event (starts from 0 for each event).
      uint64_t fTs0     { 0 }; ///< Absolute hit timestamp [ns]
      uint64_t fTs1     { 0 }; ///< Trigger time, not well defined as of Apr 14, 2021.
      uint16_t fAdc[64] {};    ///< ADC readout for each channel. CAEN (Bern) CRT FEBs use only indices 0-31.

      uint8_t  fFlags    { 0 };
      uint64_t fThis_poll_start         { 0 };
      uint64_t fLast_poll_start         { 0 };
      uint32_t fHits_in_poll            { 0 };

      uint32_t fCoinc                   { 0 };

      uint64_t fLast_accepted_timestamp { 0 };
      uint16_t fLost_hits               { 0 };


      bool IsOverflow_TS0()  const { return !(fFlags&1); } // TODO double check the logic, it may change with
      bool IsOverflow_TS1()  const { return !(fFlags&2); } // new FEB firmware (?)
      bool IsReference_TS0() const { return   fFlags&4 ; }
      bool IsReference_TS1() const { return   fFlags&8 ; }
      
  };

} // namespace icarus::crt

#endif
