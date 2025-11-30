#ifndef BLIPDATATYPE
#define BLIPDATATYPE
#include "lardataobj/RecoBase/Hit.h"
#include "nusimdata/SimulationBase/MCParticle.h"
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"
#include <vector>
#include <map>
#include <set>

namespace blip {
  const int kNplanes    = 3; ///< Wire planes in a given tpc in this detector
  const int kNTPCs      = 2; ///< TPC in this detector

  /** Extra struct used in blip reco for grabbing key recob::hit information
 * Most attributes are grabbed directly from the recob::hit, but some, like charge, involve extra processing.
 */
  struct HitInfo {
    int   hitid         = -9; ///< Index of hit in recob::hit vector
    int   cryo          = -9; ///< cryostat containing hit. From geo::WireID
    int   tpc           = -9; ///< TPC containing hit. From geo::WireID
    int   plane         = -9; ///< Plane containing hit. From geo::WireID
    int   wire          = -9; ///< Wire containing hit. From geo::WireID
    int   chan          = -9; ///< Channel ID containing hit. From recob::Hit->Channel()
    float amp           = -9; ///< Amplitude of hit [ADC]
    float rms           = -9; ///< RMS of hit shape [ticks]
    int   trkid         = -9; ///< track ID from hit-track association object
    int   shwrid        = -9; ///< Depreciated
    int   clustid       = -9; ///< If this hit gets gathered into a cluster, what is the index of that cluster. All hits should be in a track or a cluster
    int   blipid        = -9; ///< If this hit gets gathered into a blip, what is the index of that blip.
    bool  ismatch       = false; ///< Depreciated
    float integralADC    = -999;  ///< Integral area from the recob::hit [ADCs-ticks]
    float sigmaintegral = -999;   ///< Uncertainty on the integralADC value [ADC-ticks]
    float sumADC        = -999;   ///<  [ADCs] from ROISummedADC method
    float charge        = -999;    ///<  Total charge as estimated from hit integral [e-]
    /*!
      Charge is reconstructed from calo::CalorimetryAlg ( "sbnd_calorimetryalgmc" )-> ElectronsFromADCArea function
      Configuration is in sbndcode/sbndcode/LArSoftConfigurations/calorimetry_sbnd.fcl
    */
    float peakTime      = -999999; ///< Hit peak time + a fcl-set per-plane offset [tick]
    float driftTime     = -999999; ///< Drift-time accounting for the interplane separation corrections [tick]
    float gof           = -9;     ///< GoodnessOfFit from recob::hit
    int   g4trkid       = -9;    ///< simb::MCParticle g4 track ID associated with this hit
    int   g4pdg         = -999;  ///< simb::MCParticle g4pdg
    int   g4charge      = -999;   ///< anab::BackTrackerHitMatchingData numelectrons [e-]
    float g4frac        = -99;    ///< anab::BackTrackerHitMatchingData ideNFraction, or fraction of energy in hit from this particle
    float g4energy      = -999;   ///< anab::BackTrackerHitMatchingData energy [MeV]
  };

/** True energy depositions 
   * std::vector<art::Ptr<simb::MCParticle> > makes a particle list
   * std::vector<sim::SimChannel> makes a IDE list
   * Together those make a blip::ParticleInfo object used to fill in this TrueBlip information
   * For a reconstructed MC blip we will record the true blip info associated with it
   * That blip reconstruction applies cuts to overall blip size/spread
   * A single TrueBlip will be constructed for energy depositions within TrueBlipMergeDist (fcl set 0.3 cm by default)
  */
  struct TrueBlip {
    int       ID            = -9;     ///<  Index of this trueBlip object
    int       Cryostat      = -9;     ///<  Cryostat ID the blip reconstructed to
    int       TPC           = -9;     ///<  TPC ID the blip reconstructed to
    float     Time          = -9;     ///<  Charge weighted peak time of TrueBlip energy depositions [tick]
    int       TimeTick      = -9;     ///<  Depreciated
    float     DriftTime     = -9;     ///<  Charge weighted drift time of TrueBlip energy depositions [tick]
    float     Energy        = 0;      ///<  Total energy dep [MeV]
    int       DepElectrons  = 0;      ///<  Total deposited electrons [e-]
    int       NumElectrons  = 0;      ///<  electrons reaching wires [e-]
    int       LeadG4ID      = -9;     ///<  G4 track ID depositing the most charge in this deposition 
    int       LeadG4Index   = -9;     ///<  G4 track Index depositing the most charge in this deposition 
    int       LeadG4PDG     = -9;     ///<  G4 PDG associated with the track depositing the most charge
    float     LeadCharge    = -9;     ///<  Largest charge deposition associated with this True Blip
    geo::Point_t  Position;               ///<  Charge weighted true-XYZ position [cm] //Used to be TVector3
    std::map<int,float>      G4ChargeMap; ///< Map from G4 particle track ID to deposited charge in this energy deposition  
    std::map<int,float>      G4PDGMap; ///< Map from G4 particle track ID to G4 PDG
  };

