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
      
  };

} // namespace icarus::crt

#endif
