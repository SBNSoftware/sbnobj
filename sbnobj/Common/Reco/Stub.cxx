#include "sbnobj/Common/Reco/Stub.h"

int sbn::Stub::PlaneIndex(const geo::PlaneID &p) const {
  for (unsigned i_p = 0; i_p < plane.size(); i_p++) {
    if (plane[i_p] == p) return i_p;
  }

  return -1;
}

float sbn::Stub::CoreCharge(const geo::PlaneID &p) const {
  int plane_index = PlaneIndex(p);
  if (plane_index < 0) return 0.;

  return CoreCharge(plane_index);
}

int sbn::Stub::CoreNHit(const geo::PlaneID &p) const {
  int plane_index = PlaneIndex(p);
  if (plane_index < 0) return 0;

  return CoreNHit(plane_index);
}

float sbn::Stub::CoreCharge(unsigned plane_index) const {
  if (plane_index >= plane.size()) return -1;
  float ret = 0.;

  int stubdir = vtx_w[plane_index] <= hit_w[plane_index] ? 1 : -1;
  for (const sbn::StubHit &h: hits[plane_index]) {
    bool before_vtx = ((h.wire - vtx_w[plane_index]) * stubdir) < 0;
    bool after_hit = ((h.wire - hit_w[plane_index]) * stubdir) > 0;
    if (!before_vtx && !after_hit) {
      ret += h.charge;
    }
  }

  return ret;
}

int sbn::Stub::CoreNHit(unsigned plane_index) const {
  if (plane_index >= plane.size()) return -1;
  int ret = 0;

  int stubdir = vtx_w[plane_index] <= hit_w[plane_index] ? 1 : -1;
  for (const sbn::StubHit &h: hits[plane_index]) {
    bool before_vtx = ((h.wire - vtx_w[plane_index]) * stubdir) < 0;
    bool after_hit = ((h.wire - hit_w[plane_index]) * stubdir) > 0;
    if (!before_vtx && !after_hit) {
      ret ++;
    }
  }

  return ret;
}
    
bool sbn::Stub::OnCore(const geo::WireID &w) const {
  int plane_index = PlaneIndex(w);
  if (plane_index < 0) return -1;

  int stubdir = vtx_w[plane_index] <= hit_w[plane_index] ? 1 : -1;
  bool before_vtx = (((int)w.Wire - vtx_w[plane_index]) * stubdir) < 0;
  bool after_hit = (((int)w.Wire - hit_w[plane_index]) * stubdir) > 0;

  return !before_vtx && !after_hit;
}
