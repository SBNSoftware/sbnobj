#ifndef SBND_CRTTRACK_CXX
#define SBND_CRTTRACK_CXX

#include "sbnobj/SBND/CRT/CRTTrack.hh"

namespace sbnd {

  namespace crt {

    CRTTrack::CRTTrack()
      : fPoints  ({})
      , fTime    (0.)
      , fTimeErr (0.)
      , fPE      (0.)
      , fToF     (0.)
      , fTaggers ({})
    {}

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_time, const double &_etime,
                       const double &_pe, const double &_tof, const std::set<CRTTagger> &_taggers)
      : fPoints  ({_start, _end})
      , fTime    (_time)
      , fTimeErr (_etime)
      , fPE      (_pe)
      , fToF     (_tof)
      , fTaggers (_taggers)
    {}

    CRTTrack::CRTTrack(const std::vector<geo::Point_t> &_points, const double &_time, const double &_etime,
                       const double &_pe, const double &_tof, const std::set<CRTTagger> &_taggers)
      : fPoints  (_points)
      , fTime    (_time)
      , fTimeErr (_etime)
      , fPE      (_pe)
      , fToF     (_tof)
      , fTaggers (_taggers)
    {}

    CRTTrack::~CRTTrack() {}

    std::vector<geo::Point_t> CRTTrack::Points() const { return fPoints; }
    double                    CRTTrack::Time() const {return fTime; }
    double                    CRTTrack::TimeErr() const { return fTimeErr; }
    double                    CRTTrack::PE() const { return fPE; }
    double                    CRTTrack::ToF() const { return fToF; }
    std::set<CRTTagger>       CRTTrack::Taggers() const { return fTaggers; }

    geo::Point_t  CRTTrack::Start() const { return fPoints.front(); }
    geo::Point_t  CRTTrack::End() const { return fPoints.back(); }
    geo::Vector_t CRTTrack::Direction() const { return (End() - Start()).Unit(); }
    double        CRTTrack::Length() const { return (End() - Start()).R(); }
    double        CRTTrack::Theta() const { return (End() - Start()).Theta(); }
    double        CRTTrack::Phi() const { return (End() - Start()).Phi(); }
    bool          CRTTrack::Triple() const { return fTaggers.size() == 3; }

    bool CRTTrack::UsedTagger(const CRTTagger tagger) const { return fTaggers.count(tagger) == 1; }
  }
}

#endif
