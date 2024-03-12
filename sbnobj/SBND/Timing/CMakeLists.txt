cet_make_library(
  SOURCE
    DAQTimestamp.cxx
  LIBRARIES
    cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_Timing)

install_headers()
install_source()
