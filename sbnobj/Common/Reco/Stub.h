#ifndef sbncode_Stub_HH
#define sbncode_Stub_HH

#include <vector>
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "TVector3.h"

namespace sbn {
  class Stub {
  public:
    TVector3 vtx; //!< Interaction Vertex / Start of Stub [cm]
    TVector3 end; //!< End of Stub [cm]

    // per-plane information
    std::vector<geo::PlaneID> plane; //!< The plane ID

    /// Charge of each hit on the stub on the plane
    /// Corrected for electron lifetime
    /// Ordered vtx->end
    /// In units of #elec
    std::vector<std::vector<float>> charge;

    std::vector<float> pitch; //!< Pitch of stub on each wire [cm]
    std::vector<int> nwire; //!< Number of wires contributing charge to the stub

  };
} // end namespace sbn

#endif
