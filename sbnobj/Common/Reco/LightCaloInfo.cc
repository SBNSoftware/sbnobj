#include "sbnobj/Common/Reco/LightCaloInfo.h"

sbn::LightCalo::LightCalo(std::vector<double> charge_v, std::vector<double> light_v, 
                          std::vector<double> energy_v, std::vector<int> plane_v,
                          double time)
  : charge(charge_v)
  , light(light_v)
  , energy(energy_v)
  , plane(plane_v)
  , time(time)
{
}