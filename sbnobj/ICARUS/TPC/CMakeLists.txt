file(GLOB lib_srcs *.cxx)
cet_make_library(SOURCE
                 ${lib_srcs}
                 LIBRARIES
                 PRIVATE
                 messagefacility::MF_MessageLogger
                 larcoreobj::headers
                 lardataobj::headers
               )

art_dictionary(DICTIONARY_LIBRARIES
		 sbnobj::ICARUS_TPC
                 lardataobj::RecoBase
                 lardataalg::headers
                 canvas::canvas
               )

install_headers()
install_source()
