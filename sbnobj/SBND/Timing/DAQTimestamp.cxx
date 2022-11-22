#ifndef SBND_TIMESTAMP_CXX
#define SBND_TIMESTAMP_CXX

#include "sbnobj/SBND/Timing/DAQTimestamp.hh"

namespace sbnd::timing {

  DAQTimestamp::DAQTimestamp()
    : fChannel(std::numeric_limits<uint32_t>::max())
    , fTimestamp(0)
    , fOffset(0)
    , fName("")
  {}

  DAQTimestamp::DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::string name)
    : fChannel(channel)
    , fTimestamp(timestamp)
    , fOffset(offset)
    , fName(name)
  {}

  DAQTimestamp::DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::array<char, 8> name)
    : fChannel(channel)
    , fTimestamp(timestamp)
    , fOffset(offset)
    , fName("")
  {
    for(auto const& c : name)
      fName.push_back(c);
  }

  DAQTimestamp::~DAQTimestamp() {}

  uint32_t DAQTimestamp::Channel() const
  {
    return fChannel;
  }

  uint64_t DAQTimestamp::Timestamp() const
  {
    return fTimestamp;
  }

  uint64_t DAQTimestamp::Offset() const
  {
    return fOffset;
  }

  std::string DAQTimestamp::Name() const
  {
    return fName;
  }

  void DAQTimestamp::SetChannel(uint32_t channel)
  {
    fChannel = channel;
  }

  void DAQTimestamp::SetTimestamp(uint64_t timestamp)
  {
    fTimestamp = timestamp;
  }

  void DAQTimestamp::SetOffset(uint64_t offset)
  {
    fOffset = offset;
  }

  void DAQTimestamp::SetName(std::string name)
  {
    fName = name;
  }
}

#endif
