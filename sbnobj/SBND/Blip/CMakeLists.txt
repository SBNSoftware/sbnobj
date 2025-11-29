cet_make_library( 
  SOURCE
    BlipDataTypes.cc
  LIBRARIES
    lardataobj::RecoBase
    nusimdata::SimulationBase
    larcorealg::Geometry
)
art_dictionary(DICTIONARY_LIBRARIES sbnobj::SBND_Blip) 
install_headers()
install_source()
install_fhicl()
