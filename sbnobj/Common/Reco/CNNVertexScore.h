#include <limits>

#ifndef sbnobj_CNNVertexScore_HH
#define sbnobj_CNNVertexScore_HH

namespace sbn {

  class PFPCNNVertexScore {
  public:
    PFPCNNVertexScore(float pfpVertexScore0 = -999., float pfpVertexScore1 = -999., float pfpVertexScore2 = -999., int nClusters = 0);

    float pfpVertexScore0; //!< shower score for PFP, average over all associated hits
    float pfpVertexScore1; //!< shower score for PFP, average over all associated hits
    float pfpVertexScore2; //!< shower score for PFP, average over all associated hits
    int nClusters; //!< number of clusters used for calculating average score
  };    
}

#endif