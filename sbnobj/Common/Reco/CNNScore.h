#include <limits>

#ifndef sbnobj_CNNScore_HH
#define sbnobj_CNNScore_HH

namespace sbn {

  constexpr float nan_float = std::numeric_limits<float>::signaling_NaN();

  class PFPCNNScore {
  public:
    PFPCNNScore(float pfpTrackScore = nan_float, float pfpShowerScore = nan_float, float pfpNoiseScore = nan_float, int nClusters = 0);

    float pfpTrackScore; //!< shower score for PFP, average over all associated hits
    float pfpShowerScore; //!< shower score for PFP, average over all associated hits
    float pfpNoiseScore; //!< shower score for PFP, average over all associated hits
    // float pfpMichelScore; //!< michel score for PFP, average over 48*48 area around the endpoint
    int nClusters; //!< number of clusters used for calculating average score
  };    
}

#endif
