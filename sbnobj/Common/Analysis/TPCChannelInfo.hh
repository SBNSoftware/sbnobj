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
    unsigned channel;
    float baseline;
    float rms;
  };

}


#endif
