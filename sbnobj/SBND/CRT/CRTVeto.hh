/**
 * \class CRTVeto
 *
 * \brief Product to store CRT Veto Flags for a given Event
 *
 * \author Alex Antonakis (aantonakis@ucsb.edu)
 *
 */

#ifndef SBND_CRTVETO_HH
#define SBND_CRTVETO_HH

#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"

namespace sbnd::crt {

  class CRTVeto {
    bool fV0;    
    bool fV1;    
    bool fV2;    
    bool fV3;    
    bool fV4;    

  public:

    CRTVeto();
    
    CRTVeto(bool _v0, bool _v1, bool _v2, bool _v3, bool _v4);


    virtual ~CRTVeto();

    bool V0() const;
    bool V1() const;
    bool V2() const;
    bool V3() const;
    bool V4() const;


    //CRTVeto& operator= (CRTVeto const&) = default;
  };
}

#endif
