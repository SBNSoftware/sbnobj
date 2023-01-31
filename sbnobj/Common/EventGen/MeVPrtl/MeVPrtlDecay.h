#ifndef _MeVPrtlDecay_HH_
#define _MeVPrtlDecay_HH_

#include "TLorentzVector.h"

namespace evgen {
namespace ldm {
class MeVPrtlDecay {
public:
  TLorentzVector pos;

  // TODO: fix
  // By default there is no vector<TLorentzVector> dictionary 
  // available in art. I don't want to build this myself,
  // so don't use it as a workaround
  std::vector<TVector3> daughter_mom;
  std::vector<double> daughter_e;
  std::vector<int> daughter_pdg;

  // Total widths / distances for all possible decays
  double total_decay_width;
  double total_mean_lifetime;
  double total_mean_distance;

  // Fraction of width for allowed decays
  double allowed_decay_fraction;

};

} // end namespace ldm

} // end namespace evgen

#endif
