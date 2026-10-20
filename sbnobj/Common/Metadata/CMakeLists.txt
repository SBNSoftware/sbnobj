file(GLOB lib_srcs *.cxx details/*)
cet_make_library(
  SOURCE
    ${lib_srcs}
  )

art_dictionary(
  DICTIONARY_LIBRARIES
    sbnobj::Common_Metadata
  )

install_headers(SUBDIRS details)
install_source()
