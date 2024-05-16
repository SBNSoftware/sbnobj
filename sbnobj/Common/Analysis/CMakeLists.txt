cet_make_library(
  SOURCE TPCPurityInfo.cc
  LIBRARIES cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_Analysis)

install_headers()
install_source()
