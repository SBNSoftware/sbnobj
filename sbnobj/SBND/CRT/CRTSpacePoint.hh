/**
 * \class CRTSpacePoint
 *
 * \brief Product to store the characterisation of a cluster
 *
 * \author Henry Lay
 *
 */

#ifndef SBND_CRTSPACEPOINT_HH
#define SBND_CRTSPACEPOINT_HH

#include "TVector3.h"

namespace sbnd::crt {

  class CRTSpacePoint {
    
    double x;        // x position [cm]
    double ex;       // x positional error [cm]
    double y;        // y position [cm]
    double ey;       // y positional error [cm]
    double z;        // z position [cm]
    double ez;       // z positional error [cm]
    double pe;       // total PE
    double time;     // time [ns]
    double etime;    // time error [ns]
    bool   complete; // whether or not the cluster was 3D and contained overlaps

  public:

    CRTSpacePoint();
    
    CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, double _pe, 
                  double _time, double _etime, bool _complete);

    CRTSpacePoint(TVector3 _pos, TVector3 _err, double _pe, double _time, double _etime, bool _complete);

    virtual ~CRTSpacePoint();

    double   X() const;
    double   XErr() const;
    double   Y() const;
    double   YErr() const;
    double   Z() const;
    double   ZErr() const;
    TVector3 Pos() const;
    TVector3 Err() const;
    double   PE() const;
    double   Time() const;
    double   TimeErr() const;
    bool     Complete() const;

    CRTSpacePoint& operator= (CRTSpacePoint const&) = default;
  };
}

#endif
