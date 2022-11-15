#ifndef SBND_CRTCLUSTER_CXX
#define SBND_CRTCLUSTER_CXX

#include "sbnobj/SBND/CRT/CRTCluster.hh"

namespace sbnd {

  namespace crt {

    CRTCluster::CRTCluster()
      : ts0          (0)
      , ts1          (0)
      , s            (0)
      , minX         (0.)
      , maxX         (0.)
      , minY         (0.)
      , maxY         (0.)
      , minZ         (0.)
      , maxZ         (0.)
      , nHits        (0)
      , sumADC       (0)
      , sumADCCorr   (0)
      , tagger       ("")
    {}

    CRTCluster::CRTCluster(uint32_t _ts0, uint32_t _ts1, uint32_t _s, double _minX, double _maxX,
			   double _minY, double _maxY, double _minZ, double _maxZ, uint16_t _nHits,
			   uint16_t _sumADC, uint16_t _sumADCCorr, std::string _tagger)
      : ts0          (_ts0)
      , ts1          (_ts1)
      , s            (_s)
      , minX         (_minX)
      , maxX         (_maxX)
      , minY         (_minY)
      , maxY         (_maxY)
      , minZ         (_minZ)
      , maxZ         (_maxZ)
      , nHits        (_nHits)
      , sumADC       (_sumADC)
      , sumADCCorr   (_sumADCCorr)
      , tagger       (_tagger)
    {}

    CRTCluster::~CRTCluster() {}

    uint32_t    CRTCluster::Ts0() const { return ts0; }
    uint32_t    CRTCluster::Ts1() const { return ts1; }
    uint32_t    CRTCluster::UnixS() const { return s; }
    double      CRTCluster::MinX() const { return minX; }
    double      CRTCluster::MaxX() const { return maxX; }
    double      CRTCluster::MinY() const { return minY; }
    double      CRTCluster::MaxY() const { return maxY; }
    double      CRTCluster::MinZ() const { return minZ; }
    double      CRTCluster::MaxZ() const { return maxZ; }
    uint16_t    CRTCluster::NHits() const { return nHits; }
    uint16_t    CRTCluster::SumADC() const { return sumADC; }
    uint16_t    CRTCluster::SumADCCorr() const { return sumADCCorr; }
    std::string CRTCluster::Tagger() const { return tagger; }
  }
}

#endif
