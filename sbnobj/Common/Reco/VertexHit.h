#ifndef sbncode_VertexHit_HH
#define sbncode_VertexHit_HH

#include <vector>
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "TVector3.h"

namespace sbn {
  class VertexHit {
  public:
    geo::WireID wire; //!< Wire the the hit is on
    float charge; //!< Calibrated and lifetime-corrected charge on the hit [#elec]
    float proj_dist_to_vertex; //!< Distnace from the hit to the vertex on the wireplane
    float vtxw; //!< Wire of the vertex associated with this hit
    int spID; //!< ID of the SpacePoint associated with this hit
    TVector3 spXYZ; //!< 3D location of the SpacePoint associated with this hit
    float pitch; //!< Computed pitch of a track traversing from the vertex to this hit [cm]
    float dqdx; //!< charge/pitch [#elec/cm]
    float dedx; //!< Recombination corrected dQ/dx [MeV/cm]
    std::vector<int> nearbyPFPIDs; //!< ID's of PFParticle's near this hit in 2D
    std::vector<float> nearbyPFPDists; //!< 2D Dot product of vertex-hit direction to PFParticle direction
    std::vector<float> nearbyPFP3DDists; //!< ID's of PFPArticle's near this hit in 3D
    std::vector<int> nearbyPFP3DIDs; //!< 3D Dot product of vertex-hit direction to PFParticle direction
  };
} // end namespace sbn

#endif
