/**
 * \brief Dataproduct to store data associated to CRT FEBData objects
 *
 * \details Each simulated FEBData object is associated to a vector of AuxDetIDEs that
 * contributed to the energy deposits in that CRT module.
 * For each AuxDetIDE, this FEBTruthInfo product allows to store the index of the
 * SiPM associated to the energy deposit. Without FEBTruthInfo ot would be
 * impossible to associate an AuxDetIDE to a particular SiPM (or strip), but only to the
 * entire CRT module.
 *
 * \author Marco Del Tutto
 */

#ifndef SBND_FEBTRUTHINFO_HH
#define SBND_FEBTRUTHINFO_HH

#include <array>
#include <vector>

constexpr int NCH = 32;

namespace sbnd::crt {

  class FEBTruthInfo {

   public:

    // std::array<std::vector<int>, NCH> channelToAuxDetIDEIndexes;
    int channel;

    /**
     * Default constructor.
     */
    FEBTruthInfo() = default;

    /**
     * Sets the AuxDetIDE ID for the channel
     *
     * @param channel The SiPM channel.
     * @param index The AuxDetIDE ID related to this channel.
     */
    // void Add(int channel, int index) { channelToAuxDetIDEIndexes[channel].push_back(index); };

    // std::vector<int> GetIndexes(int channel) { return channelToAuxDetIDEIndexes[channel]; }
    int GetChannel() const { return channel; }

  };

} // namespace sbnd::crt

#endif