  /** Holder for MCTruth article data
   * Filled from std::vector<art::Ptr<simb::MCParticle> > (makes a particle list)
   * and std::vector<sim::SimChannel> (makes a IDE list)
   */
  struct ParticleInfo {
    simb::MCParticle particle;
    int   trackId           = -9;   ///< ID from GEANT4 track.
    int   index             = -9;   ///< Index in vector of simb::MCParticle 
    int   isPrimary         = -9;   ///< Bool value of simbMCParticle is Primary
    int   numTrajPts          = -9; ///< part.NumberTrajectoryPoints() from mcparticle
    double depEnergy         = -9;  ///< Total energy deposited across all interactions from this partcle [MeV]
    int   depElectrons        = -9; ///< Total electrons deposited across all interactions from this partcle [e-]
    double numElectrons      = -9;  ///< Depreciated
    double mass              = -9;  ///< simb::MCParticle mass [MeV]
    double E                 = -9;  ///< Starting simb::MCParticle energy [MeV]
    double endE              = -9;  ///< simb::MCParticle final energy [MeV]
    double KE                = -9;  ///< E - Mass [MeV]
    double endKE             = -9;  ///< EndE - Mass [MeV]
    double P                 = -9;  ///< Starting Magnitude of momentum vector [MeV/c]
    double Px                = -9;  ///< X-component of the momentum vector [MeV/c]
    double Py                = -9;  ///< Y-component of the momentum vector [MeV/c]
    double Pz                = -9;  ///< Z-component of the momentum vector [MeV/c]
    double pathLength        = -9; ///< Sum of distances between interaction vertecies within the active volume [cm]
    double time              = -9; ///< Time at birth [us]
    double endtime           = -9; ///< Time of final interaction [us]
    geo::Point_t startPoint;           ///< Starting Position of particle [cm] //Used to be TVector3
    geo::Point_t endPoint;             ///< End position of particle [cm]  //Used to be TVector3
    geo::Point_t position;             ///< Central position of the trajectory [cm]  //Used to be TVector3
  };

 /** Hit clusters are collections of adjacent hits on a single wire plane.
   *  They have a fcl-set maximum wire-span (fcl set. Default 10), as well as maximum tick-width (fcl set. Default 50 tick).
   *  Hit clusters have timestamp and associated wire IDs. 
   *  Within a hit cluster certain statistical summaries of the collection are saved including:
   *  Total charge, total charge uncertianty, peak hit amplitude, and charge weighted RMS hit spread
   */
  struct HitClust {
    int     ID              = -9;    ///< Per-plane index for the hit clusters. In SBND we save every collection plane hitcluster but not the induction
    bool    isValid         = false; ///< Bool check that every hit is in the same cryostat, tpc, plane. Should always be true for saved items
    int     CenterChan      = -999;  ///< Channel ID of the wire in the geometric center of the hit cluster
    int     CenterWire      = -999;  ///< Wire ID of the wire in the geometric center of the hit cluster
    bool    isTruthMatched  = false; ///< is there a trueBlip with the same leadG4ID as one of the G4IDs making up this cluster
    bool    isMerged        = false; ///< Depreciated internal flag for tracking blips before/after merge. 
    bool    isMatched       = false; ///< Is this hit cluster plane-matched into a full 3d blip
    int     DeadWireSep     = 99;    ///< Separation between the extreme ends of the hitcluster and the nearest dead wire. 
    /*!
      DeadWireSep can be between 0 and 5 and valid. Larger separations are filled in as 99.
    */
    int     Cryostat        = -9;   ///< cryostat for this hit cluster
    int     TPC             = -9;   ///< TPC for this hit cluster
    int     Plane           = -9;   ///< Plane index for this hit cluster
    int     NHits           = -9;   ///< Number of hits making up this hit cluster
    int     NWires          = -9;   ///< Wire span of the hit cluster
    float   ADCs            = -999; ///< ADC integral sum of hits making up the cluster [ADC-tick]
    float   Amplitude       = -999; ///< Max amplitude of hits making up the hit cluster [ADC]
    float   Charge          = -999; ///< Total charge of hits making up the hit cluster [e-]
    /*!
      Charge is reconstructed from calo::CalorimetryAlg ( "sbnd_calorimetryalgmc" )-> ElectronsFromADCArea function
      Configuration is in sbndcode/sbndcode/LArSoftConfigurations/calorimetry_sbnd.fcl
    */
    float   SigmaCharge     = -999; ///< charge-weighted charge uncertainties for this hit-cluster [e-]
    float   TimeTick        = -999; ///< charge-weighted average hit-peak-times for this hit-cluster [tick]
    float   Time            = -999; ///< charge-weighted average hit-peak-times for this hit-cluster [us]
    float   StartHitTime    = -999; ///< Depreciated
    float   EndHitTime      = -999; ///< Depreciated
    float   StartTime       = -999; ///< Minimum -1 sigma time of a hit in this cluster [us]
    float   EndTime         = -999; ///< Max +1 sigma time of a hit in this cluster [us]
    float   Timespan        = -999; ///< Hit cluster EndTime - StartTime [us]
    float   RMS             = -999; ///< Quadrature estimate of charge waveform timespread accounting for varied hit-drift times and internal hit-RMS [us]
    int     StartWire       = -999; ///< Lowest wireID involved with the hitcluster 
    int     EndWire         = -999; ///< Highest wireID involved with the hit cluster
    int     NPulseTrainHits = -9;  ///< Number of hits with a GoodnessOfFit<0 involved in this hit cluster
    float   GoodnessOfFit   = -999; ///< Charge weighted hit-GoodnessofFit param
    int     BlipID          = -9; ///< If this hit cluster ended up in a blip, what is its ID
    int     EdepID          = -9; ///< If this hit cluster is MC-matched what is the trueBlip ID
    std::set<int>     HitIDs; ///< Index of the recob::hit objects making up this cluster
    std::set<int>     Wires; ///<  Set of geo::wireIDs contributing hits to this cluster
    std::set<int>     Chans; ///<  Set of raw::ChannelID_t contributing hits to this cluster
    std::set<int>     G4IDs; ///<  simb::MCParticle track ID contributing hits to this cluster
    std::map<int,geo::Point_t> IntersectLocations; ///< Internal reconstruction variable for recording where hit-clusters on different planes would overlap //used to be TVector3
  };


