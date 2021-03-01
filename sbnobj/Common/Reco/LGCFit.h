// Class for holding the result of fitting a Landau-Guassian convolution

#ifndef sbncode_lgcfit_H
#define sbncode_lgcfit_H

namespace sbn {
class LGCFit {
  public:
  LGCFit()
      : mLandauWidth(-5.f)
      , mMPV(-5.f)
      , mAmplitude(-5.f)
      , mGaussWidth(-5.f)
      , mChi2(-5.f)
      , mNDF(0)
  {
  }

  LGCFit(const float landauWidth, const float MPV, const float Amplitude, const float GaussWidth, const float Chi2, const unsigned int NDF)
      : mLandauWidth(landauWidth)
      , mMPV(MPV)
      , mAmplitude(Amplitude)
      , mGaussWidth(GaussWidth)
      , mChi2(Chi2)
      , mNDF(NDF)
  {
  }

  float mLandauWidth; // Width (sigma) of the Landau
  float mMPV;         // Most probable location of the Landau
  float mAmplitude;   // Amplitude of the Landau
  float mGaussWidth;  // Wifth (sigma) of the Guassian
  float mChi2;        // Chi^2 from the fit
  unsigned int mNDF;  // Number of Degrees of Freedom in the fit
};
}

#endif
