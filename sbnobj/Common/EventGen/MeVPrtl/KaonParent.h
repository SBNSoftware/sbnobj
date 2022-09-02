#ifndef _KaonParent_HH_
#define _KaonParent_HH_

#include "TLorentzVector.h"
#include "nusimdata/SimulationBase/MCFlux.h"
#include "TRotation.h"

namespace evgen {
namespace ldm {
class KaonParent {
public:
  TLorentzVector pos;
  TLorentzVector mom; //decay momentum
  TLorentzVector pmom; //production momentum
  int kaon_pdg;
  double weight;
  int mode;

  KaonParent() {} // Default initialize
  KaonParent(const simb::MCFlux &flux);
};

}
}

#endif
