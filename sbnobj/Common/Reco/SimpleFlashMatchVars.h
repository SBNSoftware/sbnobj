#ifndef sbncode_Simpleflashmatchvars_H
#define sbncode_Simpleflashmatchvars_H

#include "TVector3.h"

namespace sbn
{
  class SimpleFlashMatch
  {
  public:
    struct Charge {
      double q;        //!< charge in slc
      TVector3 center; //!< Weighted center position [cm]
      Charge(double q_ = -1., TVector3 center_ = TVector3(-999, -999, -999)) :
        q(q_), center(center_)
        {}
    };
    struct Flash {
      double pe;       //!< photo-electrons on flash
      TVector3 center; //!< Weighted center position [cm]
      Flash(double pe_ = -1., TVector3 center_ = TVector3(-999, -999, -999)) :
        pe(pe_), center(center_)
        {}
    };
    struct Score {
      double total; //!< total score, sum of terms
      double y;     //!< score for y metric
      double z;     //!< score for z metric
      double rr;    //!< score for rr metric
      double ratio; //!< score for ratio metric
      Score (
        double total_ = -1.,
        double y_ = -1., double z_ = -1.,
        double rr_ = -1., double ratio_ = -1.) :
        total(total_), y(y_), z(z_), rr(rr_), ratio(ratio_)
        {}
      Score (int no_score) : // for no match fill all with the code
        total(no_score), y(no_score), z(no_score), rr(no_score), ratio(no_score)
        {}
    };

    SimpleFlashMatch(
      bool present_ = false, double time_ = -1,
      Charge charge_ = Charge(),
      Flash flash_ = Flash(),
      Score score_ = Score()):
      present(present_),
      time(time_),
      charge(charge_),
      light(flash_),
      score(score_)
      {}

    bool   present;     //!< Whether there's a match
    double time;        //!< time of flash
    Charge charge;      //!< object that contains charge and its position
    Flash  light;       //!< object that contains flash pe and its position
    Score  score;       //!< overall and partial scores to the match
  }; //end sbn::SimpleFlashMatch
}

#endif
