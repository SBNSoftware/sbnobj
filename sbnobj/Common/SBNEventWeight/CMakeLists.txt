cet_make( 
  NO_DICTIONARY
  LIBRARIES
    cetlib_except::cetlib_except
    ${ROOT_BASIC_LIB_LIST}
    CLHEP::CLHEP
    ##art::Framework_Services_Registry
    ##art::Framework_Services_Optional_RandomNumberGenerator_service
)

art_dictionary(DICTIONARY_LIBRARIES sbnobj_Common_SBNEventWeight)

install_headers()
install_source()

