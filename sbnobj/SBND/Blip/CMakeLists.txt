cet_make_library(
  SOURCE
    BlipDataTypes.cc
  LIBRARIES
    ROOT::Core
)
art_dictionary(DICTIONARY_LIBRARIES sbnobj::BlipDataTypes)
install_headers()
install_source()
install_fhicl()
