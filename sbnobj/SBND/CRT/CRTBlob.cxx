#ifndef SBND_CRTBLOB_CXX
#define SBND_CRTBLOB_CXX

#include "sbnobj/SBND/CRT/CRTBlob.hh"
#include <limits>

namespace sbnd {

  namespace crt {

    CRTBlob::CRTBlob()
      : fTs0        (std::numeric_limits<double>::lowest())
      , fTs0Err     (std::numeric_limits<double>::lowest())
      , fTs1        (std::numeric_limits<double>::lowest())
      , fTs1Err     (std::numeric_limits<double>::lowest())
      , fPE         (std::numeric_limits<double>::lowest())
      , fTaggerSPs  ({})
    {}

    CRTBlob::CRTBlob(const double &_ts0, const double &_ets0, const double &_ts1, const double &_ets1,
                     const double &_pe, const std::map<CRTTagger, int> &_tagger_hits)
      : fTs0        (_ts0)
      , fTs0Err     (_ets0)
      , fTs1        (_ts1)
      , fTs1Err     (_ets1)
      , fPE         (_pe)
      , fTaggerSPs  (_tagger_hits)
    {}

    CRTBlob::~CRTBlob() {}

    double                   CRTBlob::Ts0() const {return fTs0; }
    double                   CRTBlob::Ts0Err() const { return fTs0Err; }
    double                   CRTBlob::Ts1() const {return fTs1; }
    double                   CRTBlob::Ts1Err() const { return fTs1Err; }
    double                   CRTBlob::PE() const { return fPE; }
    std::map<CRTTagger, int> CRTBlob::TaggerSPs() const { return fTaggerSPs; }

    int CRTBlob::TotalSpacePoints() const
    {
      int total = 0;
      
      for(auto const& [ tagger, count ] : fTaggerSPs)
        total += count;

      return total;
    }

    int CRTBlob::SpacePointsInTagger(const CRTTagger tagger) const
    {
      return fTaggerSPs.at(tagger);
    }
  }
}

#endif
