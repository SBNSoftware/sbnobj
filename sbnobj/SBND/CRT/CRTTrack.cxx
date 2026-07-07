#ifndef SBND_CRTTRACK_CXX
#define SBND_CRTTRACK_CXX

#include "sbnobj/SBND/CRT/CRTTrack.hh"

namespace sbnd {

  namespace crt {

    CRTTrack::CRTTrack()
      : fPoints  ({})
      , fTs0     (0.)
      , fTs0Err  (0.)
      , fTs1     (0.)
      , fTs1Err  (0.)
      , fPE      (0.)
      , fToF     (0.)
      , fTaggers ({})
    {}

    CRTTrack::CRTTrack(const geo::Point_t &_start, const geo::Point_t &_end, const double &_ts0, const double &_ets0,
                       const double &_ts1, const double &_ets1, const double &_pe, const double &_tof,
                       const std::vector<CRTTagger> &_taggers)
      : fPoints  ({_start, _end})
      , fTs0     (_ts0)
      , fTs0Err  (_ets0)
      , fTs1     (_ts1)
      , fTs1Err  (_ets1)
      , fPE      (_pe)
      , fToF     (_tof)
      , fTaggers (_taggers)
    {}

    CRTTrack::CRTTrack(const std::vector<geo::Point_t> &_points, const double &_ts0, const double &_ets0,
                       const double &_ts1, const double &_ets1, const double &_pe, const double &_tof,
                       const std::vector<CRTTagger> &_taggers)
      : fPoints  (_points)
      , fTs0     (_ts0)
      , fTs0Err  (_ets0)
      , fTs1     (_ts1)
      , fTs1Err  (_ets1)
      , fPE      (_pe)
      , fToF     (_tof)
      , fTaggers (_taggers)
    {}

    CRTTrack::~CRTTrack() {}

    std::vector<geo::Point_t> CRTTrack::Points() const { return fPoints; }
    double                    CRTTrack::Ts0() const {return fTs0; }
    double                    CRTTrack::Ts0Err() const { return fTs0Err; }
    double                    CRTTrack::Ts1() const {return fTs1; }
    double                    CRTTrack::Ts1Err() const { return fTs1Err; }
    double                    CRTTrack::PE() const { return fPE; }
    double                    CRTTrack::ToF() const { return fToF; }
    std::vector<CRTTagger>    CRTTrack::Taggers() const { return fTaggers; }

    geo::Point_t  CRTTrack::Start() const { return fPoints.front(); }
    geo::Point_t  CRTTrack::End() const { return fPoints.back(); }
    geo::Vector_t CRTTrack::Direction() const { return (End() - Start()).Unit(); }
    double        CRTTrack::Length() const { return (End() - Start()).R(); }
    double        CRTTrack::Theta() const { return (End() - Start()).Theta(); }
    double        CRTTrack::Phi() const { return (End() - Start()).Phi(); }
    bool          CRTTrack::Triple() const { return fTaggers.size() == 3; }

    bool CRTTrack::UsedTagger(const CRTTagger tagger) const
    {
      for(const CRTTagger track_tagger : fTaggers)
	{
	  if(track_tagger == tagger)
	    return true;
	}

      return false;
    }
  }
}

#endif
