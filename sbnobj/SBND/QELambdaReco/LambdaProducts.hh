#ifndef SBND_LAMBDAPRODUCTS_H
#define SBND_LAMBDAPRODUCTS_H

#include <limits>

namespace qelambda {

    struct QELambdaReco {
        // bool  IsValid = false;
        int   SliceId = -1;

        // FRANS
        int   FransNUnassocOrigins       = -1;
        int   FransNMaxDirtUnassocHits   = -1;
        int   FransNAngles               = -1;
        float FransContainedPhi          = -999;
        int   FransPzsign                = 0;

        float FransScore                 = -999;
        float FransIota                  = -999;
        float FransDelta                 = -999;
        float FransEta                   = -999;
        float FransFitScore              = -999;

        // FRANS pfp id 
        int FransTrack1ID = -1;
        int FransTrack2ID = -1;
        int FransMainTrackID = -1;

        // Reco vertices
        float HyperonVtxX      = -999;
        float HyperonVtxY      = -999;
        float HyperonVtxZ      = -999;
        float PrimLeptonVtxX   = -999;
        float PrimLeptonVtxY   = -999;
        float PrimLeptonVtxZ   = -999;

        // Michel tagging
        int   MichelNMuonTracks  = -1;
        float MichelRssRatio     = -999;
        float MichelAngleQ80     = -999;
        float MichelDropRadius   = -999;
        int   MichelNBlips       = -1;
        float MichelScore        = -999;

        void SetDefault();
    };

} // namespace qelambda

#endif