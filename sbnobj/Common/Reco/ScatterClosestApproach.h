// Class for holding the result of calculating the Distacnce of Closest approach for a track

#ifndef sbncode_scatterclosestapproach_H
#define sbncode_scatterclosestapproach_H

namespace sbn {
class ScatterClosestApproach {
  public:
  ScatterClosestApproach()
      : mean(-5.f)
      , stdDev(-5.f)
      , max(-5.f)
  {
  }

  ScatterClosestApproach(const float mean, const float stdDev, const float max)
      : mean(mean)
      , stdDev(stdDev)
      , max(max)
  {
  }

  float mean;   // Average ClosestApproach [cm]
  float stdDev; // Standard Deviation ClosestApproach [cm]
  float max;    // Maximum ClosestApproach [cm]
};
}

#endif
