cet_make_library(
  SOURCE
    CRTHit.cc
    CRTPMTMatching.cxx
    CRTTrack.cc
    CRTTzero.cc
  LIBRARIES
    cetlib_except::cetlib_except
    lardataobj::Simulation
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_CRT)

install_headers()
install_source()
