#ifndef SBND_CRTVETO_CXX
#define SBND_CRTVETO_CXX

#include "sbnobj/SBND/CRT/CRTSpacePoint.hh"
#include "sbnobj/SBND/CRT/CRTVeto.hh"

#include <set>
#include <vector>

namespace sbnd {

  namespace crt {

    CRTVeto::CRTVeto()
      : fV0 (false)
      , fV1 (false)
      , fV2 (false)
      , fV3 (false)
      , fV4 (false)
      // Add South Wall times for debugging
      , fSouthTimes ({})
    {}

    CRTVeto::CRTVeto(bool _v0, bool _v1, bool _v2, bool _v3, bool _v4, const std::vector<double> _south_times)
      : fV0 (_v0)
      , fV1 (_v1)
      , fV2 (_v2)
      , fV3 (_v3)
      , fV4 (_v4)
      , fSouthTimes(_south_times)
    {}

    CRTVeto::~CRTVeto() {}

    bool CRTVeto::V0() const { return fV0; }
    bool CRTVeto::V1() const { return fV1; }
    bool CRTVeto::V2() const { return fV2; }
    bool CRTVeto::V3() const { return fV3; }
    bool CRTVeto::V4() const { return fV4; }
    std::vector<double> CRTVeto::SouthTimes() const { return fSouthTimes; }
  }
}

#endif
