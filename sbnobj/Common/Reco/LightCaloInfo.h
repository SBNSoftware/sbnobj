#ifndef sbnobj_LightCaloInfo_H
#define sbnobj_LightCaloInfo_H

#include <vector>
#include "larcoreobj/SimpleTypesAndConstants/geo_types.h"

namespace sbn
{
  class LightCalo 
  {
    public:

    // note: not ordered as plane0, plane1, and plane2 necessarily. "best plane" is first
    std::vector<double> charge; // reconstructed charge (e-)
    std::vector<double> light;  // reconstructed light (photons), set as the median of the light per channel 
    std::vector<double> energy; // sum of charge and light
    std::vector<int> plane; // first plane is the best plane (most complete)
    double time;   // t0 associated with the flash match

    LightCalo(std::vector<double> charge_v, 
              std::vector<double> light_v, 
              std::vector<double> energy_v,
              std::vector<int> plane_v,
              double time);
    LightCalo() {}
  };
}

#endif
