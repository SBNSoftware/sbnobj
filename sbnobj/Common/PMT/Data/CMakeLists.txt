cet_make_library(
  SOURCE
    PMTBeamSignal.cxx
    PMTconfiguration.cxx
    V1730Configuration.cxx
    V1730channelConfiguration.cxx
  LIBRARIES
    messagefacility::MF_MessageLogger
    lardataobj::RawData
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_PMT_Data)

install_headers()
install_source()
