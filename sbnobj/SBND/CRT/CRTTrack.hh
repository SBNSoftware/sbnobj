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

namespace sbnd::crt {

  class CRTTrack {
    
    geo::Point_t        start;   // the fitted start position [cm]
    geo::Vector_t       dir;     // the fitted track direction [cm]
    double              time;    // time [ns]
    double              etime;   // time error [ns]
    double              pe;      // total PE
    bool                triple;  // whether the track contains space points from 3 taggers
    std::array<bool, 7> taggers; // whether the track contains a space point from each tagger
                                 // (enumerated by CRTTagger enum)

  public:

    CRTTrack();
    
    CRTTrack(const geo::Point_t &_start, const geo::Vector_t &_dir, const double &_time, const double &_etime,
             const double &_pe, const bool &_triple, const std::array<bool, 7> &_taggers);

    CRTTrack(const geo::Point_t &_start, const geo::Vector_t &_dir, const double &_time, const double &_etime,
             const double &_pe, const bool &_triple, const std::vector<CRTTagger> &_used_taggers);

    virtual ~CRTTrack();

    geo::Point_t        Start() const;
    geo::Vector_t       Direction() const;
    double              Time() const;
    double              TimeErr() const;
    double              PE() const;
    bool                Triple() const;
    std::array<bool, 7> Taggers() const;
    
    bool UsedTagger(const CRTTagger tagger) const;
  };
}

#endif
