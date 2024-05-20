/**
 * \class CRTSpacePoint
 *
 * \brief Product to store the characterisation of a cluster
 *
 * \author Henry Lay (h.lay@lancaster.ac.uk)
 *
 */

#ifndef SBND_CRTSPACEPOINT_HH
#define SBND_CRTSPACEPOINT_HH

#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"

namespace sbnd::crt {

  class CRTSpacePoint {
    
    geo::Point_t fPos;      // position [cm]
    geo::Point_t fPosErr;   // positional error [cm]
    double       fPE;       // total PE
    double       fTs0;      // time according to T0 clock [ns]
    double       fTs0Err;   // error on time according to T0 clock [ns]
    double       fTs1;      // time according to T1 clock [ns]
    double       fTs1Err;   // error on time according to T1 clock [ns]
    bool         fComplete; // whether or not the cluster was 3D and contained overlaps

  public:

    CRTSpacePoint();
    
    CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, double _pe, 
                  double _ts0, double _ets0, double _ts1, double _ets1, bool _complete);

    CRTSpacePoint(geo::Point_t _pos, geo::Point_t _err, double _pe, double _ts0, double _ets0,
                  double _ts1, double _ets1, bool _complete);

    virtual ~CRTSpacePoint();

    double       X() const;
    double       XErr() const;
    double       Y() const;
    double       YErr() const;
    double       Z() const;
    double       ZErr() const;
    geo::Point_t Pos() const;
    geo::Point_t Err() const;
    double       PE() const;
    double       Ts0() const;
    double       Ts0Err() const;
    double       Ts1() const;
    double       Ts1Err() const;
    bool         Complete() const;

    CRTSpacePoint& operator= (CRTSpacePoint const&) = default;
  };
}

#endif
