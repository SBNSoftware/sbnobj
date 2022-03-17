#include "sbnobj/Common/Reco/CRUMBSResult.h"

#include <limits>

sbn::CRUMBSResult::CRUMBSResult(float score, float tpc_CRFracHitsInLongestTrack, float tpc_CRLongestTrackDeflection, float tpc_CRLongestTrackDirY,
				int tpc_CRNHitsMax, float tpc_NuEigenRatioInSphere, int tpc_NuNFinalStatePfos, int tpc_NuNHitsTotal,
				int tpc_NuNSpacePointsInSphere, float tpc_NuVertexY, float tpc_NuWeightedDirZ, float tpc_StoppingChi2CosmicRatio,
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
  : score(std::numeric_limits<float>::signaling_NaN())
  , tpc_CRFracHitsInLongestTrack(std::numeric_limits<float>::signaling_NaN())
  , tpc_CRLongestTrackDeflection(std::numeric_limits<float>::signaling_NaN())
  , tpc_CRLongestTrackDirY(std::numeric_limits<float>::signaling_NaN())
  , tpc_CRNHitsMax(std::numeric_limits<int>::max())
  , tpc_NuEigenRatioInSphere(std::numeric_limits<float>::signaling_NaN())
  , tpc_NuNFinalStatePfos(std::numeric_limits<int>::max())
  , tpc_NuNHitsTotal(std::numeric_limits<int>::max())
  , tpc_NuNSpacePointsInSphere(std::numeric_limits<int>::max())
  , tpc_NuVertexY(std::numeric_limits<float>::signaling_NaN())
  , tpc_NuWeightedDirZ(std::numeric_limits<float>::signaling_NaN())
  , tpc_StoppingChi2CosmicRatio(std::numeric_limits<float>::signaling_NaN())
  , pds_FMTotalScore(std::numeric_limits<float>::signaling_NaN())
  , pds_FMPE(std::numeric_limits<float>::signaling_NaN())
  , pds_FMTime(std::numeric_limits<float>::signaling_NaN())
  , crt_TrackScore(std::numeric_limits<float>::signaling_NaN())
  , crt_HitScore(std::numeric_limits<float>::signaling_NaN())
  , crt_TrackTime(std::numeric_limits<float>::signaling_NaN())
  , crt_HitTime(std::numeric_limits<float>::signaling_NaN())
{
}
