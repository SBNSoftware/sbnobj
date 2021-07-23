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
  std::vector<float> daughter_e;
  std::vector<int> daughter_pdg;

  double decay_width;
  double mean_lifetime;
  double mean_distance;
};

} // end namespace ldm

} // end namespace evgen

#endif
