/**
 * \class CRTCluster
 *
 * \brief Product to store a cluster of CRTStripHits
 *
 * \author Henry Lay
 *
 */

#ifndef SBND_CRTCLUSTER_HH
#define SBND_CRTCLUSTER_HH

#include <stdint.h>
#include <string>
#include <array>

namespace sbnd::crt {

  enum CRTTagger {
    kUndefinedTagger = -1,
    kBottomTagger,
    kSouthTagger,
    kNorthTagger,
    kWestTagger,
    kEastTagger,
    kTopLowTagger,
    kTopHighTagger,

    kUpstreamTagger   = kSouthTagger,
    kDownstreamTagger = kNorthTagger
  };

  class CRTCluster{
    
    uint32_t  ts0;          // T0 counter [ns]
    uint32_t  ts1;          // T1 counter [ns]
    uint32_t  s;            // Unixtime of event [s]
    uint16_t  nHits;        // The number of strip hits forming the cluster
    CRTTagger tagger;       // The tagger this cluster exists on
    bool      threeD;       // Does the cluster contain strips from both orientations?

  public:

    CRTCluster();
    
    CRTCluster(uint32_t _ts0, uint32_t _ts1, uint32_t _s, uint16_t _nHits, CRTTagger _tagger, bool _threeD);

    virtual ~CRTCluster();

    uint32_t  Ts0() const;
    uint32_t  Ts1() const;
    uint32_t  UnixS() const;
    uint16_t  NHits() const;
    CRTTagger Tagger() const;
    bool      ThreeD() const;
  };
}

#endif
