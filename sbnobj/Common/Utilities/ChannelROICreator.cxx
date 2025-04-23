/** ****************************************************************************
 * @file   ChannelROICreator.cxx
 * @brief  Helper functions to create a wire - implementation file
 * @date   April 20, 2025
 * @author usher@slac.stanford.edu
 * @see    ChannelROI.h ChannelROICreator.h
 *
 * ****************************************************************************/

// declaration header
#include "sbnobj/Common/Utilities/ChannelROICreator.h"

// LArSoft libraries
#include "lardataobj/RawData/RawDigit.h"

/// Reconstruction base classes
namespace recob {

  //----------------------------------------------------------------------
  ChannelROICreator::ChannelROICreator
    (const RegionsOfInterest_t& sigROIlist, const raw::RawDigit& rawdigit):
    channelROI(
      sigROIlist,
      rawdigit.Channel()
    )
  {
    // resize fSignalROI again:
    // just in case the user hasn't cared to set sigROIlist size right
    channelROI.fSignalROI.resize(rawdigit.Samples());
  } // Wire::Wire(RegionsOfInterest_t&)

  //----------------------------------------------------------------------
  ChannelROICreator::ChannelROICreator
    (RegionsOfInterest_t&& sigROIlist, const raw::RawDigit& rawdigit):
    channelROI(
      std::move(sigROIlist),
      rawdigit.Channel()
    )
  {
    // resize fSignalROI again:
    // just in case the user hasn't cared to set sigROIlist size right
    channelROI.fSignalROI.resize(rawdigit.Samples());
  } // Wire::Wire(RegionsOfInterest_t&)

  //----------------------------------------------------------------------
  ChannelROICreator::ChannelROICreator(
    RegionsOfInterest_t const& sigROIlist,
    raw::ChannelID_t channel,
    short int adcScaleFactor
    ):
    channelROI(sigROIlist, channel, adcScaleFactor)
    {}

  //----------------------------------------------------------------------
  ChannelROICreator::ChannelROICreator(
    RegionsOfInterest_t&& sigROIlist,
    raw::ChannelID_t channel,
    short int adcScaleFactor
    ):
    channelROI(std::move(sigROIlist), channel, adcScaleFactor)
    {}

} // namespace recob
