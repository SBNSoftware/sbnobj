#include "sbnobj/Common/Reco/CNNScore.h"

sbn::PFPCNNScore::PFPCNNScore(float pfpTrackScore, float pfpShowerScore, float pfpNoiseScore, float pfpMichelScore, float pfpEndMichelScore, int nClusters)
  : pfpTrackScore(pfpTrackScore)
  , pfpShowerScore(pfpShowerScore)
  , pfpNoiseScore(pfpNoiseScore)
  , pfpMichelScore(pfpMichelScore)
  , pfpEndMichelScore(pfpEndMichelScore)
  , nClusters(nClusters)
{
}