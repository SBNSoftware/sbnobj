#ifndef SBND_CRTTRACK_CXX
#define SBND_CRTTRACK_CXX

#include "sbnobj/SBND/CRT/CRTTrack.hh"

namespace sbnd {

  namespace crt {

    CRTTrack::CRTTrack()
      : fPoints  ({})
      , fT0      (0.)
      , fT0Err   (0.)
      , fT1      (0.)
      , fT1Err   (0.)
      , fPE      (0.)
      , fToF     (0.)
      , fTaggers ({})
    {}

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_t0, const double &_et0,
                       const double &_t1, const double &_et1, const double &_pe, const double &_tof,
                       const std::set<CRTTagger> &_taggers)
      : fPoints  ({_start, _end})
      , fT0      (_t0)
      , fT0Err   (_et0)
      , fT1      (_t1)
      , fT1Err   (_et1)
      , fPE      (_pe)
      , fToF     (_tof)
      , fTaggers (_taggers)
    {}

    CRTTrack::CRTTrack(const std::vector<geo::Point_t> &_points, const double &_t0, const double &_et0,
                       const double &_t1, const double &_et1, const double &_pe, const double &_tof,
                       const std::set<CRTTagger> &_taggers)
      : fPoints  (_points)
      , fT0      (_t0)
      , fT0Err   (_et0)
      , fT1      (_t1)
      , fT1Err   (_et1)
      , fPE      (_pe)
      , fToF     (_tof)
      , fTaggers (_taggers)
    {}

    CRTTrack::~CRTTrack() {}

    std::vector<geo::Point_t> CRTTrack::Points() const { return fPoints; }
    double                    CRTTrack::T0() const {return fT0; }
    double                    CRTTrack::T0Err() const { return fT0Err; }
    double                    CRTTrack::T1() const {return fT1; }
    double                    CRTTrack::T1Err() const { return fT1Err; }
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
