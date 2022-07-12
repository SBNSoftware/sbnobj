#ifndef SBN_TrackCaloSkimmerObj
#define SBN_TrackCaloSkimmerObj

#include <climits>

#include <vector>

namespace sbn {
  struct Vector3D {
    float x;
    float y;
    float z;

    Vector3D():
      x(std::numeric_limits<float>::signaling_NaN()),
      y(std::numeric_limits<float>::signaling_NaN()),
      z(std::numeric_limits<float>::signaling_NaN())
    {}

  };

  struct WireInfo {
    uint16_t wire; //!< Wire number
    uint16_t plane; //!< Plane number
    uint16_t tpc; //!< TPC number
    uint16_t channel; //!< Channel number
    int16_t tdc0; //!< TDC tick of the first ADC value
    std::vector<short> adcs; //!< List of ADC values

    WireInfo():
      wire((uint16_t)-1),
      plane((uint16_t)-1),
      tpc((uint16_t)-1),
      tdc0((uint16_t)-1) {}

  };

  struct HitTruth {
    float e;
    float nelec;
  };

  struct HitInfo {
    float integral; //!< Integral of gaussian fit to ADC values in hit [ADC]
    float sumadc; //!< "SummedADC" -- sum of ADC values under gaussian fit [ADC]
    float width; //!< Width of fitted gaussian hit [ticks]
    Vector3D sp; //!< Space-Point Position of hit [cm]
    float time; //!< Peak time of hit [ticks]
    int id; //!< ID of hit
    uint16_t channel; //!< Channel number of hit
    uint16_t wire; //!< Wire number of hit
    uint16_t plane; //!< Plane number of hit
    uint16_t tpc; //!< TPC number of hit
    uint16_t mult; //!< Multiplicity of hit
    int16_t start; //!< Start tick of hit [ticks]
    int16_t end; //!< End tick of hit [ticks]
    bool hasSP; //!< Whether the hit has a SpacePoint

    HitTruth truth;

    HitInfo():
      integral(-1),
      sumadc(-1),
      width(-1),
      time(-1),
      id(-1),
      channel((uint16_t)-1),
      wire((uint16_t)-1),
      plane((uint16_t)-1),
      tpc((uint16_t)-1),
      mult((uint16_t)-1),
      start(-1),
      end(-1) {}
  };

  struct TrackHitInfo {
    HitInfo h; //!< Hit information by itself
    float pitch; //!< Pitch of track across wire the hit is on [cm]
    float dqdx; //!< Initial computed dq/dx of hit [ADC/cm]
    float rr; //!< Residual range of hit along track [cm]
    Vector3D tp; //!< Track Trajectory position of hit [cm]
    Vector3D dir; //!< Direction of track at hit location
    uint16_t i_snippet; //!< Index of hit into snippet 
    bool ontraj; //!< Whether the hit is on the track trajectory
    bool oncalo; //!< Whether the hit is on the track calorimetry

    TrackHitInfo():
      pitch(-1),
      dqdx(-1),
      rr(-1),
      i_snippet((uint16_t)-1),
      ontraj(false),
      oncalo(false) {}

  };

  struct MetaInfo {
    int run; //!< Run number 
    int evt; //!< Event number 
    int subrun; //!< Subrun number
    uint64_t time; //!< Timestamp
    int ifile; //!< Index of file into processing
    int iproc; //!< Index of process number into processing (useful for grid)

   MetaInfo():
     run(-1),
     evt(-1),
     subrun(-1),
     ifile(-1),
     iproc(-1) {}
  };

  struct TrueHit {
    int16_t cryo; //!< Cryostat of hit
    int16_t tpc; //!< TPC of hit
    int16_t plane; //!< Plane of hit
    int wire; //!< Wire of hit
    int channel; //!< Channel of hit

    unsigned ndep; //!< Number of depositions in hit
    float nelec; //!< Number of electrons in hit
    float e; //!< energy in hit [MeV]
    float pitch; //!< Track pitch for hit, using true direction [cm]
    float pitch_sce; //!< Track pitch for hit, after distortion to pitch caused by space charge [cm]
    
    float rr; //!< Track residual range for hit [cm]
    int itraj; //!< Index of hit along trajectory
    Vector3D p; //!< Location of hit, computed after space charge [cm]
    Vector3D p_scecorr; //!< Location of the hit after un-doing space charge [cm]
    Vector3D p_width; //!< Width of depositions going into hit [cm^2]
    Vector3D p_scecorr_width; //!< Width of depositions going into hit after un-doing space charge [cm^2]
    float time; //!< Time of hit [ticks]
    float tdrift; //!< Drift time [us]

