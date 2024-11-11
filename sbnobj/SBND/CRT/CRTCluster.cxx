#ifndef SBND_CRTCLUSTER_CXX
#define SBND_CRTCLUSTER_CXX

#include "sbnobj/SBND/CRT/CRTCluster.hh"

namespace sbnd {

  namespace crt {

    CRTCluster::CRTCluster()
      : fTs0          (0)
      , fTs1          (0)
      , fUnixS        (0)
      , fNHits        (0)
      , fTagger       (kUndefinedTagger)
      , fComposition  (kUndefinedSet)
    {}

    CRTCluster::CRTCluster(int64_t _ts0, int64_t _ts1, uint32_t _unixS, uint16_t _nHits, CRTTagger _tagger,
                           CoordSet _composition)
      : fTs0          (_ts0)
      , fTs1          (_ts1)
      , fUnixS        (_unixS)
      , fNHits        (_nHits)
      , fTagger       (_tagger)
      , fComposition  (_composition)
    {}

    CRTCluster::~CRTCluster() {}

    int64_t   CRTCluster::Ts0() const { return fTs0; }
    int64_t   CRTCluster::Ts1() const { return fTs1; }
    uint32_t  CRTCluster::UnixS() const { return fUnixS; }
    uint16_t  CRTCluster::NHits() const { return fNHits; }
    CRTTagger CRTCluster::Tagger() const { return fTagger; }
    CoordSet  CRTCluster::Composition() const { return fComposition; }
  }
}

#endif
