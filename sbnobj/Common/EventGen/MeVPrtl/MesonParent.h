#ifndef _MesonParent_HH_
#define _MesonParent_HH_

#include "TLorentzVector.h"
#include "nusimdata/SimulationBase/MCFlux.h"
#include "TRotation.h"

namespace evgen {
namespace ldm {
class MesonParent {
public:
  TLorentzVector pos;
  TLorentzVector mom;
  int meson_pdg;
  double weight;
  int mode;

  MesonParent() {} // Default initialize
  MesonParent(const simb::MCFlux &flux);
  bool isKaon() const {return abs(meson_pdg) == 321 || meson_pdg == 130;}
};

}
}

#endif
