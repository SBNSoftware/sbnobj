cet_make_library(
  SOURCE
    MultiChannelOpticalTriggerGate.cxx
    OpticalTriggerGate.cxx
    SingleChannelOpticalTriggerGate.cxx
  LIBRARIES
    lardataalg::UtilitiesHeaders
    lardataobj::RawData
    larcorealg::CoreUtils
    cetlib_except::cetlib_except
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::ICARUS_PMT_Trigger_Data)

install_headers()
install_source()
