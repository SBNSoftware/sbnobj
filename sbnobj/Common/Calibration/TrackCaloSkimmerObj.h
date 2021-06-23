#ifndef SBN_TrackCaloSkimmerObj
#define SBN_TrackCaloSkimmerObj

#include <vector>

namespace sbn {
  struct WireInfo {
    uint16_t wire;
    uint16_t plane;
    uint16_t tpc;
    int16_t tdc0;
    std::vector<short> adcs;

    WireInfo():
      wire((uint16_t)-1),
      plane((uint16_t)-1),
      tpc((uint16_t)-1),
      tdc0((uint16_t)-1) {}

  };

  struct HitInfo {
    float integral;
    float sumadc;
    float width;
    float pitch;
    float dqdx;
    float rr;
    float x;
    float y;
    float z;
    float dir_x;
    float dir_y;
    float dir_z;
    float time;
    uint16_t wire;
    uint16_t plane;
    uint16_t tpc;
    uint16_t mult;
    uint16_t i_snippet;
    int16_t start;
    int16_t end;
    bool ontraj;
    bool oncalo;

    HitInfo():
      integral(-1),
      sumadc(-1),
      width(-1),
      pitch(-1),
      dqdx(-1),
      rr(-1),
      x(-1),
      y(-1),
      z(-1),
      time(-1),
      wire((uint16_t)-1),
      plane((uint16_t)-1),
      tpc((uint16_t)-1),
      mult((uint16_t)-1),
      i_snippet((uint16_t)-1),
      start(-1),
      end(-1),
      ontraj(false),
      oncalo(false) {}
  };

  struct MetaInfo {
    int run;
    int evt;
    int subrun;
    int ifile;
    int iproc;

   MetaInfo():
     run(-1),
     evt(-1),
     subrun(-1),
     ifile(-1),
     iproc(-1) {}
  };

  struct TrackInfo {
    MetaInfo meta;
    std::vector<HitInfo> hits0; 
    std::vector<HitInfo> hits1; 
    std::vector<HitInfo> hits2; 
    std::vector<WireInfo> wires0;
    std::vector<WireInfo> wires1;
    std::vector<WireInfo> wires2;

    float t0; 
    int id;
    int cryostat;
    bool clear_cosmic_muon;
    float start_x; 
    float start_y;
    float start_z;
    float end_x; 
    float end_y;
    float end_z;
    float dir_x; 
    float dir_y;
    float dir_z;
    float length;

    unsigned ndaughters;

    float hit_min_time_p0_tpcE;
    float hit_max_time_p0_tpcE;
    float hit_min_time_p1_tpcE;
    float hit_max_time_p1_tpcE;
    float hit_min_time_p2_tpcE;
    float hit_max_time_p2_tpcE;
    float hit_min_time_p0_tpcW;
    float hit_max_time_p0_tpcW;
    float hit_min_time_p1_tpcW;
    float hit_max_time_p1_tpcW;
    float hit_min_time_p2_tpcW;
    float hit_max_time_p2_tpcW;

    float const_fit_C;
    float const_fit_residuals;

    float exp_fit_A;
    float exp_fit_R;
    float exp_fit_residuals;

    int n_fit_point;

    int selected;

    std::vector<float> tracks_near_end_dist;
    std::vector<float> tracks_near_end_costh;

    TrackInfo():
      t0(-1),
      id(-1),
      cryostat(-1),
      clear_cosmic_muon(false),
      start_x(-1),
      start_y(-1),
      start_z(-1),
      end_x(-1),
      end_y(-1),
      end_z(-1),
      dir_x(-1),
      dir_y(-1),
      dir_z(-1),
      length(-1),
      ndaughters(0),
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
      selected(-1) {}
  };

}

#endif
