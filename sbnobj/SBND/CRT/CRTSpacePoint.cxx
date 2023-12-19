#ifndef SBND_CRTSPACEPOINT_CXX
#define SBND_CRTSPACEPOINT_CXX

#include "sbnobj/SBND/CRT/CRTSpacePoint.hh"

namespace sbnd {

  namespace crt {

    CRTSpacePoint::CRTSpacePoint()
      : fPos      ({0., 0., 0.})
      , fPosErr   ({0., 0., 0.})
      , fPE       (0.)
      , fTime     (0.)
      , fTimeErr  (0.)
      , fComplete (false)
    {}

    CRTSpacePoint::CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, 
                                 double _pe, double _time, double _etime, bool _complete)
      : fPos      ({_x, _y, _z})
      , fPosErr   ({_ex, _ey, _ez})
      , fPE       (_pe)
      , fTime     (_time)
      , fTimeErr  (_etime)
      , fComplete (_complete)
    {}

    CRTSpacePoint::CRTSpacePoint(geo::Point_t _pos, geo::Point_t _err, double _pe, double _time, double _etime, bool _complete)
      : fPos      (_pos)
      , fPosErr   (_err)
      , fPE       (_pe)
      , fTime     (_time)
      , fTimeErr  (_etime)
      , fComplete (_complete)
    {}

    CRTSpacePoint::~CRTSpacePoint() {}

    double       CRTSpacePoint::X() const { return fPos.X(); }
    double       CRTSpacePoint::XErr() const { return fPosErr.X(); }
    double       CRTSpacePoint::Y() const { return fPos.Y(); }
    double       CRTSpacePoint::YErr() const { return fPosErr.Y(); }
    double       CRTSpacePoint::Z() const { return fPos.Z(); }
    double       CRTSpacePoint::ZErr() const { return fPosErr.Z(); }
    geo::Point_t CRTSpacePoint::Pos() const { return fPos; }
    geo::Point_t CRTSpacePoint::Err() const { return fPosErr; }
    double       CRTSpacePoint::PE() const { return fPE; }
    double       CRTSpacePoint::Time() const { return fTime; }
    double       CRTSpacePoint::TimeErr() const { return fTimeErr; }
    bool         CRTSpacePoint::Complete() const { return fComplete; }
  }
}

#endif
