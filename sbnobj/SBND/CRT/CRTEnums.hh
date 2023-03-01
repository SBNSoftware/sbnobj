/**
 * \brief Definitions of enums used in CRT objects
 *
 * \author Henry Lay (h.lay@lancaster.ac.uk)
 */

#ifndef SBND_CRTENUMS_HH
#define SBND_CRTENUMS_HH

#include <stdint.h>
#include <type_traits>

namespace sbnd::crt {

  enum CRTTagger {
    kUndefinedTagger = -1,
    kBottomTagger,
    kSouthTagger,
    kNorthTagger,
    kWestTagger,
    kEastTagger,
    kTopLowTagger,
    kTopHighTagger,

    kUpstreamTagger   = kSouthTagger,
    kDownstreamTagger = kNorthTagger
  };

  enum CoordSet : uint8_t {    // These are defined like bitwise 'flags' so they can be operated on
    kUndefinedSet = 0,
    kX   = 1,   // 001
    kY   = 2,   // 010
    kZ   = 4,   // 100
    kXY  = 3,   // 011
    kXZ  = 5,   // 101
    kYZ  = 6,   // 110
    kXYZ = 7,   // 111

    kThreeD = kXYZ

  };
}

extern sbnd::crt::CoordSet operator|(sbnd::crt::CoordSet lhs, sbnd::crt::CoordSet rhs);

extern sbnd::crt::CoordSet operator&(sbnd::crt::CoordSet lhs, sbnd::crt::CoordSet rhs);

#endif
