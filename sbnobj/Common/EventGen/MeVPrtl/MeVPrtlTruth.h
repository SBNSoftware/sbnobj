#ifndef _MeVPrtlTruth_HH_
#define _MeVPrtlTruth_HH_

#include "TLorentzVector.h"
#include "MeVPrtlDecay.h"
#include "MeVPrtlFlux.h"
#include <array>

namespace evgen {
namespace ldm {

enum Generator {
  kUnknown=-1,
  kDissonantHiggs=0,
  kHNL=1
};

class MeVPrtlTruth {
public:
  TLorentzVector kaon_dmom;
  TLorentzVector kaon_dmom_beamcoord;
  TLorentzVector kaon_dpos_beamcoord;
  int kaon_pdg;
  TLorentzVector mevprtl_mom_beamcoord;
  TLorentzVector mevprtl_mom;
  TLorentzVector mevprtl_start;
  double equiv_enu;
  TVector3 mevprtl_enter;
  TVector3 mevprtl_exit;
  TLorentzVector decay_pos;

  // TODO: fix
  // By default there is no vector<TLorentzVector> dictionary 
  // available in art. I don't want to build this myself,
  // so don't use it as a workaround
  std::vector<TVector3> daughter_mom;
  std::vector<double> daughter_e;
  std::vector<int> daughter_pdg;
  double pot;
  double flux_weight;
  double ray_weight;
  double decay_weight;

  double mass;
  double C1;
  double C2;
  double C3;
  double C4;
  double C5;

  double decay_width;
  double mean_lifetime;
  double mean_distance;

  Generator gen;

  MeVPrtlTruth(const MeVPrtlFlux &flux, const MeVPrtlDecay &decay, std::array<TVector3, 2> inout, double flux_weight, double ray_weight, double decay_weight, double pot);
  MeVPrtlTruth() {} // Default initialize
};

} // end namespace ldm

} // end namespace evgen

#endif
