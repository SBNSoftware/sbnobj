#ifndef _MeVPrtlFlux_HH_
#define _MeVPrtlFlux_HH_

#include "TLorentzVector.h"

namespace evgen {
namespace ldm {
class MeVPrtlFlux {
public:
  TLorentzVector pos_beamcoord;
  TLorentzVector pos;
  TLorentzVector mmom_beamcoord;
  TLorentzVector mmom;
  TLorentzVector mom;
  TLorentzVector mom_beamcoord;
  TLorentzVector sec;
  TLorentzVector sec_beamcoord;
  double equiv_enu;
  double C1;
  double C2;
  double C3;
  double C4;
  double C5;
  double mass;
  double polarization;
  int meson_pdg;
  int secondary_pdg;
  int generator;

};
}
}

#endif
