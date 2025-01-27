/**
 * @file   sbnobj/Common/CRTPMTMatching.cxx
 * @brief  Data product to store CRT PMT Matches (implementation file).
 * @author Anna Heggestuen (aheggest@colostate.edu) and Francesco Poppi (poppi@bo.infn.it)
 * @date   November 22, 2024
 * @see    sbnobj/Common/CRTPMTMatching.hh
 */

// Library header
#include "sbnobj/Common/CRT/CRTPMTMatching.hh"

sbn::crt::MatchType sbn::crt::assignFlashClassification(
  unsigned int topen, unsigned int topex, 
  unsigned int sideen, unsigned int sideex, 
  unsigned int bottomen, unsigned int bottomex
)
{
  MatchType flashType;
  if (topen == 0 && sideen == 0 && topex == 0 && sideex == 0){
    if(bottomex==0 && bottomen==0) flashType = MatchType::noMatch;
    else if (bottomex>=1 && bottomen==0) flashType = MatchType::exBottom;
    else if (bottomex==0 && bottomen>=1) flashType = MatchType::enBottom;
    else flashType = MatchType::others;
  }
  else if (topen == 1 && sideen == 0 && topex == 0 && sideex == 0){
    if(bottomex==1 && bottomen==0) flashType = MatchType::enTop_exBottom;
    else flashType = MatchType::enTop;
  }
  else if (topen == 0 && sideen == 1 && topex == 0 && sideex == 0)
    if(bottomex==1 && bottomen==0) flashType = MatchType::enSide_exBottom;
    else flashType = MatchType::enSide;
  else if (topen == 1 && sideen == 0 && topex == 0 && sideex == 1)
    flashType = MatchType::enTop_exSide;
  else if (topen == 0 && sideen == 0 && topex == 1 && sideex == 0){
    if(bottomex==0 && bottomen==1) flashType = MatchType::exTop_enBottom;
    else flashType = MatchType::exTop;
  }
  else if (topen == 0 && sideen == 0 && topex == 0 && sideex == 1)
    if(bottomex==0 && bottomen==1) flashType = MatchType::exSide_enBottom;
    else flashType = MatchType::exSide;
  else if (topen >= 1 && sideen == 0 && topex == 0 && sideex == 0) // could also add `if (MatchBottomCRT)` here
    flashType = MatchType::enTop_mult; 
  else if (topen >= 1 && sideen == 0 && topex == 0 && sideex >= 1) // and here 
    flashType = MatchType::enTop_exSide_mult;
  else
    flashType = MatchType::others;
  return flashType;

}
