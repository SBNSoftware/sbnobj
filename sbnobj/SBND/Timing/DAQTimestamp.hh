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

   public:

    /**
     * Default constructor.
     */
    DAQTimestamp();

    /**
     * Constructor to set all parameters
     *
     * @param channel    Hardware channel
     * @param timestamp  Timestamp of signal [ns]
     * @param offset     Channel specific offset [ns]
     * @param name       Name of channel input
     */
    DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::string name);

    /**
     * Constructor to set all parameters, using array for name
     *
     * @param channel    Hardware channel
     * @param timestamp  Timestamp of signal [ns]
     * @param offset     Channel specific offset [ns]
     * @param name       Name of channel input
     */
    DAQTimestamp(uint32_t channel, uint64_t timestamp, uint64_t offset, std::array<char, 8> name);

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
 
    /**
     * Setters
     */
    void SetChannel(uint32_t channel);
    void SetTimestamp(uint64_t timestamp);
    void SetOffset(uint64_t offset);
    void SetName(std::string name);
  };
}

#endif