  /** Blips are small, plane-matched, energy deposition in liquid argon with sizes similar to wire separation.
 *  Blips are composed of hit-clusters, which are (time and space) adjacent hits on a single wire plane. 
 *  A single plane, usually the collection, is given a privledged position as the calorimetry plane. 
 *  Every hit-cluster on the calorimetry plane is checked for matches on the other two planes, and when multiple possible pairs are found 
 *  the highest scoring one is selected. 
 *  Score components include cluster charge, cluster time duration, cluster peak time, and wire intersections. 
 */
  struct Blip {
    int       ID              = -9;         ///< Internal index for blip labelling
    bool      isValid         = false;      ///< Blip passes basic checks in reco. All blips saved to artRoot file should be valid.
    int       Cryostat        = -9;         ///< Which cryostat the blip was reconstructed to. For SBND this should always be 0.
    int       TPC             = -9;         ///< Which tpc the blip was reconstructed to. For SBND this may be 0 or 1. 
    int       NPlanes         = -9;         ///< Number of planes matched to build the blip. Blips must be plane matched so this should be 2+ planes.
    int       MaxWireSpan     = -9;         ///< Maximum span of wires on any plane hit-cluster
    float     TimeTick        = -999;       ///< Average time of hitclusters making up blips. [tpc tick]
    /*!
      Hit cluster time is the charge-weighted average of the hit-peak times for hits in the cluster 
    */
    float     Time            = -999;       ///< Average time of hitclusters making up blips. [us] 
    /*!
      Hit cluster time is the charge-weighted average of the hit-peak times for hits in the cluster 
    */
    float     Charge          = -9;         ///< Charge on calorimetry plane [e-]
    float     Energy          = -999;       ///< Reconstructed energy in the calorimetry plane (const dE/dx, fcl-configurable) [MeV]
    float     EnergyESTAR     = -999;       ///< Reconstructed energy in the calorimetry plane (ESTAR method from ArgoNeuT)    [MeV]
    float     EnergyPSTAR     = -999;       ///< Reconstructed energy in the calorimetry plane (PSTAR method similar with ESTAR method from ArgoNeuT) [MeV]
    float     ProxTrkDist     = -9;         ///< 3-D distance to closest track, assuming the blip was concident with event trigger [cm]
    /*!
      for properly flash matched out-of-time tracks this distance will be wrong! The blips have no such flash matching ability as of yet
    */
    int       ProxTrkID       = -9;         ///< index of the of closest track, assuming the blip was concident with event trigger
    bool      inCylinder      = false;      ///< Bool for whether this blip falls in a 45 degree cone relative to any track closer than fcl-set CylinderRadius (15 cm)
    /*!
      please note the blip X position is unreliable, so these distance and 3-d position derived variables may be incorrect
    */
    geo::Point_t  Position;                 ///< 3D position vector. Reconstructed with wrong t0! [cm]
    float     SigmaYZ         = -9.;        ///< Uncertainty in YZ intersect [cm]
    float     dX              = -9;         ///< Equivalent length along drift direction [cm] 
    float     dYZ             = -9;         ///< Approximate length scale in YZ space [cm]
    std::array<blip::HitClust, kNplanes> clusters; ///< Plane/cluster-specific information. Just contains hit clusters making up this blip!
    blip::TrueBlip truth; ///< Truth-matched energy deposition. Just contains the relevant MC truth info to this blip!
    double X() { return Position.X(); }
    double Y() { return Position.Y(); }
    double Z() { return Position.Z(); }
    
  };
}
#endif
