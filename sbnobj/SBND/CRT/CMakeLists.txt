cet_make( 
  LIBRARIES
    cetlib_except::cetlib_except
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_CRT)

install_headers()
install_source()
