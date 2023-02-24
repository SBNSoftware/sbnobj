#include "sbnobj/Common/Reco/CNNScore.h"

sbn::CNNScore::CNNScore(float showerScore, float michelScore)
    // TODO: if not clear cosmic?
    //return ShowerScore(pfp)
  : showerScore(showerScore)
  , michelScore(michelScore)
{
}
