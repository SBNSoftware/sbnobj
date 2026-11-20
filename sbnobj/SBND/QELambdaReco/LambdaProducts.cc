// LambdaProducts.cc
#include "LambdaProducts.hh"

void qelambda::QELambdaReco::SetDefault() {
    SliceId = -1;

    // FRANS
    FransNUnassocOrigins       = -1;
    FransNMaxDirtUnassocHits   = -1;
    FransNAngles               = -1;
    FransContainedPhi          = -999;
    FransPzsign                = 0;
    
    FransScore                 = -999;
    FransIota                  = -999;
    FransDelta                 = -999;
    FransEta                   = -999;
    FransFitScore              = -999;

    // FRANS pfp id 
    FransTrack1ID = -1;
    FransTrack2ID = -1;
    FransMainTrackID = -1;

    // Reco vertices
    HyperonVtxX      = -999;
    HyperonVtxY      = -999;
    HyperonVtxZ      = -999;
    PrimLeptonVtxX   = -999;
    PrimLeptonVtxY   = -999;
    PrimLeptonVtxZ   = -999;

    MichelNMuonTracks  = -1;
    MichelRssRatio     = -999;
    MichelAngleQ80     = -999;
    MichelDropRadius   = -999;
    MichelNBlips       = -1;
    MichelScore        = -999;
}
