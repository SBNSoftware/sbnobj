/**
 * @file sbnobj/Common/Trigger/ExtraTriggerInfo.cxx
 * @brief Data product holding additional trigger information.
 * @authors Gianluca Petrillo (petrillo@slac.stanford.edu),
 *          Jacob Zettlemoyer (jzettle@fnal.gov>)
 * @date June 18, 2021
 * @see sbnobj/Common/Trigger/ExtraTriggerInfo.h
 */

#include "sbnobj/Common/Trigger/ExtraTriggerInfo.h"

// C/C++ standard library
#include <ostream>
#include <iomanip> // std::setfill(), std::setw()


// -----------------------------------------------------------------------------
namespace {
  
  // ---------------------------------------------------------------------------
  template <typename Stream, char CharOn = 'x', char CharOff = '-'>
  class ByteDumper {
    static constexpr char symbols[2] = { CharOff, CharOn };
    
    Stream& out;
    
      public:
    ByteDumper(Stream& out): out{ out } {}
    
    void operator() (std::uint8_t bits, std::size_t nBits = 8) const
      {
        std::uint8_t mask = 1 << (nBits - 1); // default: 0x80
        do { out << symbols[(bits & mask)? 1: 0]; } while (mask >>= 1);
      }
    
  }; // ByteDumper
  
  
  // ---------------------------------------------------------------------------
  template <typename T = std::uint64_t>
  struct TimestampDumper { T timestamp; };
  
  template <typename T>
  TimestampDumper<T> dumpTimestamp(T timestamp)
    { return { timestamp }; }
  
