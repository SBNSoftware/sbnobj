#ifndef sbncode_Simpleflashmatchvars_H
#define sbncode_Simpleflashmatchvars_H

#include "TVector3.h"

namespace sbn
{
  class SimpleFlashMatch
  {
  public:
  SimpleFlashMatch(
    bool present = false, double time = -1, double pe = -1,
    double score = -1, double scr_y = -1, double scr_z = -1,
    double scr_rr = -1, double scr_ratio = -1,
    TVector3 chargeXYZ = TVector3(-999, -999, -999),
    TVector3 lightXYZ = TVector3(-999,-999,-999)):
    mPresent(present),
    mTime(time),
    mPE(pe),
    mScore(score),
    mScr_y(scr_y),
    mScr_z(scr_z),
    mScr_rr(scr_rr),
    mScr_ratio(scr_ratio),
    mChargeXYZ(chargeXYZ),
    mLightXYZ(lightXYZ)
    {}

    bool mPresent;
    double mTime;
    double mPE;
    double mScore;
    double mScr_y;
    double mScr_z;
    double mScr_rr;
    double mScr_ratio;
    TVector3 mChargeXYZ;
    TVector3 mLightXYZ;
  }; //end sbn::SimpleFlashMatch
}

#endif
