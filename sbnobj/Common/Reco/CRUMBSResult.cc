#include "sbnobj/Common/Reco/CRUMBSResult.h"

sbn::CRUMBSResult::CRUMBSResult(float score, float tpc_CRFracHitsInLongestTrack, float tpc_CRLongestTrackDeflection, float tpc_CRLongestTrackDirY,
				float tpc_CRNHitsMax, float tpc_NuEigenRatioInSphere, float tpc_NuNFinalStatePfos, float tpc_NuNHitsTotal,
				float tpc_NuNSpacePointsInSphere, float tpc_NuVertexY, float tpc_NuWeightedDirZ, float tpc_StoppingChi2CosmicRatio,
				float pds_FMTotalScore, float pds_FMPE, float pds_FMTime, float crt_TrackScore, float crt_HitScore,
				float crt_TrackTime, float crt_HitTime)
: score(score)
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

sbn::CRUMBSResult::CRUMBSResult(float score)
  : score(score)
{
}

sbn::CRUMBSResult::CRUMBSResult()
  : score(-5.f)
  , tpc_CRFracHitsInLongestTrack(-5.f)
  , tpc_CRLongestTrackDeflection(-5.f)
  , tpc_CRLongestTrackDirY(-5.f)
  , tpc_CRNHitsMax(-5.f)
  , tpc_NuEigenRatioInSphere(-5.f)
  , tpc_NuNFinalStatePfos(-5.f)
  , tpc_NuNHitsTotal(-5.f)
  , tpc_NuNSpacePointsInSphere(-5.f)
  , tpc_NuVertexY(-5.f)
  , tpc_NuWeightedDirZ(-5.f)
  , tpc_StoppingChi2CosmicRatio(-5.f)
  , pds_FMTotalScore(-5.f)
  , pds_FMPE(-5.f)
  , pds_FMTime(-5.f)
  , crt_TrackScore(-5.f)
  , crt_HitScore(-5.f)
  , crt_TrackTime(-5.f)
  , crt_HitTime(-5.f)
{
}
