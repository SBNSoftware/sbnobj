#include "sbnobj/Common/Reco/Stub.h"

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

