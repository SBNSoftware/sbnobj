file(GLOB lib_srcs *.cxx)
cet_make_library(SOURCE
                 ${lib_srcs}
                 LIBRARIES
                 PUBLIC
                 larcoreobj::headers
                 lardataobj::headers
               )

art_dictionary(DICTIONARY_LIBRARIES
                 sbnobj::ICARUS_TPC
               )

install_headers()
install_source()
