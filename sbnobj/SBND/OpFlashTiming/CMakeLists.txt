cet_make_library(
  SOURCE
    CorrectedOpFlashTiming.cc
  LIBRARIES
    cetlib_except::cetlib_except
    lardataobj::AnalysisBase
)

art_dictionary(DICTIONARY_LIBRARIES sbnobj_SBND_OpFlashTiming)