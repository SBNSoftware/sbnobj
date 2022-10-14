/**
 * \brief Dataproduct to store raw FEB data from the CRT
 *
 * \author Marco Del Tutto
 */

#ifndef SBND_FEBDATA_HH
#define SBND_FEBDATA_HH

#include <stdint.h>
#include <vector>
#include <utility>
#include <array>

constexpr int N_CH = 32;

typedef std::array<uint16_t, N_CH> adc_array_t;

namespace sbnd::crt {

  class FEBData {

    uint16_t fMac5; ///< ID of the FEB
    uint16_t fFlags; ///< Event flags describing the type of data recorded
    uint32_t fTs0; ///< T0 counter [ns]
    uint32_t fTs1; ///< T1 counter [ns]
    uint32_t fUnixS; ///< Event time since unix epoch [s]
    adc_array_t fADC; ///< 32 ADC values, one per SiPM
    uint32_t fCoinc; ///< ID of SiPM that fired the trigger

   public:

    /**
     * Default constructor.
     */
    FEBData();

    /**
     * Constructor to set all parameters
     *
     * @param mac5 The ID of the CRT module (FEB).
     * @param flags The event flags.
     * @param ts0 The value of the t0 counter.
     * @param ts1 The value of the t1 counter.
     * @param unixs The event time since unix epoch.
     * @param ADC The 32-size array with ADC values.
     * @param coinc The ID of the strip that fired the trigger.
     */
    FEBData(uint16_t mac5, uint16_t flags, uint32_t ts0, uint32_t ts1, uint32_t unixs, adc_array_t ADC, uint32_t coinc);

    virtual ~FEBData();

    /**
     * Returns the ID of the CRT module.
     *
     * @return The MAC5 ID of this FEB data.
     */
    uint16_t Mac5() const;

    /**
     * Returns the event flags from the data taking.
     *
     * @return The event flags of this FEB data.
     */
    uint16_t Flags() const;

    /**
     * Returns the T0 time from the T0 counter.
     *
     * @return The Ts0 of this FEB data.
     */
    uint32_t Ts0() const;

    /**
     * Returns the T1 time from the T1 counter.
     *
     * @return The Ts1 of this FEB data.
     */
    uint32_t Ts1() const;

    /**
     * Returns the unix time of the event.
     *
     * @return The unix time of the FEB data.
     */
    uint32_t UnixS() const;

    /**
     * Returns the array of ACD counts from the FEB board.
     * 32 values are returned, one for each of the 32 SiPMs
     * in one CRT module.
     *
     * @return The ADC array of size 32 of this FEB data.
     */
    adc_array_t ADC() const;

    /**
     * Returns the ACD counts from a certain sipm in the FEB board.
     *
     * @param sipmID The index of the sipm (0-31)
     *
     * @return The ADC value for that sipm.
     */
    uint16_t ADC(size_t sipmID) const;

    /**
     * Returns the ID of the sipm that fired the trigger.
     *
     * @return The Coinc variable of this FEB data.
     */
    uint32_t Coinc() const;

    /**
     * Setter method for Mac5
     *
     * @param mac5 The mac5 to set.
     */
    void SetMac5(uint16_t mac5);

    /**
     * Setter method for flags
     *
     * @param flags The flags to set.
     */
    void SetFlags(uint16_t flags);

    /**
     * Setter method for Ts0
     *
     * @param ts0 The ts0 value to set
     */
    void SetTs0(uint32_t ts0);

    /**
     * Setter method for Ts1
     *
     * @param ts1 The ts1 value to set
     */
    void SetTs1(uint32_t ts1);

    /**
     * Setter method for unix time
     *
     * @param unixs The unix time to set.
     */
    void SetUnixS(uint32_t unixs);

    /**
     * Adds ADC values on a certain sipm.
     *
     * @param sipmID The ID of the sipm in the module (0-31).
     * @param adc The ADC value for this sipm.
     */
    void SetADC(size_t sipmID, uint16_t adc);

    /**
     * Setter method for coinc
     *
     * @param coinc The coinc values to set
     */
    void SetCoinc(uint32_t coinc);
  };

} // namespace sbnd::crt

#endif
