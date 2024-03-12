cet_make_library(
  SOURCE
    ExtraTriggerInfo.cxx
  LIBRARIES
    ROOT::Core
)


art_dictionary(DICTIONARY_LIBRARIES sbnobj_Common_Trigger)

install_headers()
install_source()
