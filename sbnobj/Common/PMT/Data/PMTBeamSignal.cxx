/**
 * @file   sbnobj/Common/PMT/Data/PMTBeamSignal.cxx
 * @brief  Holds the event-by-event RWM or EW times
 * @author Anna Heggestuen (aheggest@colostate.edu)
 * @date   May 19, 2025
 * @see    sbnobj/Common/PMT/Data/PMTBeamSignal.h
 */

//library header
#include "sbnobj/Common/PMT/Data/PMTBeamSignal.hh"

// C/C++ standard libraries 
#include <iostream>

// -----------------------------------------------------------------------------
void sbn::timing::SelectFirstOpHitByTime(const recob::OpHit* const hit, 
                                        std::map<int, double> &startmap, 
                                        std::map<int, double> &risemap)
{
  const int ch = hit->OpChannel();
  double ts = hit->StartTime();
  double tr = hit->RiseTime();
  // select the first ophit (by time) in each channel
  if (startmap.find(ch) != startmap.end())
  {
    if (ts < startmap[ch])
      {
        startmap[ch] = ts;
        risemap[ch] = ts + tr;
      }
  }
  else
  {
    startmap[ch] = ts;
    risemap[ch] = ts + tr;
  }  
}
// -----------------------------------------------------------------------------
int sbn::timing::getSideByChannel(const int channel)
{
  /*
  Channels are numbered from east to west, from North (cryo side) to South (beam side)
  We look in the opposide direction wrt to the beam direction South->North:
  - Left is the east wall of each cryostat;
  - Right is the west side of each cryostat;
  - [ 0:89 ] and [180:269] are on the left,
    the return value of the function is 0;
  - [ 90-179 ] and [ 270:359 ] are on the right,
    the return value of the function is 1;
  */

  int side = channel / 90; // always round down
  return side % 2;
}

// -----------------------------------------------------------------------------
double sbn::timing::getFlashBunchTime(std::map<int, double> startmap, 
                                      std::map<int, double> risemap,
                                      std::vector<sbn::timing::PMTBeamSignal> RWMTimes)
{
  // if no RWM info available, all pmt_start_time_rwm are invalid
  // return icarus::timing::NoTime as well for the flash
  if (RWMTimes.empty())
    return sbn::timing::NoTime;

  std::vector<int> channels;
  std::vector<double> hit_rise_time_rwm;
  for (auto it = startmap.begin(); it != startmap.end(); it++){
    int ch = it->first;
    channels.push_back(ch);
    auto rwm = RWMTimes.at(ch);
    if (!rwm.isValid()){
        std::cout << "No RWM signal for channel " << ch << " "
                  << "(Crate " << rwm.crate << ", Board " << rwm.digitizerLabel
                  << ", SpecialChannel " << rwm.specialChannel << ")\n";
    }
    float rwm_trigger = rwm.startTime; // rwm time w.r.t. trigger time [us]
    hit_rise_time_rwm.push_back(risemap[ch] - rwm_trigger);
  }

  double tfirst_left = std::numeric_limits<double>::max();
  double tfirst_right = std::numeric_limits<double>::max();

  int nleft = 0;
  int nright = 0;
  for(std::size_t i = 0; i < hit_rise_time_rwm.size(); i++){
    int ch = channels[i];
    int side = sbn::timing::getSideByChannel(ch);
    //int side = (ch / 90) % 2 ; //move this to a function as Matteo did to keep doc clear
    double t = hit_rise_time_rwm[i]; // rise time w.r.t. rwm

    // if any RWM copy is missing (therefore missing for an entire PMT crate),
    // it might not be possible to use the first hits (they might not have a RMW time)
    // so return icarus::timing::NoTime as in other bad cases
    if (!RWMTimes[i].isValid())
      return sbn::timing::NoTime;

    // count hits separetely on the two walls
    if (side == 0)
    {
      nleft++;
      if (t < tfirst_left)
        tfirst_left = t;
    }
    else if (side == 1)
    {
      nright++;
      if (t < tfirst_right)
        tfirst_right = t;
    }
  } //end loop over m_hit_rise_time_rwm vector

  // if there are no hits in one of the walls... very rare?
  if (nleft < 1 || nright < 1)
  {
    std::cout << "Flash doesn't have hits on both walls!"
                                             << "Left: " << nleft << " t " << tfirst_left << " "
                                             << "Right: " << nright << " t " << tfirst_right;
    // return what we have...
    return (tfirst_left < tfirst_right) ? tfirst_left : tfirst_right;
  }

  return (tfirst_left + tfirst_right) / 2.;

}
