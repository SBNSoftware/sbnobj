#include "sbnobj/Common/Reco/CNNScore.h"

sbn::PFPCNNScore::PFPCNNScore(float pfpTrackScore, float pfpShowerScore, float pfpNoiseScore, float pfpEndMichelScore, int nClusters)
  : pfpTrackScore(pfpTrackScore)
  , pfpShowerScore(pfpShowerScore)
  , pfpNoiseScore(pfpNoiseScore)
  , pfpEndMichelScore(pfpEndMichelScore)
  , nClusters(nClusters)
{
}