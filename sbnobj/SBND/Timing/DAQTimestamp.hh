/**
 * \brief Data product to store a timestamp from the DAQ system
 *
 * \author Henry Lay         (h.lay@lancaster.ac.uk)
 * \author Vu Chi Lan Nguyen (vclnguyen1@sheffield.ac.uk)
 */

#ifndef SBND_DAQTIMESTAMP_HH
#define SBND_DAQTIMESTAMP_HH

#include <stdint.h>
#include <string>
#include <array>
#include <limits> // for std::numeric_limits

namespace sbnd::timing {

  class DAQTimestamp {

    uint32_t fChannel;   ///< Hardware channel
    uint64_t fTimestamp; ///< Timestamp of signal [ns]
    uint64_t fOffset;    ///< Channel specific offset [ns]
    std::string fName;   ///< Name of channel input
    
    //New addition for sbndcode version > v10_04_??
    uint64_t fTimestampPs; ///< Timestamp of signal [ps]

   public:

    /**
     * Default constructor.
     */
    DAQTimestamp();

    /**
     * Constructor to set 4 parameters but timestamp ps
     * For decoding with sbndcode <= v10_04_??
     *
     * @param channel    Hardware channel
     * @param timestamp  Timestamp of signal [ns] in UTC format
     * @param offset     Channel specific offset [ns]
     * @param name       Name of channel input
     */
    DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::string name);
    DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::array<char, 8> name);

    /**
     * Constructor to set all parameters 
     * For decoding with sbndcode > v10_04_??
     *
     * @param channel    Hardware channel
     * @param timestamp  Timestamp of signal [ns] in UTC format
     * @param offset     Channel specific offset [ns]
     * @param name       Name of channel input
     */
    DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::string name, uint64_t timestampPs);
    DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::array<char, 8> name, uint64_t timestampPs);

    /**
     * Destructor
     */
    virtual ~DAQTimestamp();

    /**
     * Getters
     */
    uint32_t    Channel() const;
    uint64_t    Timestamp() const;
    uint64_t    Offset() const;
    std::string Name() const;
    
    //New addition for sbndcode version > v10_04_??
    uint64_t    TimestampPs() const;
 
    /**
     * Setters
     */
    void SetChannel(uint32_t channel);
    void SetTimestamp(uint64_t timestamp);
    void SetOffset(uint64_t offset);
    void SetName(std::string name);

    //New addition for sbndcode version > v10_04_??
    void SetTimestampPs(uint64_t timestamp);
  };
}

#endif
