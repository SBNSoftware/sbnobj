// Class for holding the result of calculating the Distacnce of Closest approach for a track

#ifndef sbncode_scatterclosestapproach_H
#define sbncode_scatterclosestapproach_H

namespace sbn {
class ScatterClosestApproach {
  public:
  ScatterClosestApproach()
      : Mean(-5.f)
      , StdDev(-5.f)
      , Max(-5.f)
  {
  }

  ScatterClosestApproach(const float mean, const float stdDev, const float max)
      : Mean(mean)
      , StdDev(stdDev)
      , Max(max)
  {
  }

  float Mean;   // Average ClosestApproach [cm]
  float StdDev; // Standard Deviation ClosestApproach [cm]
  float Max;    // Maximum ClosestApproach [cm]
};
}

#endif
