#ifndef SBND_CRTSPACEPOINT_CXX
#define SBND_CRTSPACEPOINT_CXX

#include "sbnobj/SBND/CRT/CRTSpacePoint.hh"

namespace sbnd {

  namespace crt {

    CRTSpacePoint::CRTSpacePoint()
      : pos      ({0., 0., 0.})
      , epos     ({0., 0., 0.})
      , pe       (0.)
      , time     (0.)
      , etime    (0.)
      , complete (false)
    {}

    CRTSpacePoint::CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, 
                                 double _pe, double _time, double _etime, bool _complete)
      : pos      ({_x, _y, _z})
      , epos     ({_ex, _ey, _ez})
      , pe       (_pe)
      , time     (_time)
      , etime    (_etime)
      , complete (_complete)
    {}

    CRTSpacePoint::CRTSpacePoint(geo::Point_t _pos, geo::Point_t _err, double _pe, double _time, double _etime, bool _complete)
      : pos      (_pos)
      , epos     (_err)
      , pe       (_pe)
      , time     (_time)
      , etime    (_etime)
      , complete (_complete)
    {}

    CRTSpacePoint::~CRTSpacePoint() {}

    double       CRTSpacePoint::X() const { return pos.X(); }
    double       CRTSpacePoint::XErr() const { return epos.X(); }
    double       CRTSpacePoint::Y() const { return pos.Y(); }
    double       CRTSpacePoint::YErr() const { return epos.Y(); }
    double       CRTSpacePoint::Z() const { return pos.Z(); }
    double       CRTSpacePoint::ZErr() const { return epos.Z(); }
    geo::Point_t CRTSpacePoint::Pos() const { return pos; }
    geo::Point_t CRTSpacePoint::Err() const { return epos; }
    double       CRTSpacePoint::PE() const { return pe; }
    double       CRTSpacePoint::Time() const { return time; }
    double       CRTSpacePoint::TimeErr() const { return etime; }
    bool         CRTSpacePoint::Complete() const { return complete; }
  }
}

#endif
