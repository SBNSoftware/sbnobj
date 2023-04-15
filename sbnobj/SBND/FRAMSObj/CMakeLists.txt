cet_make(
  LIBRARIES
    cetlib_except::cetlib_except
    messagefacility::MF_MessageLogger
    larcorealg::Geometry
    lardataobj::AnalysisBase
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::SBND_FRAMSObj)

install_headers()
install_source()
