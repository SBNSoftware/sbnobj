#include "KaonParent.h"
#include <cassert>

evgen::ldm::KaonParent::KaonParent(const simb::MCFlux &flux) {
  // set the particle codes
  switch (flux.fndecay) {
    case 1 /*K0L -> nue pi- e+ */:
    case 2 /*K0L -> nuebar pi+ e-*/:
    case 3 /* K0L -> numu pi- mu+*/:
    case 4 /*K0L -> numubar pi+ mu-*/:
      kaon_pdg = 130;
      break;
    case 5  /*K+  -> numu mu+*/:
    case 6  /*K+  -> nue pi0 e+*/:
    case 7  /*K+  -> numu pi0 mu+*/:
      kaon_pdg = 321;
      break;
    case 8  /*K-  -> numubar mu-*/:
    case 9  /*K-  -> nuebar pi0 e-*/:
    case 10 /*K-  -> numubar pi0 mu-*/:
      kaon_pdg = -321;
      break;
    default:
      kaon_pdg = 0;
      return; // not a kaon decay
  }
  mode = flux.fndecay;

  TVector3 pos3 = TVector3(flux.fvx, flux.fvy, flux.fvz);
  double time = flux.fxpoint; /* README: the MCFlux for some reason does not have any time variable, so I have chosen to canibalize this one, 
                              which according to documentation is just for debugging. (I am very sorry). */

  pos.SetVect(pos3);
  pos.SetT(time);


  // Get the mass from the available kinematics in the MCFlux

  // Get the magnitue of the beam slope drdz^2
  double drdz2 = flux.fppdxdz*flux.fppdxdz + flux.fppdydz*flux.fppdydz;

  // the total momentum is p/cos(theta) = p * sqrt(1 + drdz2)
  double production_momentum = flux.fpppz * sqrt(1 + drdz2);

  // And then we can use the total energy/momentum to get the mass
  //
  // This operation is dangerous numerically because for large energy we are relying 
  // on the cancellation of two large numbers to get a small number. I have tested that
  // this gives precise results to 6 digits up to the energies relevant for numi (50GeV),
  // provided one uses doubles.
  double mass = sqrt(flux.fppenergy*flux.fppenergy - production_momentum*production_momentum);

  mom.SetVectM(TVector3(flux.fpdpx, flux.fpdpy, flux.fpdpz), mass);

  weight = flux.fnimpwt;
}

