cet_make_library(
  SOURCE
    CNNScore.cc
    CRUMBSResult.cc
    FlashTriggerPrimitive.cc
    LightCalo.cc
    MVAPID.cc
    MergedTrackInfo.cc
    OpT0FinderResult.cc
    RangeP.cc
    ScatterClosestApproach.cc
    ShowerSelectionVars.cc
    SimpleFlashMatchVars.cc
    StoppingChi2Fit.cc
    Stub.cxx
    TPCPMTBarycenterMatch.cc
    VertexHit.cc
  LIBRARIES
    cetlib_except::cetlib_except
    messagefacility::MF_MessageLogger
    larcorealg::Geometry
    lardataobj::AnalysisBase
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_Reco)

install_headers()
install_source()
