cet_make(
  LIBRARIES
    lardataobj::RawData
    larcorealg::CoreUtils
    cetlib_except::cetlib_except
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::ICARUS_PMT_Trigger_Data)

install_headers()
install_source()
