cet_make_library(
  SOURCE
    ChannelROICreator.cxx
  LIBRARIES
    sbnobj::ICARUS_TPC
    lardataobj::AnalysisBase
  )

install_headers()
install_source()
