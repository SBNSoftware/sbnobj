cet_make(
  LIBRARIES
    cetlib_except::cetlib_except
    lardataobj::Simulation
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_CRT)

install_headers()
install_source()
