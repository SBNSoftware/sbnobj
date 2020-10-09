cet_make( 
  LIBRARIES
    cetlib_except
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_ICARUS_CRT)

install_headers()
install_source()
