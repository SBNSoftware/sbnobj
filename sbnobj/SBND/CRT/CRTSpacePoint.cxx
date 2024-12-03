#ifndef SBND_CRTSPACEPOINT_CXX
#define SBND_CRTSPACEPOINT_CXX

#include "sbnobj/SBND/CRT/CRTSpacePoint.hh"

namespace sbnd {

  namespace crt {

    CRTSpacePoint::CRTSpacePoint()
      : fPos      ({0., 0., 0.})
      , fPosErr   ({0., 0., 0.})
      , fPE       (0.)
      , fTs0      (0.)
      , fTs0Err   (0.)
      , fTs1      (0.)
      , fTs1Err   (0.)
      , fComplete (false)
    {}

    CRTSpacePoint::CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, 
                                 double _pe, double _ts0, double _ets0, double _ts1, double _ets1, bool _complete)
      : fPos      ({_x, _y, _z})
      , fPosErr   ({_ex, _ey, _ez})
      , fPE       (_pe)
      , fTs0      (_ts0)
      , fTs0Err   (_ets0)
      , fTs1      (_ts1)
      , fTs1Err   (_ets1)
      , fComplete (_complete)
    {}

    CRTSpacePoint::CRTSpacePoint(geo::Point_t _pos, geo::Point_t _err, double _pe, double _ts0, double _ets0,
                                 double _ts1, double _ets1, bool _complete)
      : fPos      (_pos)
      , fPosErr   (_err)
      , fPE       (_pe)
      , fTs0      (_ts0)
      , fTs0Err   (_ets0)
      , fTs1      (_ts1)
      , fTs1Err   (_ets1)
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
    double       CRTSpacePoint::Ts0() const { return fTs0; }
    double       CRTSpacePoint::Ts0Err() const { return fTs0Err; }
    double       CRTSpacePoint::Ts1() const { return fTs1; }
    double       CRTSpacePoint::Ts1Err() const { return fTs1Err; }
    bool         CRTSpacePoint::Complete() const { return fComplete; }
  }
}

#endif
