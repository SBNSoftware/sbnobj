/**
 * \class CRTTrack
 *
 * \brief Product to store a track between CRTSpacePoints
 *
 * \author Henry Lay (h.lay@lancaster.ac.uk)
 *
 */

#ifndef SBND_CRTTRACK_HH
#define SBND_CRTTRACK_HH

#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"
#include "sbnobj/SBND/CRT/CRTEnums.hh"

#include <set>
#include <vector>

namespace sbnd::crt {

  class CRTTrack {
    
    std::vector<geo::Point_t> fPoints;  // the fitted track points at each tagger [cm]
    double                    fTs0;     // average time according to T0 clock [ns]
    double                    fTs0Err;  // average time error according to T0 clock [ns]
    double                    fTs1;     // average time according to T1 clock [ns]
    double                    fTs1Err;  // average time error according to T1 clock [ns]
    double                    fPE;      // total PE
    double                    fToF;     // time from first space point to last [ns]
    std::set<CRTTagger>       fTaggers; // which taggers were used to create the track

  public:

    CRTTrack();
    
    CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_ts0, const double &_ets0,
             const double &_ts1, const double &_ets1, const double &_pe, const double &_tof,
             const std::set<CRTTagger> &_taggers);

    CRTTrack(const std::vector<geo::Point_t> &_points, const double &_ts0, const double &_ets0,
             const double &_ts1, const double &_ets1, const double &_pe, const double &_tof,
             const std::set<CRTTagger> &_taggers);

    virtual ~CRTTrack();

    std::vector<geo::Point_t> Points() const;
    double                    Ts0() const;
    double                    Ts0Err() const;
    double                    Ts1() const;
    double                    Ts1Err() const;
    double                    PE() const;
    double                    ToF() const;
    std::set<CRTTagger>       Taggers() const;

    geo::Point_t  Start() const;
    geo::Point_t  End() const;
    geo::Vector_t Direction() const;
    double        Length() const;
    double        Theta() const;
    double        Phi() const;
    bool          Triple() const;
    
    bool UsedTagger(const CRTTagger tagger) const;
  };
}

#endif
