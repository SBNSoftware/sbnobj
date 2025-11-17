#ifndef sbnobj_LightCaloInfo_H
#define sbnobj_LightCaloInfo_H

#include <vector>
#include <limits>

namespace sbn{
  class LightCalo {
  public:
    static constexpr double nan = std::numeric_limits<double>::signaling_NaN();

    std::vector<double> charge = std::vector<double>(3, nan);
    std::vector<double> light  = std::vector<double>(3, nan);
    std::vector<double> energy = std::vector<double>(3, nan);
    int     bestplane{ -1 };
    double  time{ nan };

    LightCalo() = default;
    LightCalo(std::vector<double> charge, std::vector<double> light, std::vector<double> energy, int bestplane, double time) 
      : charge(charge)
      , light(light)
      , energy(energy)
      , bestplane(bestplane)
      , time(time)
      {} 
  };
}

#endif
