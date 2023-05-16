#include "sbnobj/Common/Reco/LightCaloInfo.h"

// initializer
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

double sbn::LightCalo::bestCharge() const {
  return charge.at(0);
}

double sbn::LightCalo::bestLight() const {
  return light.at(0);
}

double sbn::LightCalo::bestEnergy() const {
  return energy.at(0);
}

int sbn::LightCalo::bestPlane() const {
  return plane.at(0);
}