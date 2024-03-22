cet_make_library(
  SOURCE
    pmtTrigger.cc
  LIBRARIES
    cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_Trigger)

install_headers()
install_source()
