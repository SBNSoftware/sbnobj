#ifndef sbncode_VertexHit_HH
#define sbncode_VertexHit_HH

#include <vector>
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"

namespace sbn {
  class VertexHit {
  public:
    geo::WireID wire; //!< Wire that the hit is on
    float charge; //!< Calibrated and lifetime-corrected charge on the hit [#elec]
    float proj_dist_to_vertex; //!< Distnace from the hit to the vertex on the wireplane
    float vtxw; //!< Wire of the vertex associated with this hit. Not space charge corrected. [cm]
    float vtxx; //!< X-Position of the vertex associated with this hit as seen by wire-planes. Not space charge corrected. [cm]
    int spID; //!< ID of the SpacePoint associated with this hit
    geo::Point_t spXYZ; //!< 3D location of the SpacePoint associated with this hit. Space charge corrected. [cm]
    geo::Point_t vtxXYZ; //!< 3D location of the Vertex associated with this hit. Space charge corrected. [cm]
    float pitch; //!< Computed pitch of a track traversing from the vertex to this hit. Space charge corrected. [cm]
    float dqdx; //!< charge/pitch [#elec/cm]
    float dedx; //!< Recombination corrected dQ/dx [MeV/cm]
  };
} // end namespace sbn

#endif
