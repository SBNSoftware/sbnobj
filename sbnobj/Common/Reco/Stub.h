#ifndef sbncode_Stub_HH
#define sbncode_Stub_HH

#include <vector>
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "TVector3.h"

namespace sbn {
  class StubHit {
    public:
      float charge; //!< Calibrated and corrected for electron lifetime [#elec]
      bool ontrack; //!< Whether the hit is also on a track
      bool before_vtx; 
      bool after_hit;
  };

  class Stub {
  public:
    TVector3 vtx; //!< Interaction Vertex / Start of Stub [cm]
    TVector3 end; //!< End of Stub [cm]

    // per-plane information
    std::vector<geo::PlaneID> plane; //!< The plane ID

    std::vector<float> pitch; //!< Pitch of stub on each wire [cm]
    std::vector<float> trkpitch; //!< Pitch of the matched track on each wire [cm]
    std::vector<int> nwire;

    std::vector<std::vector<StubHit>> hits; //!< Hits on each plane. Ordered vtx->end
  };
} // end namespace sbn

#endif
