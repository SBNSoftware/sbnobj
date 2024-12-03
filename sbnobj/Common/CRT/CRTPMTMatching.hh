/**
 * @file   sbnobj/Common/CRTPMTMatching.hh
 * @brief  data product to store CRT PMT Matches 
 * @author Anna Heggestuen (aheggest@colostate.edu) and Francesco Poppi ( poppi@bo.infn.it )
 * @date   June 1 2023.
 */

#ifndef CRTPMTMATCHING_hh_
#define CRTPMTMATCHING_hh_

// C++ includes
#include <vector>
#include <limits>
#include "larcoreobj/SimpleTypesAndConstants/geo_vectors.h"

namespace sbn::crt {

  /// Type of match between a TPC object (e.g. PMT flash) and CRT system.
  enum class MatchType { /// perhaps it would be better to define these in icaruscode 
    noMatch           = 0, ///< No CRT match.
      enTop             = 1, ///< Matched with Top CRT hit before optical flash.
      enSide            = 2, ///< Matched with Side CRT hit before optical flash.
      enTop_exSide      = 3, ///< Matched with one Top CRT hit before the optical flash and matched with one Side CRT hit after the optical flash.
      exTop             = 4, ///< Matched with a Top CRT after the optical flash.
      exSide            = 5, ///< Matched with a Side CRT after the optical flash.
      enTop_mult        = 6, ///< Matched with multiple Top CRT hits before the optical flash.
      enTop_exSide_mult = 7, ///< Matched with multiple Top CRT hits before the optical flash and more then 1 side CRT hits after the optical flash.
      enBottom          = 8, ///< Matched with bottom CRT hit before the optical flash.
      exBottom          = 10, ///< Matched with Bottom CRT hit after the optical flash.
      enTop_exBottom    = 11, ///< Matched with one Top CRT hit before the optical flash and
      enSide_exBottom   = 12, ///< Matched with one Side CRT hit before the optical flash and matched with one Bottom CRT hit after the optical flash.
      exTop_enBottom    = 13, ///< Matched with one Bottom CRT hit before the optical flash and matched with one Top CRT hit after the optical flash.
      exSide_enBottom   = 14, ///< Matched with one Bottom CRT hit before the optical flash and matched with one Side CRT hit after the optical flash.
      others            = 9  ///< All the other cases.
      };
  MatchType assignFlashClassification(uint topen, uint topex, 
				      uint sideen, uint sideex, 
				      uint bottomen, uint bottomex)
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

  /// Information about a CRT hit matched with a PMT flash.
  struct MatchedCRT {

    /// Special value to indicate the lack of information on a time.
    static constexpr double NoTime = std::numeric_limits<double>::lowest();
    
    /// Special value to indicate no information on the hit location.
    static constexpr int NoLocation = -1;

    geo::Point_t position;           ///< Hit location [cm]
    double PMTTimeDiff; //= NoTime;     < CRT hit time minus PMT flash time [us] (instead maybe wanna set NoTime vars in 
    double time;//        = NoTime;     ///< CRT hit time [us]
    int sys;     //       = NoLocation; ///< CRT subdetector the hit fell into.
    int region;//         = NoLocation; ///< Region the matched CRT hit fell into.
  };

  struct CRTPMTMatching{
    /// Special value to indicate the lack of information on an ID.
    static constexpr int NoID = std::numeric_limits<int>::min();
    
    /// Special value to indicate the lack of information on a counter.
    static constexpr unsigned int NoCount 
      = std::numeric_limits<unsigned int>::max();

    /// Special value to indicate the lack of information on a time.
    static constexpr double NoTime = std::numeric_limits<double>::lowest();

    /// Special value to indicate the lack of information on flash photoelectrons.
    static constexpr double NoPE = -1.0;

    /// Special value to indicate the lack of information on flash width.
    static constexpr double NoWidth = -1.0;


    int          flashID;//             = NoID;    ///< ID of the optical flash.
    double       flashTime;//           = NoTime;  ///< Time of the optical flash w.r.t. the global trigger [us]
    double       flashGateTime;//       = NoTime;  ///< Time of the optical flash w.r.t. the beam gate opening [us]
    double       firstOpHitPeakTime;//  = NoTime;  ///< Time of the first optical hit peak time w.r.t. the global trigger [us]
    double       firstOpHitStartTime;// = NoTime;  ///< Time of the first optical hit start time w.r.t. the global trigger [us]
    bool         flashInGate;//         = false;   ///< Flash within gate or not.
    bool         flashInBeam ;//        = false;   ///< Flash within the beam window of the gate or not.
    double       flashPE;//             = -1.0;    ///< Total reconstructed light in the flash [photoelectrons]
    geo::Point_t flashPosition;                 ///< Flash barycenter coordinates evaluated using ADCs as weights.
    double       flashYWidth;//         = NoWidth; ///< Flash spread along Y.
    double       flashZWidth;//         = NoWidth; ///< Flash spread along Z. 
    MatchType    flashClassification;// = MatchType::noMatch; ///< Classification of the optical flash.
    std::vector<MatchedCRT> matchedCRTHits;     ///< Matched CRT Hits with the optical flash.
    unsigned int nTopCRTHitsBefore   = NoCount; ///< Number of Top CRT Hits before the optical flash.
    unsigned int nTopCRTHitsAfter    = NoCount; ///< Number of Top CRT Hits after the optical flash.
    unsigned int nSideCRTHitsBefore  = NoCount; ///< Number of Side CRT Hits before the optical flash.
    unsigned int nSideCRTHitsAfter   = NoCount; ///< Number of Side CRT Hits after the optical flash.



    /// Returns whether the information in this record is in any way valid.
    bool isValid() const { return flashID != NoID; }

  };

  /// Additional information about the matching of one flash and one CRT hit.
  /// 
  /// Intended as association metadata.
  struct CRTPMTMatchingInfo {

    enum class Dir { unknown, entering, exiting };

    /// Special value to indicate the lack of information on a time.
    static constexpr double NoTime = std::numeric_limits<double>::lowest();

    /// Whether CRT hit describes a particle entering the detector of exiting.
    Dir direction = Dir::unknown;
    double timeOfFlight = NoTime; ///< CRT hit time minus PMT flash time [us]
    double distance; ///< Distance between CRT Hit and optical flash centroid [cm]

  }; // CRTPMTMatchingInfo


} // namespace sbn::crt


#endif 
