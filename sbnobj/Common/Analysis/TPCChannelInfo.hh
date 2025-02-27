/**
 * \class TPCChannelInfo
 *
 * \ingroup anab
 *
 * \brief TPCChannel Analysis Info
 *
 */

#ifndef TPCChannelInfo_hh_
#define TPCChannelInfo_hh_


namespace anab {

  struct TPCChannelInfo{
    unsigned channel; //!< Channel number 
    float baseline; //!< Channel baseline
    float rms; //!< Channel RMS
    float even_fraction; //!< Fraction of even samples in waveform
    float xbad_fraction; //!< Fraction of samples equal to 0xBAD in the waveform
  };

}


#endif
