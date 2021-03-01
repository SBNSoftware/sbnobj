/**
 * @file   sbnobj/Common/PMT/Data/classes.h
 * @author Gianluca Petrillo (petrillo@slac.stanford.edu)
 * @date   February 25, 2021
 * 
 * Enables dictionary definitions for:
 * 
 * * `sbn::PMTconfiguration`
 * 
 * See also `sbnobj/Common/PMT/Data/classes_def.xml`.
 */

// SBN libraries
#include "sbnobj/Common/PMT/Data/PMTconfiguration.h"

// framework libraries
#include "canvas/Persistency/Common/Wrapper.h"

// C++ libraries
#include <ostream>

namespace {
  
  sbn::PMTconfiguration PMTconfig;
  
} // local namespace
