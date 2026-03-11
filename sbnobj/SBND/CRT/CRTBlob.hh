/**
 * \class CRTBlob
 *
 * \brief Product to store a blob of CRT activity across all walls
 *
 * \author Henry Lay (h.lay@sheffield.ac.uk)
 *
 */

#ifndef SBND_CRTBLOB_HH
#define SBND_CRTBLOB_HH

#include "sbnobj/SBND/CRT/CRTEnums.hh"

#include <map>

namespace sbnd::crt {

  class CRTBlob {
    
    double                   fTs0;        // average time according to T0 clock [ns]
    double                   fTs0Err;     // error on average time according to T0 clock [ns]
    double                   fTs1;        // average time according to T1 clock [ns]
    double                   fTs1Err;     // error on average time according to T1 clock [ns]
    double                   fPE;         // total PE
    std::map<CRTTagger, int> fTaggerSPs;  // how many spacepoints from each tagger contribute to the blob

  public:

    CRTBlob();

    CRTBlob(const double &_ts0, const double &_ets0, const double &_ts1, const double &_ets1, const double &_pe,
            const std::map<CRTTagger, int> &_tagger_sps);

    virtual ~CRTBlob();

    double                   Ts0() const;
    double                   Ts0Err() const;
    double                   Ts1() const;
    double                   Ts1Err() const;
    double                   PE() const;
    std::map<CRTTagger, int> TaggerSPs() const;

    int TotalSpacePoints() const;
    int SpacePointsInTagger(const CRTTagger tagger) const;
  };
}

#endif
