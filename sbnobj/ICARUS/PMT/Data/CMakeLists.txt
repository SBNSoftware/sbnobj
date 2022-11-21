cet_make(
  LIBRARIES
  NO_DICTIONARY
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::ICARUS_PMT_Data lardataobj::RawData)

install_headers()
install_source()
