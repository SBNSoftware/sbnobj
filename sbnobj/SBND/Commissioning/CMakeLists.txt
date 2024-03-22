cet_make_library(
  SOURCE
    MuonTrack.cc
  LIBRARIES
    cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_Commissioning lardataobj::RecoBase)

install_headers()
install_source()
