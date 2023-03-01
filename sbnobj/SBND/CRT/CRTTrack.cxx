#ifndef SBND_CRTTRACK_CXX
#define SBND_CRTTRACK_CXX

#include "sbnobj/SBND/CRT/CRTTrack.hh"

namespace sbnd {

  namespace crt {

    CRTTrack::CRTTrack()
      : points  ({})
      , time    (0.)
      , etime   (0.)
      , pe      (0.)
      , tof     (0.)
      , taggers ({})
    {}

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_time, const double &_etime,
                       const double &_pe, const double &_tof, const std::set<CRTTagger> &_taggers)
      : points  ({_start, _end})
      , time    (_time)
      , etime   (_etime)
      , pe      (_pe)
      , tof     (_tof)
      , taggers (_taggers)
    {}

    CRTTrack::CRTTrack(const std::vector<geo::Point_t> &_points, const double &_time, const double &_etime,
                       const double &_pe, const double &_tof, const std::set<CRTTagger> &_taggers)
      : points  (_points)
      , time    (_time)
      , etime   (_etime)
      , pe      (_pe)
      , tof     (_tof)
      , taggers (_taggers)
    {}

    CRTTrack::~CRTTrack() {}

    std::vector<geo::Point_t> CRTTrack::Points() const { return points; }
    double                    CRTTrack::Time() const {return time; }
    double                    CRTTrack::TimeErr() const { return etime; }
    double                    CRTTrack::PE() const { return pe; }
    double                    CRTTrack::ToF() const { return tof; }
    std::set<CRTTagger>       CRTTrack::Taggers() const { return taggers; }

    geo::Point_t  CRTTrack::Start() const { return points.front(); }
    geo::Point_t  CRTTrack::End() const { return points.back(); }
    geo::Vector_t CRTTrack::Direction() const { return (End() - Start()).Unit(); }
    double        CRTTrack::Length() const { return (End() - Start()).R(); }
    double        CRTTrack::Theta() const { return (End() - Start()).Theta(); }
    double        CRTTrack::Phi() const { return (End() - Start()).Phi(); }
    bool          CRTTrack::Triple() const { return taggers.size() == 3; }

    bool CRTTrack::UsedTagger(const CRTTagger tagger) const { return taggers.count(tagger) == 1; }
  }
}

#endif
