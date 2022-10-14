cet_make(
  LIBRARIES
    ROOT::Core
  NO_DICTIONARY
)


art_dictionary(DICTIONARY_LIBRARIES sbnobj_Common_Trigger)

install_headers()
install_source()
