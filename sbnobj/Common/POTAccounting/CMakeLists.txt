cet_make_library(
  SOURCE
    BNBSpillInfo.cc
    EXTCountInfo.cc
    NuMISpillInfo.cc
  LIBRARIES
    cetlib_except::cetlib_except
    ROOT::Core
  )

art_dictionary(DICTIONARY_LIBRARIES sbnobj_Common_POTAccounting)

install_headers()
install_source()
