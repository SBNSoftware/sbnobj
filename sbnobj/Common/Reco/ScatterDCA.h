// Class for holding the result of calculating the Distacnce of Closest approach for a track

#ifndef sbncode_scatterdca_H
#define sbncode_scatterdca_H

namespace sbn {
class ScatterDCA {
  public:
  ScatterDCA()
      : mMean(-5.f)
      , mStdDev(-5.f)
      , mMax(-5.f)
  {
  }

  ScatterDCA(const float mean, const float stdDev, const float max)
      : mMean(mean)
      , mStdDev(stdDev)
      , mMax(max)
  {
  }

  float mMean;   // Average DCA
  float mStdDev; // Standard Deviation DCA
  float mMax;    // Maximum DCA
};
}

#endif
