cet_make( 
  LIBRARIES
    cetlib_except
    ${MF_MESSAGELOGGER}
    ${ROOT_BASIC_LIB_LIST}
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_Common_Reco)

install_headers()
install_source()
