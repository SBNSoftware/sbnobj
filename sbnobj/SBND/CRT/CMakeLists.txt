cet_make( 
  LIBRARIES
    cetlib_except::cetlib_except
    ${ROOT_BASIC_LIB_LIST}

  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_CRT)

install_headers()
install_source()
