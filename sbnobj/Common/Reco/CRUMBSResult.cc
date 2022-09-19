#include "sbnobj/Common/Reco/CRUMBSResult.h"

sbn::CRUMBSResult::CRUMBSResult(float score, float ccnumuscore, float ccnuescore, float ncscore, float bestscore, int bestid, 
				float tpc_CRFracHitsInLongestTrack, float tpc_CRLongestTrackDeflection, float tpc_CRLongestTrackDirY,
				int tpc_CRNHitsMax, float tpc_NuEigenRatioInSphere, int tpc_NuNFinalStatePfos, int tpc_NuNHitsTotal,
				int tpc_NuNSpacePointsInSphere, float tpc_NuVertexY, float tpc_NuWeightedDirZ, float tpc_StoppingChi2CosmicRatio,
				float pds_FMTotalScore, float pds_FMPE, float pds_FMTime, float crt_TrackScore, float crt_HitScore,
				float crt_TrackTime, float crt_HitTime)
  : score(score)
  , ccnumuscore(ccnumuscore)
  , ccnuescore(ccnuescore)
  , ncscore(ncscore)
  , bestscore(bestscore)
  , bestid(bestid)
  , tpc_CRFracHitsInLongestTrack(tpc_CRFracHitsInLongestTrack)
  , tpc_CRLongestTrackDeflection(tpc_CRLongestTrackDeflection)
  , tpc_CRLongestTrackDirY(tpc_CRLongestTrackDirY)
  , tpc_CRNHitsMax(tpc_CRNHitsMax)
  , tpc_NuEigenRatioInSphere(tpc_NuEigenRatioInSphere)
  , tpc_NuNFinalStatePfos(tpc_NuNFinalStatePfos)
  , tpc_NuNHitsTotal(tpc_NuNHitsTotal)
  , tpc_NuNSpacePointsInSphere(tpc_NuNSpacePointsInSphere)
  , tpc_NuVertexY(tpc_NuVertexY)
  , tpc_NuWeightedDirZ(tpc_NuWeightedDirZ)
  , tpc_StoppingChi2CosmicRatio(tpc_StoppingChi2CosmicRatio)
  , pds_FMTotalScore(pds_FMTotalScore)
  , pds_FMPE(pds_FMPE)
  , pds_FMTime(pds_FMTime)
  , crt_TrackScore(crt_TrackScore)
  , crt_HitScore(crt_HitScore)
  , crt_TrackTime(crt_TrackTime)
  , crt_HitTime(crt_HitTime)
{
}