    TrueHit():
      cryo(-1),
      tpc(-1),
      wire(-1),
      channel(-1),
      ndep(0),
      nelec(0.),
      e(0.),
      pitch(0.),
      rr(0.),
      itraj(-1),
      time(0.)
      {
        // set the location to 0.
        p.x = 0;
        p.y = 0;
        p.z = 0;

        p_scecorr.x = 0;
        p_scecorr.y = 0;
        p_scecorr.z = 0;

        p_width.x = 0;
        p_width.y = 0;

        p_scecorr_width.z = 0;
        p_scecorr_width.x = 0;
        p_scecorr_width.y = 0;
        p_scecorr_width.z = 0;
      }
  };

  struct TrueParticle {
    float    plane0VisE;   //!< Sum of energy deposited on plane 0 (1st Ind.) [GeV]
    float    plane1VisE;   //!< Sum of energy deposited on plane 1 (2nd Ind.) [GeV]
    float    plane2VisE;   //!< Sum of energy deposited on plane 2 (Col.) [GeV]
    
    float    genE;        //!< Energy at generation pt [GeV]
    float    startE;      //!< Energy at first pt in active TPC volume [GeV]
    float    endE;        //!< Energy at last pt in active TPC volume [GeV]
    float    genT;        //!< Start time of gen point [mus -- t=0 is spill time]
    float    startT;      //!< Start time of first TPC point [mus -- t=0 is spill time]
    float    endT;        //!< End time last point in the active [mus -- t=0 is spill time]
    float    length;      //!< Trajectory length in active TPC volume the particle first enters [cm]
    
    unsigned plane0nhit;  //!< Number of hits on plane 0 (1st Ind.)
    unsigned plane1nhit;  //!< Number of hits on plane 1 (2nd Ind.)
    unsigned plane2nhit;  //!< Number of hits on plane 2 (Col.)
    
    Vector3D genp;        //!< Momentum at generation point [GeV/c]
    Vector3D startp;      //!< Momentum at first point in the active TPC volume [GeV/c]
    Vector3D endp;        //!< Momentum at last point in the active TPC volume [GeV/c]
    Vector3D gen;         //!< Generation position [cm]
    Vector3D start;       //!< Start position in the active TPC volume [cm]
    Vector3D end;         //!< End position in the active TPC volume [cm]
    
    int   wallin;      //!< Wall of cryostat particle enters (wNone if starting in detector)
    int   wallout;     //!< Wall of cryostat particle exits (wNone if stopping in detector)
    
    bool     cont_tpc;    //!< Whether the particle is contained in a single TPC
    bool     crosses_tpc; //!< Whether the particle crosses a TPC boundary
    bool     contained;   //!< Whether the particle is contained in a single active volume
    
    int      pdg;          //!< Particle ID code
    int      G4ID;         //!< ID of the particle (taken from G4 -- -1 if this particle is not propogated by G4)
    int    parent;         //!< ID of parent particle
    
    int   start_process; //!< Start G4 process of the particle. Values defned as enum in StandardRecord
    int   end_process; //!< End G4 process of the particle. Values defined as enum in StandardRecord

    std::vector<TrueHit> truehits0; //!< List of True "hits" of this particle on Plane 0
    std::vector<TrueHit> truehits1; //!< List of True "hits" of this particle on Plane 1
    std::vector<TrueHit> truehits2; //!< List of True "hits" of this particle on Plane 2

    TrueParticle():
      plane0VisE(std::numeric_limits<float>::signaling_NaN()),
      plane1VisE(std::numeric_limits<float>::signaling_NaN()),
      plane2VisE(std::numeric_limits<float>::signaling_NaN()),
      genE(std::numeric_limits<float>::signaling_NaN()),
      startE(std::numeric_limits<float>::signaling_NaN()),
      endE(std::numeric_limits<float>::signaling_NaN()),
      genT(std::numeric_limits<float>::signaling_NaN()),
      startT(std::numeric_limits<float>::signaling_NaN()),
      endT(std::numeric_limits<float>::signaling_NaN()),
      length(std::numeric_limits<float>::signaling_NaN()),
      plane0nhit(0),
      plane1nhit(0),
      plane2nhit(0),
      wallin(-1),
      wallout(-1),
      cont_tpc(false),
      crosses_tpc(false),
      contained(false),
      pdg(-1),
      G4ID(-1), // Invalid
      start_process(-1),
      end_process(-1)
    {}
  };

  struct TrackTruth {
    TrueParticle p; //!< Truth information on particle
    TrueParticle michel; //!< Truth information on daughter-Michel-electron. Invalid if it doesn't exist
    float pur; //!< Purity of truth matching
    float eff; //!< Efficiency of truth matching
    float depE; //!< Total deposited energy of hits matched to track [GeV]

