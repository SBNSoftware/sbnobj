#ifndef SBND_CRTTRACK_CXX
#define SBND_CRTTRACK_CXX

#include "sbnobj/SBND/CRT/CRTTrack.hh"

namespace sbnd {

  namespace crt {

    CRTTrack::CRTTrack()
      : start   ({0., 0., 0.})
      , dir     ({0., 0., 0.})
      , time    (0.)
      , etime   (0.)
      , pe      (0.)
      , triple  (false)
      , taggers ()
    {
      taggers.fill(false);
    }

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Vector_t &_dir, const double &_time, const double &_etime,
                       const double &_pe, const bool &_triple, const std::array<bool, 7> &_taggers)
      : start   (_start)
      , dir     (_dir)
      , time    (_time)
      , etime   (_etime)
      , pe      (_pe)
      , triple  (_triple)
      , taggers (_taggers)
    {}

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Vector_t &_dir, const double &_time, const double &_etime,
                       const double &_pe, const bool &_triple, const std::vector<CRTTagger> &_used_taggers)
      : start   (_start)
      , dir     (_dir)
      , time    (_time)
      , etime   (_etime)
      , pe      (_pe)
      , triple  (_triple)
      , taggers ()
    {
      for(auto const &tagger : _used_taggers)
        taggers[tagger] = true;
    }

    CRTTrack::~CRTTrack() {}

    geo::Point_t        CRTTrack::Start() const { return start; }
    geo::Vector_t       CRTTrack::Direction() const { return dir; }
    double              CRTTrack::Time() const {return time; }
    double              CRTTrack::TimeErr() const { return etime; }
    double              CRTTrack::PE() const { return pe; }
    bool                CRTTrack::Triple() const { return triple; }
    std::array<bool, 7> CRTTrack::Taggers() const { return taggers; }

    bool CRTTrack::UsedTagger(const CRTTagger tagger) const { return taggers[tagger]; }
  }
}

#endif
