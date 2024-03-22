cet_make_library(
  SOURCE
    CRTData.cc
  LIBRARIES
    cetlib_except::cetlib_except
    lardataobj::Simulation
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::ICARUS_CRT)

install_headers()
install_source()
