cet_make_library(
  SOURCE
    CRTHit.cc
    CRTPMTMatching.cxx
    CRTTrack.cc
    CRTTzero.cc
    CRTT0TaggingInfo.cc
  LIBRARIES
    cetlib_except::cetlib_except
    lardataobj::Simulation
    larcorealg::Geometry
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_CRT)

install_headers()
install_source()
