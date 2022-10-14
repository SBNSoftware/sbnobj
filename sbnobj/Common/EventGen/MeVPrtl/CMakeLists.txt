find_package(dk2nudata REQUIRED)

cet_make(
  LIBRARIES
    cetlib_except::cetlib_except
    nusimdata::SimulationBase
    dk2nu::Tree
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_EventGen_MeVPrtl nusimdata::SimulationBase)

install_headers()
install_source()
