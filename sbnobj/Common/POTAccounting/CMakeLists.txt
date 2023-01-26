cet_make(
  LIBRARIES
    cetlib_except::cetlib_except
    ROOT::Core
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_Common_POTAccounting)

install_headers()
install_source()