  template <typename T>
  std::ostream& operator<< (std::ostream& out, TimestampDumper<T> wrapper) {
    T const timestamp = wrapper.timestamp;
    if (sbn::ExtraTriggerInfo::isValidTimestamp(timestamp)) {
      out << (timestamp / 1'000'000'000) << "."
        << std::setfill('0') << std::setw(9) << (timestamp % 1'000'000'000)
        << " s";
    }
    else out << "<n/a>";
    return out;
  } // operator<< (TimestampDumper)
  
  
  // ---------------------------------------------------------------------------
  struct TriggerIDdumper { unsigned int ID; };
  
  TriggerIDdumper dumpTriggerID(unsigned int ID) { return { ID }; }
  
  std::ostream& operator<< (std::ostream& out, TriggerIDdumper wrapper) {
    unsigned int const ID = wrapper.ID;
    if (sbn::ExtraTriggerInfo::isValidID(ID)) out << ID;
    else                                      out << "<n/a>";
    return out;
  } // operator<< (TriggerIDdumper)
  
  
  // ---------------------------------------------------------------------------
  struct TriggerCountDumper { unsigned int count; };
  
  TriggerCountDumper dumpTriggerCount(unsigned int count) { return { count }; }
  
  std::ostream& operator<< (std::ostream& out, TriggerCountDumper wrapper) {
    unsigned int const count = wrapper.count;
    if (sbn::ExtraTriggerInfo::isValidCount(count)) out << count;
    else                                            out << "<n/a>";
    return out;
  } // operator<< (TriggerCountDumper)
  
  
  // ---------------------------------------------------------------------------
  long long int timestampDiff(std::uint64_t timestamp, std::uint64_t ref) {
    return static_cast<long long int>
      ((timestamp > ref)? (timestamp - ref): (ref - timestamp));
  }
  
  
  // ---------------------------------------------------------------------------
  template <typename T>
  struct BitDumper { T bits; unsigned int n; };
  
  template <typename T>
  BitDumper<T> dumpBits
    (T bits, unsigned int n = sizeof(T) * 8) { return { bits, n }; }
  
  template <typename T>
  std::ostream& operator<< (std::ostream& out, BitDumper<T> wrapper) {
    static auto const bitMask = [](unsigned int n)
      { return (n == sizeof(T)*8)? ~T{0}: T((1 << n) - 1); };
    
    ByteDumper const dumpByte{ out };
    unsigned int bitsLeft = wrapper.n;
    while (bitsLeft > 0) { // goes 8 by 8 (fewer on the first iteration)
      unsigned int const maskBits = (bitsLeft - 1) % 8 + 1;
      bitsLeft -= maskBits;
      dumpByte((wrapper.bits >> bitsLeft) & bitMask(maskBits), maskBits);
    } // while
    
    return out;
  } // operator<< (LVDSmaskDumper)
  
  
  // ---------------------------------------------------------------------------

  struct LVDSmaskDumper { std::uint64_t bits; };

  LVDSmaskDumper dumpLVDSmask(std::uint64_t bits) { return { bits }; }

  std::ostream& operator<< (std::ostream& out, LVDSmaskDumper wrapper) {
    std::uint64_t const bits { wrapper.bits };

    auto boardBits = [](std::uint64_t bits, short int board) -> std::uint8_t
      { return static_cast<std::uint8_t>((bits >> (board * 8)) & 0xFF); };

    // positions 3 and 7 are empty
    out
      << dumpBits(boardBits(bits, 6)) << ' '
      << dumpBits(boardBits(bits, 5)) << ' '
      << dumpBits(boardBits(bits, 4)) << ' '
      << ' '
      << dumpBits(boardBits(bits, 2)) << ' '
      << dumpBits(boardBits(bits, 1)) << ' '
      << dumpBits(boardBits(bits, 0))
      ;

    return out;
  } // operator<< (LVDSmaskDumper)
  
} // local namespace


// -----------------------------------------------------------------------------
std::ostream& sbn::operator<< (std::ostream& out, ExtraTriggerInfo const& info)
{
  if (!info.isValid()) {
    out << "<invalid>";
    return out;
  }
  
  // quite a load:
  out
    <<   "trigger ID=" << dumpTriggerID(info.triggerID)
      << " (type " << name(info.triggerType) << ")"
      << " from source " << name(info.sourceType)
      << " at " << dumpTimestamp(info.triggerTimestamp)
      << " on beam gate ID=" << dumpTriggerID(info.gateID)
      << " at " << dumpTimestamp(info.beamGateTimestamp)
      << " (diff: "
      << timestampDiff(info.beamGateTimestamp, info.triggerTimestamp) << " ns)"
    << "\n"
    << "enable gate opened at " << dumpTimestamp(info.enableGateTimestamp)
    << " (" << timestampDiff(info.beamGateTimestamp, info.enableGateTimestamp)
    << " ns before the gate)"
    << "\n"
      << "counts from this source: trigger="
        << dumpTriggerCount(info.triggerCount)
      << " beam=" << dumpTriggerCount(info.gateCount)
    << "\n"
      << "previous trigger from this source at "
      << dumpTimestamp(info.previousTriggerTimestamp)
      << ", triggers since: "
      << dumpTriggerCount(info.anyTriggerCountFromPreviousTrigger)
      << ", gates since: "
      << dumpTriggerCount(info.anyGateCountFromPreviousTrigger)
      << " ("
      << dumpTriggerCount(info.gateCountFromPreviousTrigger)
      << " from this same source)"
    << "\n"
      << "most recent trigger was from source "
      << name(info.anyPreviousTriggerSourceType) << " at "
      << dumpTimestamp(info.anyPreviousTriggerTimestamp)
    ;
  if (sbn::ExtraTriggerInfo::isValidTimestamp(info.anyPreviousTriggerTimestamp)
    && sbn::ExtraTriggerInfo::isValidTimestamp(info.triggerTimestamp))
  {
    out
      << " ("
      << dumpTimestamp(info.triggerTimestamp - info.anyPreviousTriggerTimestamp)
      << " earlier)";
  }
  out
      << ", and "
      << dumpTriggerCount(info.anyGateCountFromAnyPreviousTrigger)
      << " gates from any source have opened since"
    ;
  if (info.WRtimeToTriggerTime != ExtraTriggerInfo::UnknownCorrection) {
    out << "\nCorrection applied to the timestamps: "
      << dumpTimestamp(info.WRtimeToTriggerTime);
  }
  if (info.triggerLocationBits != 0) {
    out << "\nLocation(s) of trigger:";
    for (std::string const& bitName: names(info.triggerLocation()))
      out << "  * " << bitName;
  }
  
  out << "\nWest cryostat: " << info.cryostats[ExtraTriggerInfo::WestCryostat];
  out << "\nEast cryostat: " << info.cryostats[ExtraTriggerInfo::EastCryostat];
  
  return out;
} // sbn::operator<< (ExtraTriggerInfo)



// -----------------------------------------------------------------------------
std::ostream& sbn::operator<<
  (std::ostream& out, sbn::ExtraTriggerInfo::CryostatInfo const& cryo)
{
  out << cryo.triggerCount << " triggers";
  if (cryo.hasTrigger())
    out << ", the first one " << cryo.beamToTrigger << " ns after gate";
  if (cryo.hasAnyActivity()) {
    out << "\n  trigger logic: ";
    if (cryo.triggerLogicBits) {
      for (std::string const& bitName: names(cryo.triggerLogic()))
        out << "  * " << bitName;
    }
    else out << " none!";
    out
      << "\n  east wall:  "
      << dumpLVDSmask(cryo.LVDSstatus[ExtraTriggerInfo::EastPMTwall])
      << ", sectors: "
      << dumpBits(cryo.sectorStatus[ExtraTriggerInfo::EastPMTwall], 6)
      << "\n  west wall:  "
      << dumpLVDSmask(cryo.LVDSstatus[ExtraTriggerInfo::WestPMTwall])
      << ", sectors: "
      << dumpBits(cryo.sectorStatus[ExtraTriggerInfo::WestPMTwall], 6)
      ;
  }
  return out;
} // std::ostream& sbn::operator<< (ExtraTriggerInfo::CryostatInfo)


// -----------------------------------------------------------------------------
