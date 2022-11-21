cet_make(
  LIBRARIES
  lardataobj::RawData
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::Common_PMT_Data)

install_headers()
install_source()
