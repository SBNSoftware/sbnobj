cet_make_library(
  SOURCE
    CRTCluster.cxx
    CRTData.cxx
    CRTEnums.cxx
    CRTSpacePoint.cxx
    CRTStripHit.cxx
    CRTTrack.cxx
    CRTBlob.cxx
    CRTVeto.cxx
    FEBData.cxx
    FEBTruthInfo.cxx
  LIBRARIES
    cetlib_except::cetlib_except
    lardataobj::Simulation
    lardataobj::RecoBase
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::SBND_CRT)

install_headers()
install_source()
