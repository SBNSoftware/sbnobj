cet_make_library(
  SOURCE
    ToF.cc
  LIBRARIES
    cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_ToF)

install_headers()
install_source()
