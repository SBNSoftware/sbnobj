#include "sbnobj/Common/Reco/CNNVertexScore.h"

sbn::PFPCNNVertexScore::PFPCNNVertexScore(float pfpVertexScore0, float pfpVertexScore1, float pfpVertexScore2, int nClusters)
  : pfpVertexScore0(pfpVertexScore0)
  , pfpVertexScore1(pfpVertexScore1)
  , pfpVertexScore2(pfpVertexScore2)
  , nClusters(nClusters)
{
}