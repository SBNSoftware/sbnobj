# ======================================================================
#  sbnobj main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/sbnobj/ups/setup_for_development <-d|-p>
#  cmake [-DCMAKE_INSTALL_PREFIX=/install/path]
#        -DCMAKE_BUILD_TYPE=$CETPKG_TYPE
#        $CETPKG_SOURCE
#  make
#  make test
#  make install
#  make package (builds distribution tarfile)
# ======================================================================
cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

find_package(cetmodules 2.29.02 REQUIRED)
project(sbnobj VERSION 09.14.10 LANGUAGES CXX)

message(STATUS
  "\n-- ============================================================================="
  "\n-- === *** Start of configuration of ${PROJECT_NAME} ***"
  "\n-- ===")


include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic
  EXTRA_CXX_FLAGS -Wno-unused-local-typedefs
)

cet_report_compiler_flags(REPORT_THRESHOLD VERBOSE)

# these are minimum required versions, not the actual product versions
find_package( messagefacility REQUIRED )
find_package( canvas REQUIRED)
find_package( larcoreobj REQUIRED)
find_package( lardataobj REQUIRED)
find_package( larcorealg REQUIRED)
find_package( lardataalg REQUIRED)
find_package( nusimdata REQUIRED)
find_package( Boost COMPONENTS system)
find_package( ROOT REQUIRED)
find_package( CLHEP REQUIRED)

# macros for dictionary and simple_plugin
include(ArtDictionary)
include(CetMake)
include(BasicPlugin)

# add cet_find_library commands here when needed

# ADD SOURCE CODE SUBDIRECTORIES HERE
add_subdirectory(sbnobj)

# tests
add_subdirectory(test)

# ups - table and config files
# must be AFTER all other subdirectories

# packaging utility - must be last


message(STATUS
  "\n-- ==="
  "\n-- === *** End of configuration of ${PROJECT_NAME} ***"
  "\n-- ============================================================================="
  "\n-- "
  )
cet_cmake_config()
