cet_make_library(
  SOURCE
    CorrectedOpFlashTiming.cc
  LIBRARIES
    cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_OpFlashTiming)

install_headers()
install_source()
