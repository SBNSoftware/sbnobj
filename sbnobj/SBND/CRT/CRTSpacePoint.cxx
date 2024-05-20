#ifndef SBND_CRTSPACEPOINT_CXX
#define SBND_CRTSPACEPOINT_CXX

#include "sbnobj/SBND/CRT/CRTSpacePoint.hh"

namespace sbnd {

  namespace crt {

    CRTSpacePoint::CRTSpacePoint()
      : fPos      ({0., 0., 0.})
      , fPosErr   ({0., 0., 0.})
      , fPE       (0.)
      , fT0       (0.)
      , fT0Err    (0.)
      , fT1       (0.)
      , fT1Err    (0.)
      , fComplete (false)
    {}

    CRTSpacePoint::CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, 
                                 double _pe, double _t0, double _et0, double _t1, double _et1, bool _complete)
      : fPos      ({_x, _y, _z})
      , fPosErr   ({_ex, _ey, _ez})
      , fPE       (_pe)
      , fT0       (_t0)
      , fT0Err    (_et0)
      , fT1       (_t1)
      , fT1Err    (_et1)
      , fComplete (_complete)
    {}

    CRTSpacePoint::CRTSpacePoint(geo::Point_t _pos, geo::Point_t _err, double _pe, double _t0, double _et0,
                                 double _t1, double _et1, bool _complete)
      : fPos      (_pos)
      , fPosErr   (_err)
      , fPE       (_pe)
      , fT0       (_t0)
      , fT0Err    (_et0)
      , fT1       (_t1)
      , fT1Err    (_et1)
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
    double       CRTSpacePoint::T0() const { return fT0; }
    double       CRTSpacePoint::T0Err() const { return fT0Err; }
    double       CRTSpacePoint::T1() const { return fT1; }
    double       CRTSpacePoint::T1Err() const { return fT1Err; }
    bool         CRTSpacePoint::Complete() const { return fComplete; }
  }
}

#endif