    TrackTruth():
      pur(std::numeric_limits<float>::signaling_NaN()),
      eff(std::numeric_limits<float>::signaling_NaN()),
      depE(std::numeric_limits<float>::signaling_NaN())
    {}

  };

  struct TrackInfo {
    MetaInfo meta; //!< Meta-data associated with this track
    std::vector<TrackHitInfo> hits0; //!< List of hits on plane 0
    std::vector<TrackHitInfo> hits1; //!< List of hits on plane 1
    std::vector<TrackHitInfo> hits2; //!< List of hits on plane 2
    std::vector<WireInfo> wires0; //!< List of wire information on plane 0
    std::vector<WireInfo> wires1; //!< List of wire information on plane 1
    std::vector<WireInfo> wires2; //!< List of wire information on plane 2

    float t0; //!< T0 of track [us]
    int whicht0; //!< Which T0 producer was used to tag
    int id; //!< ID of track
    int cryostat; //!< Cryostat number of track
    bool clear_cosmic_muon; //!< Whether Pandora thinks the track is "clearly" a cosmic
    Vector3D start; //!< Start position of track [cm]
    Vector3D end; //!< End position of track [cm]
    Vector3D dir; //!< Direction of track 
    float length; //!< Length of track [cm]

    float hit_min_time_p0_tpcE; //!< Min hit time of track on plane 0 TPC E
    float hit_max_time_p0_tpcE; //!< Max hit time of track on plane 0 TPC E
    float hit_min_time_p1_tpcE; //!< Min hit time of track on plane 1 TPC E
    float hit_max_time_p1_tpcE; //!< Max hit time of track on plane 1 TPC E
    float hit_min_time_p2_tpcE; //!< Min hit time of track on plane 2 TPC E
    float hit_max_time_p2_tpcE; //!< Max hit time of track on plane 2 TPC E
    float hit_min_time_p0_tpcW; //!< Min hit time of track on plane 0 TPC W
    float hit_max_time_p0_tpcW; //!< Max hit time of track on plane 0 TPC W
    float hit_min_time_p1_tpcW; //!< Min hit time of track on plane 1 TPC W
    float hit_max_time_p1_tpcW; //!< Max hit time of track on plane 1 TPC W
    float hit_min_time_p2_tpcW; //!< Min hit time of track on plane 2 TPC W
    float hit_max_time_p2_tpcW; //!< Max hit time of track on plane 2 TPC W

    float const_fit_C; //!< Fit parameter
    float const_fit_residuals; //!< Fit parameter

    float exp_fit_A; //!< Fit parameter
    float exp_fit_R; //!< Fit parameter
    float exp_fit_residuals; //!< Fit parameter

    int n_fit_point; //!< Fit parameter

    int selected; //!< Index of the tool that selected this track
    int nprescale; //!< Prescale of the tool that selected this track

    std::vector<int> daughter_pdg; //!< Pandora PDG codes of daughter PFP's
    std::vector<unsigned> daughter_nsp; //!< Number of space points in each daughter
    std::vector<float> daughter_sp_toend_dist; //!< Smallest distance from any daughter Space Point to Track End [cm]

    std::vector<float> tracks_near_end_dist; //!< List of tracks near the end of this track
    std::vector<float> tracks_near_end_costh; //!< List of tracks near the end of this track

    std::vector<float> tracks_near_start_dist; //!< List of tracks near the start of this track
    std::vector<float> tracks_near_start_costh; //!< List of tracks near the start of this track

    std::vector<HitInfo> endhits; //!< List of hits near the endpoint of the track on the collection plane

    TrackTruth truth; //!< Truth-matching information

    TrackInfo():
      t0(-1),
      id(-1),
      cryostat(-1),
      clear_cosmic_muon(false),
      length(-1),
      hit_min_time_p0_tpcE(-100000),
      hit_max_time_p0_tpcE(-100000),
      hit_min_time_p1_tpcE(-100000),
      hit_max_time_p1_tpcE(-100000),
      hit_min_time_p2_tpcE(-100000),
      hit_max_time_p2_tpcE(-100000),
      hit_min_time_p0_tpcW(-100000),
      hit_max_time_p0_tpcW(-100000),
      hit_min_time_p1_tpcW(-100000),
      hit_max_time_p1_tpcW(-100000),
      hit_min_time_p2_tpcW(-100000),
      hit_max_time_p2_tpcW(-100000),
      const_fit_C(-1),
      const_fit_residuals(-1),
      exp_fit_A(-1),
      exp_fit_R(-1),
      exp_fit_residuals(-1),
      n_fit_point(-1),
      selected(-1),
      nprescale(-1) {}
  };

}

#endif
