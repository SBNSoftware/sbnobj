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


# use cmake 3.12 or later
cmake_minimum_required (VERSION 3.12...3.14 FATAL_ERROR)

project(lardataobj LANGUAGES CXX)

# cetbuildtools contains our cmake modules
find_package(cetbuildtools REQUIRED)

list(APPEND CMAKE_MODULE_PATH
     $ENV{CANVAS_ROOT_IO_DIR}/Modules
     $ENV{ART_DIR}/Modules
#     ${CMAKE_CURRENT_SOURCE_DIR}/Modules
)

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic
  EXTRA_CXX_FLAGS -Wno-unused-local-typedefs
)

cet_report_compiler_flags()

# these are minimum required versions, not the actual product versions
find_ups_product( canvas )
find_ups_product( larcoreobj )
find_ups_product( larcorealg )
find_ups_product( lardataalg )
find_ups_product( nusimdata )
find_ups_boost( )
find_ups_root()
find_ups_product( cetbuildtools )

# macros for dictionary and simple_plugin
include(ArtDictionary)
include(ArtMake)
include(BuildPlugins)

# add cet_find_library commands here when needed

# ADD SOURCE CODE SUBDIRECTORIES HERE
add_subdirectory(sbnobj)

# tests
add_subdirectory(test)

# ups - table and config files
# must be AFTER all other subdirectories
add_subdirectory(ups)

# packaging utility - must be last
include(UseCPack)
