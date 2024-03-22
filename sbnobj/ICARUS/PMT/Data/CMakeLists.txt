cet_make_library(
  SOURCE WaveformBaseline.cxx
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj::ICARUS_PMT_Data lardataobj::RawData)

install_headers()
install_source()
