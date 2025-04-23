/** ****************************************************************************
 * @file ChannelROI.cxx
 * @brief Definition of basic channel signal object.
 * @author brebel@fnal.gov
 * @see  ChannelROI.h
 *
 * ****************************************************************************/

#include "sbnobj/ICARUS/TPC/ChannelROI.h"

// C/C++ standard libraries
#include <utility> // std::move()
#include <functional> // std::bind()

namespace recob{

  //----------------------------------------------------------------------
  ChannelROI::ChannelROI()
    : fChannel(raw::InvalidChannelID)
    , fADCScaleFactor(defADCScaleFactor)
    , fSignalROI()
    {}

  //----------------------------------------------------------------------
  ChannelROI::ChannelROI(
    RegionsOfInterest_t const& sigROIlist,
    raw::ChannelID_t channel,
    short int adcScaleFactor
    )
    : fChannel(channel)
    , fADCScaleFactor(adcScaleFactor)
    , fSignalROI(sigROIlist)
    {}

  //----------------------------------------------------------------------
  ChannelROI::ChannelROI(
    RegionsOfInterest_t&& sigROIlist,
    raw::ChannelID_t channel,
    short int adcScaleFactor
    )
    : fChannel(channel)
    , fADCScaleFactor(adcScaleFactor)
    , fSignalROI(std::move(sigROIlist))
    {}


  //----------------------------------------------------------------------
  std::vector<short int> ChannelROI::Signal() const {
    return { fSignalROI.begin(), fSignalROI.end() };
  } // ChannelROI::Signal()

  ChannelROI::RegionsOfInterest_f ChannelROI::SignalROIF()  const
  {
      RegionsOfInterest_f ROIVec;

      /// Note that when we are storing we scale the ADC values by a factor 
      /// in order to maintain resolution
      //const float ADCScaleFactor = 10.;

      // Loop through the ROIs for this channel
      for(const auto& range : fSignalROI.get_ranges())
      {
          size_t startTick = range.begin_index();

          std::vector<float> dataVec(range.data().begin(),range.data().end());

          for(auto& data : dataVec) data /= fADCScaleFactor;

          ROIVec.add_range(startTick, std::move(dataVec));
      }

      return ROIVec;
  }

}
////////////////////////////////////////////////////////////////////////

