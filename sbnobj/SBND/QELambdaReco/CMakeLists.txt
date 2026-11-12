cet_make_library(
  LIBRARY_NAME SBND_qelambda
  SOURCE LambdaProducts.cc
  SOURCE LambdaPID.cc
  LIBRARIES
    ROOT::Core
    lardataobj::RecoBase
)

art_dictionary(
  DICTIONARY_LIBRARIES
    sbnobj::SBND_qelambda
)

install_headers()
install_source()