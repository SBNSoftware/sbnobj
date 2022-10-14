find_package(dk2nudata REQUIRED)
cet_make(
  NO_DICTIONARY
  LIBRARIES
    cetlib_except::cetlib_except
    ROOT::Matrix
    ROOT::Core
    CLHEP::CLHEP
    nusimdata::SimulationBase
    dk2nu::Tree
)

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_SBNEventWeight)

install_headers()
install_source()

