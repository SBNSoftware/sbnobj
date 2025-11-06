cet_make_library( LIBRARY_NAME sbndobj_BlipDataTypes
  SOURCE
    BlipDataTypes.cc
  LIBRARIES
    lardataobj::RecoBase
    nusimdata::SimulationBase
)
art_dictionary(DICTIONARY_LIBRARIES sbndobj_BlipDataTypes) 
install_headers()
install_source()
install_fhicl()
