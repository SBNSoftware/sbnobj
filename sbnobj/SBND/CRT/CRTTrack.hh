/**
 * \class CRTTrack
 *
 * \brief Product to store a track between CRTSpacePoints
 *
 * \author Henry Lay
 *
 */

#ifndef SBND_CRTTRACK_HH
#define SBND_CRTTRACK_HH

#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"
#include "sbnobj/SBND/CRT/CRTEnums.hh"

#include <set>

namespace sbnd::crt {

  class CRTTrack {
    
    std::vector<geo::Point_t> points;  // the fitted track points at each tagger [cm]
    double                    time;    // average time [ns]
    double                    etime;   // average time error [ns]
    double                    pe;      // total PE
    double                    tof;     // time from first space point to last [ns]
    std::set<CRTTagger>       taggers; // which taggers were used to create the track

  public:

    CRTTrack();
    
    CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_time, const double &_etime,
             const double &_pe, const double &_tof, const std::set<CRTTagger> &_taggers);

    CRTTrack(const std::vector<geo::Point_t> &_points, const double &_time, const double &_etime,
             const double &_pe, const double &_tof, const std::set<CRTTagger> &_taggers);

    virtual ~CRTTrack();

    std::vector<geo::Point_t> Points() const;
    double                    Time() const;
    double                    TimeErr() const;
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
