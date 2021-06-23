#ifndef sbncode_Stub_HH
#define sbncode_Stub_HH

#include <vector>
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "TVector3.h"

namespace sbn {
  class StubHit {
    public:
      float charge; //!< Calibrated and corrected for electron lifetime [#elec]
      short wire; //!< The wire this hit is on
      bool ontrack; //!< Whether the hit is also on a track
  };

  class Stub {
  public:
    TVector3 vtx; //!< Interaction Vertex / Start of Stub [cm]
    TVector3 end; //!< End of Stub [cm]

    float efield_end; //!< The E-Field at the stub end point
    float efield_vtx; //!< The E-Field at the reconstructed vertex

    // Per-plane information: sorted so that the "best" plane is the first index
    std::vector<geo::PlaneID> plane; //!< The plane ID

    std::vector<float> pitch; //!< Pitch of stub on each wire [cm]
    std::vector<float> trkpitch; //!< Pitch of the matched track on each wire [cm]
    std::vector<float> vtx_w; //!< Wire coordinate of the vertex on this plane
    std::vector<short> hit_w; //!< Wire of the end point hit on this plane

    std::vector<std::vector<StubHit>> hits; //!< Hits on each plane. Ordered vtx->end

    /// Helper functions
    float CoreCharge(unsigned plane_index=0) const; //!< Returns the charge along the core of the stub on the given plane index
    int CoreNHit(unsigned plane_index=0) const; //!< Returns the number of hits along the core of the stub on the given plane index
    float CoreCharge(const geo::PlaneID &p) const;
    int CoreNHit(const geo::PlaneID &p) const;

    int PlaneIndex(const geo::PlaneID &p) const;

    bool OnCore(const geo::WireID &w) const; //!< Returns whether the input wire-ID is on the core of the stub 

  };
} // end namespace sbn

#endif
