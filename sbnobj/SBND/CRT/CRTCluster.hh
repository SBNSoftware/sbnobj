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

namespace sbnd::crt {

  class CRTCluster{
    
    uint32_t    ts0;          // T0 counter [ns]
    uint32_t    ts1;          // T1 counter [ns]
    uint32_t    s;            // Unixtime of event [s]
    double      minX;         // Minimum X position within cluster [cm]
    double      maxX;         // Maximum X position within cluster [cm]
    double      minY;         // Minimum Y position within cluster [cm]
    double      maxY;         // Maximum Y position within cluster [cm]
    double      minZ;         // Minimum Z position within cluster [cm]
    double      maxZ;         // Maximum Z position within cluster [cm]
    uint16_t    nHits;        // The number of strip hits forming the cluster
    uint16_t    sumADC;       // The sum of the ADC counts from the contributing hits
    uint16_t    sumADCCorr;   // The sum of the ADC counts from the contributing hits,
                              //   with corrections applied
    std::string tagger;       // The name of the tagger this cluster exists on

  public:

    CRTCluster();
    
    CRTCluster(uint32_t _ts0, uint32_t _ts1, uint32_t _s, double _minX, double _maxX, 
	       double _minY, double _maxY, double _minZ, double _maxZ, uint16_t _nHits, 
	       uint16_t _sumADC, uint16_t _sumADCCorr, std::string _tagger);

    virtual ~CRTCluster();

    uint32_t    Ts0() const;
    uint32_t    Ts1() const;
    uint32_t    UnixS() const;
    double      MinX() const;
    double      MaxX() const;
    double      MinY() const;
    double      MaxY() const;
    double      MinZ() const;
    double      MaxZ() const;
    uint16_t    NHits() const;
    uint16_t    SumADC() const;
    uint16_t    SumADCCorr() const;
    std::string Tagger() const;
  };
}

#endif
