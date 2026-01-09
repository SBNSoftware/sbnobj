#ifndef SBN_TrackCaloSkimmerObj
#define SBN_TrackCaloSkimmerObj

#include <limits> // for std::numeric_limits
#include <cstdint>
#include <vector>

namespace sbn {
  struct Vector3D {
    float x = std::numeric_limits<float>::signaling_NaN();
    float y = std::numeric_limits<float>::signaling_NaN();
    float z = std::numeric_limits<float>::signaling_NaN();
  };

  struct WireInfo {
    uint16_t wire    = uint16_t(-1); //!< Wire number
    uint16_t plane   = uint16_t(-1); //!< Plane number
    uint16_t tpc     = uint16_t(-1); //!< TPC number
    uint16_t channel = uint16_t(-1); //!< Channel number
    int16_t tdc0     = int16_t(-1) ; //!< TDC tick of the first ADC value
    std::vector<short> adcs;         //!< List of ADC values
  };

  struct HitTruth {
    float e     = std::numeric_limits<float>::signaling_NaN();
    float nelec = std::numeric_limits<float>::signaling_NaN();
  };

  struct HitInfo {
    float integral   = -1.f;         //!< Integral of gaussian fit to ADC values in hit [ADC]
    float sumadc     = -1.f;         //!< "SummedADC" -- sum of ADC values under gaussian fit [ADC]
    float width      = -1.f;         //!< Width of fitted gaussian hit [ticks]
    float goodness   = -1.f;         //!< Goodness-of-fit of fitted gaussian hit
    Vector3D sp;                     //!< Space-Point Position of hit [cm]
    float time       = -1.f;         //!< Peak time of hit [ticks]
    int id           = -1;           //!< ID of hit
    uint16_t channel = uint16_t(-1); //!< Channel number of hit
    uint16_t wire    = uint16_t(-1); //!< Wire number of hit
    uint16_t plane   = uint16_t(-1); //!< Plane number of hit
    uint16_t tpc     = uint16_t(-1); //!< TPC number of hit
    uint16_t mult    = uint16_t(-1); //!< Multiplicity of hit
    int16_t start     = -1;          //!< Start tick of hit [ticks]
    int16_t end       = -1;          //!< End tick of hit [ticks]
    bool hasSP        = false;       //!< Whether the hit has a SpacePoint

    HitTruth truth;
  };

  struct TrackHitInfo {
    HitInfo h;                         //!< Hit information by itself
    float pitch = -1.f;                //!< Pitch of track across wire the hit is on [cm]
    float dqdx  = -1.f;                //!< Initial computed dq/dx of hit [ADC/cm]
    float rr    = -1.f;                //!< Residual range of hit along track [cm]
    Vector3D tp;                       //!< Track Trajectory position of hit [cm]
    Vector3D dir;                      //!< Direction of track at hit location
    uint16_t i_snippet = uint16_t(-1); //!< Index of hit into snippet 
    bool ontraj = false;               //!< Whether the hit is on the track trajectory
    bool oncalo = false;               //!< Whether the hit is on the track calorimetry
  };

  struct MetaInfo {
    int run    = -1;                //!< Run number 
    int evt    = -1;                //!< Event number 
    int subrun = -1;                //!< Subrun number
    uint64_t time = uint64_t(-1);   //!< Timestamp
    int ifile  = -1;                //!< Index of file into processing
    int iproc  = -1;                //!< Index of process number into processing (useful for grid)
  };

  struct TrueHit {
    int16_t cryo    = -1001;                                          //!< Cryostat of hit
    int16_t tpc     = -1;                                          //!< TPC of hit
    int16_t plane   = -1;                                          //!< Plane of hit
    int wire        = -1;                                          //!< Wire of hit
    int channel     = -1;                                          //!< Channel of hit
    unsigned ndep   = 0u;                                          //!< Number of depositions in hit
    float nelec     = 0.f;                                         //!< Number of electrons in hit
    float e         = 0.f;                                         //!< energy in hit [MeV]
    float pitch     = 0.f;                                         //!< Track pitch for hit, using true direction [cm]
    float pitch_sce = 0.f;                                         //!< Track pitch for hit, after distortion to pitch caused by space charge [cm]
    float rr        = 0.f;                                         //!< Track residual range for hit [cm]
    int itraj = -1;                                                //!< Index of hit along trajectory
    Vector3D p;                                                    //!< Location of hit, computed after space charge [cm]
    Vector3D p_scecorr;                                            //!< Location of the hit after un-doing space charge [cm]
    Vector3D p_width;                                              //!< Width of depositions going into hit [cm^2]
    Vector3D p_scecorr_width;                                      //!< Width of depositions going into hit after un-doing space charge [cm^2]
    float time   = std::numeric_limits<float>::signaling_NaN();    //!< Time of hit [ticks]
    float tdrift = std::numeric_limits<float>::signaling_NaN();    //!< Drift time [us]
  };

