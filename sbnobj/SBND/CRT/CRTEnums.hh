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

  // CRTTagger enum used to quickly refer to one of the seven SBND taggers.

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

  // Often working in 1, 2 or 3 dimensions for CRT things, this enum allows us to define this easily.
  // It is defined like a bitset of flags such that the below operations can be defined usefully.

  enum CoordSet : uint8_t {
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

  enum CRTChannelStatus {
    kGoodChannel = 0,
    kDeadChannel,
    kDeadNeighbourChannel,
    kQuietChannel,
    kQuietNeighbourChannel
  };
}

extern sbnd::crt::CoordSet operator|(sbnd::crt::CoordSet lhs, sbnd::crt::CoordSet rhs);

extern sbnd::crt::CoordSet operator&(sbnd::crt::CoordSet lhs, sbnd::crt::CoordSet rhs);

#endif
