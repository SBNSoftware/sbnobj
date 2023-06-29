#include "sbnobj/Common/Reco/CNNScore.h"

sbn::PFPCNNScore::PFPCNNScore(float pfpTrackScore, float pfpShowerScore, float pfpNoiseScore, int nClusters)
  : pfpTrackScore(pfpTrackScore)
  , pfpShowerScore(pfpShowerScore)
  , pfpNoiseScore(pfpNoiseScore)
  // , pfpMichelScore(pfpMichelScore)
  , nClusters(nClusters)
{
}
