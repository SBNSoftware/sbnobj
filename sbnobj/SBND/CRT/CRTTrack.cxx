#ifndef SBND_CRTTRACK_CXX
#define SBND_CRTTRACK_CXX

#include "sbnobj/SBND/CRT/CRTTrack.hh"

namespace sbnd {

  namespace crt {

    CRTTrack::CRTTrack()
      : start   ({0., 0., 0.})
      , end     ({0., 0., 0.})
      , time    (0.)
      , etime   (0.)
      , pe      (0.)
      , tof     (0.)
      , triple  (false)
      , taggers ()
    {
      taggers.fill(false);
    }

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_time, const double &_etime,
                       const double &_pe, const double &_tof, const bool &_triple,
                       const std::array<bool, 7> &_taggers)
      : start   (_start)
      , end     (_end)
      , time    (_time)
      , etime   (_etime)
      , pe      (_pe)
      , tof     (_tof)
      , triple  (_triple)
      , taggers (_taggers)
    {}

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_time, const double &_etime,
                       const double &_pe, const double &_tof, const bool &_triple,
                       const std::set<CRTTagger> &_used_taggers)
      : start   (_start)
      , end     (_end)
      , time    (_time)
      , etime   (_etime)
      , pe      (_pe)
      , tof     (_tof)
      , triple  (_triple)
      , taggers ()
    {
      for(auto const &tagger : _used_taggers)
        taggers[tagger] = true;
    }

    CRTTrack::~CRTTrack() {}

    geo::Point_t        CRTTrack::Start() const { return start; }
    geo::Point_t        CRTTrack::End() const { return end; }
    double              CRTTrack::Time() const {return time; }
    double              CRTTrack::TimeErr() const { return etime; }
    double              CRTTrack::PE() const { return pe; }
    double              CRTTrack::ToF() const { return tof; }
    bool                CRTTrack::Triple() const { return triple; }
    std::array<bool, 7> CRTTrack::Taggers() const { return taggers; }

    geo::Vector_t CRTTrack::Direction() const { return (end - start).Unit(); }
    double        CRTTrack::Length() const { return (end - start).R(); }
    double        CRTTrack::Theta() const { return (end - start).Theta(); }
    double        CRTTrack::Phi() const { return (end - start).Phi(); }

    bool CRTTrack::UsedTagger(const CRTTagger tagger) const { return taggers[tagger]; }
  }
}

#endif
