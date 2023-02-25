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
    
    geo::Point_t        start;   // the fitted start position [cm]
    geo::Point_t        end;     // the fitted track end [cm]
    double              time;    // average time [ns]
    double              etime;   // average time error [ns]
    double              pe;      // total PE
    double              tof;     // time from first space point to last [ns]
    bool                triple;  // whether the track contains space points from 3 taggers
    std::array<bool, 7> taggers; // whether the track contains a space point from each tagger
                                 // (enumerated by CRTTagger enum)

  public:

    CRTTrack();
    
    CRTTrack(const geo::Point_t &_start, const geo::Point_t &_dir, const double &_time, const double &_etime,
             const double &_pe, const double &_tof, const bool &_triple,
             const std::array<bool, 7> &_taggers);

    CRTTrack(const geo::Point_t &_start, const geo::Point_t &_dir, const double &_time, const double &_etime,
             const double &_pe, const double &_tof, const bool &_triple,
             const std::set<CRTTagger> &_used_taggers);

    virtual ~CRTTrack();

    geo::Point_t        Start() const;
    geo::Point_t        End() const;
    double              Time() const;
    double              TimeErr() const;
    double              PE() const;
    double              ToF() const;
    bool                Triple() const;
    std::array<bool, 7> Taggers() const;

    geo::Vector_t Direction() const;
    double        Length() const;
    double        Theta() const;
    double        Phi() const;
    
    bool UsedTagger(const CRTTagger tagger) const;

    bool operator==(const CRTTrack &other) const;
  };
}

#endif
