// Class for holding the result of calculating the Distacnce of Closest approach for a track

#ifndef sbncode_scatterclosestapproach_H
#define sbncode_scatterclosestapproach_H

namespace sbn {
class ScatterClosestApproach {
  public:
  ScatterClosestApproach()
      : mMean(-5.f)
      , mStdDev(-5.f)
      , mMax(-5.f)
  {
  }

  ScatterClosestApproach(const float mean, const float stdDev, const float max)
      : mMean(mean)
      , mStdDev(stdDev)
      , mMax(max)
  {
  }

  float mMean;   // Average ClosestApproach [cm]
  float mStdDev; // Standard Deviation ClosestApproach [cm]
  float mMax;    // Maximum ClosestApproach [cm]
};
}

#endif