  struct TrueParticle {
    float    plane0VisE = std::numeric_limits<float>::signaling_NaN();  //!< Sum of energy deposited on plane 0 (1st Ind.) [GeV]
    float    plane1VisE = std::numeric_limits<float>::signaling_NaN();  //!< Sum of energy deposited on plane 1 (2nd Ind.) [GeV]
    float    plane2VisE = std::numeric_limits<float>::signaling_NaN();  //!< Sum of energy deposited on plane 2 (Col.) [GeV]
    
    float    genE   = std::numeric_limits<float>::signaling_NaN();      //!< Energy at generation pt [GeV]
    float    startE = std::numeric_limits<float>::signaling_NaN();      //!< Energy at first pt in active TPC volume [GeV]
    float    endE   = std::numeric_limits<float>::signaling_NaN();      //!< Energy at last pt in active TPC volume [GeV]
    float    genT   = std::numeric_limits<float>::signaling_NaN();      //!< Start time of gen point [mus -- t=0 is spill time]
    float    startT = std::numeric_limits<float>::signaling_NaN();      //!< Start time of first TPC point [mus -- t=0 is spill time]
    float    endT   = std::numeric_limits<float>::signaling_NaN();      //!< End time last point in the active [mus -- t=0 is spill time]
    float    length = std::numeric_limits<float>::signaling_NaN();      //!< Trajectory length in active TPC volume the particle first enters [cm]
    
    unsigned plane0nhit = 0;                                            //!< Number of hits on plane 0 (1st Ind.)
    unsigned plane1nhit = 0;                                            //!< Number of hits on plane 1 (2nd Ind.)
    unsigned plane2nhit = 0;                                            //!< Number of hits on plane 2 (Col.)
    
    Vector3D genp;                                                      //!< Momentum at generation point [GeV/c]
    Vector3D startp;                                                    //!< Momentum at first point in the active TPC volume [GeV/c]
    Vector3D endp;                                                      //!< Momentum at last point in the active TPC volume [GeV/c]
    Vector3D gen;                                                       //!< Generation position [cm]
    Vector3D start;                                                     //!< Start position in the active TPC volume [cm]
    Vector3D end;                                                       //!< End position in the active TPC volume [cm]
    
    int   wallin  = -1;                                                 //!< Wall of cryostat particle enters (wNone if starting in detector)
    int   wallout = -1;                                                 //!< Wall of cryostat particle exits (wNone if stopping in detector)
    
    bool     cont_tpc    = false;                                       //!< Whether the particle is contained in a single TPC
    bool     crosses_tpc = false;                                       //!< Whether the particle crosses a TPC boundary
    bool     contained   = false;                                       //!< Whether the particle is contained in a single active volume
    
    int       pdg = -1;                                                 //!< Particle ID code
    int      G4ID = -1;                                                 //!< ID of the particle (taken from G4 -- -1 if this particle is not propogated by G4)
    int    parent = -1;                                                 //!< ID of parent particle
    
    int   start_process = -1;                                           //!< Start G4 process of the particle. Values defned as enum in StandardRecord
    int   end_process   = -1;                                           //!< End G4 process of the particle. Values defined as enum in StandardRecord
    
    std::vector<TrueHit> truehits0;                                     //!< List of True "hits" of this particle on Plane 0
    std::vector<TrueHit> truehits1;                                     //!< List of True "hits" of this particle on Plane 1
    std::vector<TrueHit> truehits2;                                     //!< List of True "hits" of this particle on Plane 2
    
    std::vector<Vector3D> traj;                                         //!< True trajectory of particle
    std::vector<Vector3D> traj_sce;                                     //!< True trajectory of particle, deflected by space charge
  };

  struct TrackTruth {
    TrueParticle p;                                           //!< Truth information on particle
    TrueParticle michel;                                      //!< Truth information on daughter-Michel-electron. Invalid if it doesn't exist
    float pur  = std::numeric_limits<float>::signaling_NaN(); //!< Purity of truth matching
    float eff  = std::numeric_limits<float>::signaling_NaN(); //!< Efficiency of truth matching
    float depE = std::numeric_limits<float>::signaling_NaN(); //!< Total deposited energy of hits matched to track [GeV]
  };

