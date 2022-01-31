// Class for holding the result of fitting a Pol0 andf expo to find the Bragg peak for a track

#ifndef sbncode_stoppingchi2fit_H
#define sbncode_stoppingchi2fit_H

namespace sbn {
class StoppingChi2Fit {
  public:
  StoppingChi2Fit()
      : pol0Chi2(-5.f)
      , expChi2(-5.f)
      , pol0Fit(-5.f)
  {
  }

  StoppingChi2Fit(const float pol0Chi2, const float expChi2, const float pol0Fit)
      : pol0Chi2(pol0Chi2)
      , expChi2(expChi2)
      , pol0Fit(pol0Fit)
  {
  }

  float pol0Chi2; // Chi^2 of fitting a 0 degree polynomial
  float expChi2;  // Chi^2 of fitting an exponential
  float pol0Fit;  // Best fit value of a 0 degree polynomial [MeV/cm]
};
}

#endif
