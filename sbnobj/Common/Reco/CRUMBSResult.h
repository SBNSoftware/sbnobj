// Class for holding the result of the CRUMBS slice ID

#ifndef sbnobj_CRUMBSResult_H
#define sbnobj_CRUMBSResult_H

namespace sbn {
  class CRUMBSResult {
  public:

    CRUMBSResult(float score, float tpc_CRFracHitsInLongestTrack, float tpc_CRLongestTrackDeflection, float tpc_CRLongestTrackDirY, 
		 float tpc_CRNHitsMax, float tpc_NuEigenRatioInSphere, float tpc_NuNFinalStatePfos, float tpc_NuNHitsTotal, 
		 float tpc_NuNSpacePointsInSphere, float tpc_NuVertexY, float tpc_NuWeightedDirZ, float tpc_StoppingChi2CosmicRatio, 
		 float pds_FMTotalScore, float pds_FMPE, float pds_FMTime, float crt_TrackScore, float crt_HitScore, 
		 float crt_TrackTime, float crt_HitTime);
    CRUMBSResult(float score);
    CRUMBSResult();    
    
    float score;
    float tpc_CRFracHitsInLongestTrack;
    float tpc_CRLongestTrackDeflection;
    float tpc_CRLongestTrackDirY;
    float tpc_CRNHitsMax;
    float tpc_NuEigenRatioInSphere;
    float tpc_NuNFinalStatePfos;
    float tpc_NuNHitsTotal;
    float tpc_NuNSpacePointsInSphere;
    float tpc_NuVertexY;
    float tpc_NuWeightedDirZ;
    float tpc_StoppingChi2CosmicRatio;
    float pds_FMTotalScore;
    float pds_FMPE;
    float pds_FMTime;
    float crt_TrackScore;
    float crt_HitScore;
    float crt_TrackTime;
    float crt_HitTime;
  };
}

#endif
