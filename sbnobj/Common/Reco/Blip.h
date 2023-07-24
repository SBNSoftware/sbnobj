#ifndef sbncode_Blip_hh
#define sbncode_Blip_hh

#include <vector>
#include <map>

namespace sbn {

  struct TruthBlip {
    int ID = -9;
    int TPC = -9;
    float Time = -999e9;
    float Energy = 0;
    int DepElectrons = 0;
    int NumElectons = 0;
    float DriftTime = -9;
    int LeadG4ID = -9;
    int LeadG4Index = -9;
    int LeadG4PDG = -9;
    float LeadCharge = -9;
    float pos_x = -99999;
    float pos_y = -99999;
    float pos_z = -99999;
    std::map<int, float> G4ChargeMap;
    std::map<int, float> G4PDGMap;
    
  };

  class Blip {
  public:
    int ID = -9; //!< Blip ID/index
    bool isValid = false; //!< Blip passes set of checks
    int TPC = -9; //!< TPC ID
    int Cryostat = -9; //!< Cryostat ID
    int NPlanes = -9; //!< Number of matched planes
    int MaxWireSpan = -9; //!< Maximum span of wires on any plane cluster
    float ChargeADC = -999; //!< Charge (ADC) on calorimetry plane
    float ChargeElec = -999; //!< Charge (e-) on calorimetry plane
    float Energy = -999; //!< Energy (const dE/dx, configurable)
    float Time = -999; //!< Drift time in time ticks
    float ProxTrkDist = -9; //!< Distance to closest track
    float ProxTrkID = -9; //!< ID of closest track
    bool inCylinder = false; //!< Is it in a cone/cylinder region of another track?

    float pos_x; //!< x position
    float pos_y; //!< y position
    float pos_z; //!< z position
    float SigmaYZ = -9; //!< Uncertainty in YZ intersect [cm]
    float dX = -9; //!< Length along drift direction
    float dYZ = -9; //!< Approx. length scale in YZ space [cm]

    //Truth-matched energy deposition (for simulated events)
    sbn::TruthBlip truth;

  };
}
#endif
