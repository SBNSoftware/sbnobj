#ifndef SBND_CRTVETO_CXX
#define SBND_CRTVETO_CXX

#include "sbnobj/SBND/CRT/CRTSpacePoint.hh"
#include "sbnobj/SBND/CRT/CRTVeto.hh"

namespace sbnd {

  namespace crt {

    CRTVeto::CRTVeto()
      : fV0 (false)
      , fV1 (false)
      , fV2 (false)
      , fV3 (false)
    {}

    CRTVeto::CRTVeto(bool _v0, bool _v1, bool _v2, bool _v3)
      : fV0 (_v0)
      , fV1 (_v1)
      , fV2 (_v2)
      , fV3 (_v3)
    {}

    CRTVeto::~CRTVeto() {}

    bool CRTVeto::V0() const { return fV0; }
    bool CRTVeto::V1() const { return fV1; }
    bool CRTVeto::V2() const { return fV2; }
    bool CRTVeto::V3() const { return fV3; }
  }
}

#endif
