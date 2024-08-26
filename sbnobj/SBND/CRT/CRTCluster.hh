/**
 * \class CRTCluster
 *
 * \brief Product to store a cluster of CRTStripHits
 *
 * \author Henry Lay (h.lay@lancaster.ac.uk)
 *
 */

#ifndef SBND_CRTCLUSTER_HH
#define SBND_CRTCLUSTER_HH

#include "sbnobj/SBND/CRT/CRTEnums.hh"

namespace sbnd::crt {

  class CRTCluster {
    
    int64_t   fTs0;           // T0 counter [ns]
    int64_t   fTs1;           // T1 counter [ns]
    uint32_t  fUnixS;        // Unixtime of event [s]
    uint16_t  fNHits;        // The number of strip hits forming the cluster
    CRTTagger fTagger;       // The tagger this cluster exists on
    CoordSet  fComposition;  // What combination of orientations does the cluster make up?

  public:

    CRTCluster();
    
    CRTCluster(int64_t _ts0, int64_t _ts1, uint32_t _unixS, uint16_t _nHits, CRTTagger _tagger,
               CoordSet _composition);

    virtual ~CRTCluster();

    int64_t   Ts0() const;
    int64_t   Ts1() const;
    uint32_t  UnixS() const;
    uint16_t  NHits() const;
    CRTTagger Tagger() const;
    CoordSet  Composition() const;
  };
}

#endif
