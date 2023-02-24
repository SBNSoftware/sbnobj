// class for storing CNN hit classification result
#include <limits>

#ifndef CNNScore_HH
#define CNNScore_HH

namespace sbn {

  constexpr float nan_float = std::numeric_limits<float>::signaling_NaN();

  class CNNScore {
  public:
    CNNScore(float showerScore = nan_float, float michelScore = nan_float);

    float showerScore; //!< shower score for PFO, average over all associated hits
    float michelScore; //!< michel score for PFO, average over 48*48 area around the endpoint
  };    
}

#endif
