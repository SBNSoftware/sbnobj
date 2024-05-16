cet_make_library(
  SOURCE
    MeVPrtlTruth.cxx
    MesonParent.cxx
  LIBRARIES
    cetlib_except::cetlib_except
    nusimdata::SimulationBase
    dk2nu::Tree
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_EventGen_MeVPrtl nusimdata::SimulationBase)

install_headers()
install_source()
