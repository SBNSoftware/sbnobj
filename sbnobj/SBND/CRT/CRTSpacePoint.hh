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
    
    double x;     // x position [cm]
    double ex;    // x positional error [cm]
    double y;     // y position [cm]
    double ey;    // y positional error [cm]
    double z;     // z position [cm]
    double ez;    // z positional error [cm]
    double pe;    // total PE
    double time;  // time [ns]

  public:

    CRTSpacePoint();
    
    CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, double _pe, double _time);

    CRTSpacePoint(TVector3 _pos, TVector3 _err, double _pe, double time);

    virtual ~CRTSpacePoint();

    double X() const;
    double XErr() const;
    double Y() const;
    double YErr() const;
    double Z() const;
    double ZErr() const;
    double PE() const;
    double Time() const;
  };
}

#endif
