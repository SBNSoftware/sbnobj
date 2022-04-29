/**
 * \class CRTData
 *
 * \ingroup crt
 *
 * \brief CRT Track Info
 *
 * \author $Author: David Lorca $
 *
 */

#ifndef CRTTrack_hh_
#define CRTTrack_hh_
#include <cstdint>

#include <vector>
#include <map>

namespace sbn::crt {

  struct CRTTrack{

    float peshit; ///< Total photoelectrons for this track (sum of PEs from the two CRTHits)
    double ts0_s; ///< Average time (second) of the two hits making the track
    double ts0_s_err; ///< Average time (second) spread of the two hits making the track
    double ts0_ns; ///< Average T0 (nanosecond) of the two hits making the track
    double ts0_ns_err; ///< Error on average T0 (nanosecond) of the two hits making the track
    double ts1_ns; ///< Average T1 (nanosecond) of the two hits making the track
    double ts1_ns_err; ///< Error on average T1 (nanosecond) of the two hits making the track
    int plane1; ///< Plane ID of first CRTHit
    int plane2; ///< Plane ID of second CRTHit

    float x1_pos; ///< X position of first CRTHit
    float x1_err; ///< X position error of first CRTHit
    float y1_pos; ///< Y position of first CRTHit
    float y1_err; ///< Y position error of first CRTHit
    float z1_pos; ///< Z position of first CRTHit
    float z1_err; ///< Z position error of first CRTHit
    float x2_pos; ///< X position of second CRTHit
    float x2_err; ///< X position error of second CRTHit
    float y2_pos; ///< Y position of second CRTHit
    float y2_err; ///< Y position error of second CRTHit
    float z2_pos; ///< Z position of second CRTHit
    float z2_err; ///< Z position error of second CRTHit
    float length; ///< Track length
    float thetaxy;  ///< Track angle on the X-Y plane
    float phizy; ///< Track angle on the Z-Y plane
    double ts0_ns_h1; ///< T0 time of first CRTHit
    double ts0_ns_err_h1; ///< T0 time error of first CRTHit
    double ts0_ns_h2; ///< T0 time of second CRTHit
    double ts0_ns_err_h2; ///< T0 time error of second CRTHit

    bool complete; ///< Whether or not the track is complete

    CRTTrack() {}

  };

} // namespace sbn::crt

#endif
