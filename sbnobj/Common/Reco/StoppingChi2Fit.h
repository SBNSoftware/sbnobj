// Class for holding the result of fitting a Pol0 andf expo to find the Bragg peak for a track

#ifndef sbncode_stoppingchi2fit_H
#define sbncode_stoppingchi2fit_H

namespace sbn {
class StoppingChi2Fit {
  public:
  StoppingChi2Fit()
      : Pol0Chi2(-5.f)
      , ExpChi2(-5.f)
      , Pol0Fit(-5.f)
  {
  }

  StoppingChi2Fit(const float pol0Chi2, const float expChi2, const float pol0Fit)
      : Pol0Chi2(pol0Chi2)
      , ExpChi2(expChi2)
      , Pol0Fit(pol0Fit)
  {
  }

  float Pol0Chi2; // Chi^2 of fitting a 0 degree polynomial
  float ExpChi2;  // Chi^2 of fitting an exponential
  float Pol0Fit;  // Best fit value of a 0 degree polynomial [MeV/cm]
};
}

#endif
