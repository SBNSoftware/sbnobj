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

#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"

namespace sbnd::crt {

  class CRTSpacePoint {
    
    geo::Point_t pos;      // position [cm]
    geo::Point_t epos;     // positional error [cm]
    double       pe;       // total PE
    double       time;     // time [ns]
    double       etime;    // time error [ns]
    bool         complete; // whether or not the cluster was 3D and contained overlaps

  public:

    CRTSpacePoint();
    
    CRTSpacePoint(double _x, double _ex, double _y, double _ey, double _z, double _ez, double _pe, 
                  double _time, double _etime, bool _complete);

    CRTSpacePoint(geo::Point_t _pos, geo::Point_t _err, double _pe, double _time, double _etime, bool _complete);

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
    double       Time() const;
    double       TimeErr() const;
    bool         Complete() const;

    CRTSpacePoint& operator= (CRTSpacePoint const&) = default;

    bool operator==(const CRTSpacePoint &other) const;
  };
}

#endif
