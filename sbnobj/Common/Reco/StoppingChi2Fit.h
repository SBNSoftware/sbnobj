// Class for holding the result of fitting a Pol0 andf expo to find the Bragg peak for a track

#ifndef sbncode_stoppingchi2fit_H
#define sbncode_stoppingchi2fit_H

namespace sbn {
class StoppingChi2Fit {
  public:
  StoppingChi2Fit()
      : mPol0Chi2(-5.f)
      , mExpChi2(-5.f)
      , mPol0Fit(-5.f)
  {
  }

  StoppingChi2Fit(const float Pol0Chi2, const float ExpChi2, const float Pol0Fit)
      : mPol0Chi2(Pol0Chi2)
      , mExpChi2(ExpChi2)
      , mPol0Fit(Pol0Fit)
  {
  }

  float mPol0Chi2; // Chi^2 of fitting a 0 degree polynomial
  float mExpChi2;  // Chi^2 of fitting an exponential
  float mPol0Fit;  // Best fit value of a 0 degree polynomial [MeV/cm]
};
}

#endif
