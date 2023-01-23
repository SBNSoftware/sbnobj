#ifndef SBND_CRTCLUSTER_CXX
#define SBND_CRTCLUSTER_CXX

#include "sbnobj/SBND/CRT/CRTCluster.hh"

namespace sbnd {

  namespace crt {

    CRTCluster::CRTCluster()
      : ts0          (0)
      , ts1          (0)
      , s            (0)
      , nHits        (0)
      , tagger       (kUndefinedTagger)
      , composition  (kUndefinedSet)
    {}

    CRTCluster::CRTCluster(uint32_t _ts0, uint32_t _ts1, uint32_t _s, uint16_t _nHits, CRTTagger _tagger,
                           CoordSet _composition)
      : ts0          (_ts0)
      , ts1          (_ts1)
      , s            (_s)
      , nHits        (_nHits)
      , tagger       (_tagger)
      , composition  (_composition)
    {}

    CRTCluster::~CRTCluster() {}

    uint32_t  CRTCluster::Ts0() const { return ts0; }
    uint32_t  CRTCluster::Ts1() const { return ts1; }
    uint32_t  CRTCluster::UnixS() const { return s; }
    uint16_t  CRTCluster::NHits() const { return nHits; }
    CRTTagger CRTCluster::Tagger() const { return tagger; }
    CoordSet  CRTCluster::Composition() const { return composition; }
  }
}

#endif