  struct TrackInfo {
    MetaInfo meta;                                                 //!< Meta-data associated with this track
    std::vector<TrackHitInfo> hits0;                               //!< List of hits on plane 0
    std::vector<TrackHitInfo> hits1;                               //!< List of hits on plane 1
    std::vector<TrackHitInfo> hits2;                               //!< List of hits on plane 2
    std::vector<WireInfo> wires0;                                  //!< List of wire information on plane 0
    std::vector<WireInfo> wires1;                                  //!< List of wire information on plane 1
    std::vector<WireInfo> wires2;                                  //!< List of wire information on plane 2

    float t0PFP            = std::numeric_limits<float>::lowest(); //!< Particle-Flow-Particle (Pandora) T0. Derived from cathode crossing
    float t0CRTTrack       = std::numeric_limits<float>::lowest(); //!< t0 from CRT Track (SBND)
    float t0CRTHit         = std::numeric_limits<float>::lowest(); //!< t0 from CRT Hit (ICARUS)
    float t0CRTSpacePoint  = std::numeric_limits<float>::lowest(); //!< t0 from CRT SpacePoint (SBND)
    float crtMatchingScore = std::numeric_limits<float>::lowest(); //<! An assessment of the quality of the match made for whicht0 == 1,2,3
    int whicht0     = -1;                                          //!< Which T0 producer was used to tag. 0 is Pandora, 1 is CRTTrack 2 is CRTHit, 3 is CRTSpacePoint
    float xShiftCRT = 0.f;                                         //<! If whicht0 == 1,2,3 the amount by which the track was shifted in x
    int id          = -1;                                          //!< ID of track
    int cryostat    = -1000;                                          //!< Cryostat number of track
    bool clear_cosmic_muon = false;                                //!< Whether Pandora thinks the track is "clearly" a cosmic
    Vector3D start;                                                //!< Start position of track [cm]
    Vector3D end;                                                  //!< End position of track [cm]
    Vector3D dir;                                                  //!< Direction of track 
    Vector3D PCAdir;                                               //!< Track Direction as fitted from PCA 
    float length = -1.;                                            //!< Length of track [cm]

    float hit_min_time_p0_tpcE = -100000.f;                        //!< Min hit time of track on plane 0 TPC E
    float hit_max_time_p0_tpcE = -100000.f;                        //!< Max hit time of track on plane 0 TPC E
    float hit_min_time_p1_tpcE = -100000.f;                        //!< Min hit time of track on plane 1 TPC E
    float hit_max_time_p1_tpcE = -100000.f;                        //!< Max hit time of track on plane 1 TPC E
    float hit_min_time_p2_tpcE = -100000.f;                        //!< Min hit time of track on plane 2 TPC E
    float hit_max_time_p2_tpcE = -100000.f;                        //!< Max hit time of track on plane 2 TPC E
    float hit_min_time_p0_tpcW = -100000.f;                        //!< Min hit time of track on plane 0 TPC W
    float hit_max_time_p0_tpcW = -100000.f;                        //!< Max hit time of track on plane 0 TPC W
    float hit_min_time_p1_tpcW = -100000.f;                        //!< Min hit time of track on plane 1 TPC W
    float hit_max_time_p1_tpcW = -100000.f;                        //!< Max hit time of track on plane 1 TPC W
    float hit_min_time_p2_tpcW = -100000.f;                        //!< Min hit time of track on plane 2 TPC W
    float hit_max_time_p2_tpcW = -100000.f;                        //!< Max hit time of track on plane 2 TPC W
    
    float const_fit_C = -1.;                                       //!< Fit parameter
    float const_fit_residuals = -1.;                               //!< Fit parameter
    float exp_fit_A = -1.;                                         //!< Fit parameter
    float exp_fit_R = -1.;                                         //!< Fit parameter
    float exp_fit_residuals = -1.;                                 //!< Fit parameter
    int n_fit_point = -1;                                          //!< Fit parameter
    
    int selected  = -1;                                            //!< Index of the tool that selected this track
    int nprescale = -1;                                            //!< Prescale of the tool that selected this track

    std::vector<int> daughter_pdg;                                 //!< Pandora PDG codes of daughter PFP's
    std::vector<unsigned> daughter_nsp;                            //!< Number of space points in each daughter
    std::vector<float> daughter_sp_toend_dist;                     //!< Smallest distance from any daughter Space Point to Track End [cm]
                    
    std::vector<float> tracks_near_end_dist;                       //!< List of tracks near the end of this track
    std::vector<float> tracks_near_end_costh;                      //!< List of tracks near the end of this track

    std::vector<float> tracks_near_start_dist;                     //!< List of tracks near the start of this track
    std::vector<float> tracks_near_start_costh;                    //!< List of tracks near the start of this track

    std::vector<HitInfo> endhits;                                  //!< List of hits near the endpoint of the track on the collection plane

    TrackTruth truth;                                              //!< Truth-matching information
  };

}

#endif
