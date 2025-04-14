/**
 * \class CRTVeto
 *
 * \brief Product to store CRT Veto Flags for a given Event
 *
 * \author Alex Antonakis (aantonakis@ucsb.edu)
 *
 */

#ifndef SBND_CRTVETO_HH
#define SBND_CRTVETO_HH

namespace sbnd::crt {

  class CRTVeto {
    
   /**
    * Brief Description of Veto Variables:
    *
    * V0 --> veto on any CRT activity minus the CRT bottom tagger
    *
    * V1 --> Same as V0 but require that both Top Taggers were hit to veto 
    * on the CRT Top 
    *
    * V2 --> Same as V0 but do not veto on the North CRT Wall
    *
    * V3 --> Same as V2 but require that both Top Taggers were hit to veto 
    * on the CRT Top
    *
    * V4 --> Only Veto on the South CRT Wall 
    *
    * CRT activity that is used to veto lies within a fcl configureable time
    * window. This Window is chosen to be a narrow window around the 1.6 us beam 
    * window in the nominal configuration
    *
    */
 
    bool fV0;    
    bool fV1;    
    bool fV2;    
    bool fV3;    
    bool fV4;    

  public:

    CRTVeto();
    
    CRTVeto(bool _v0, bool _v1, bool _v2, bool _v3, bool _v4);

    virtual ~CRTVeto();

    bool V0() const;
    bool V1() const;
    bool V2() const;
    bool V3() const;
    bool V4() const;

  };
}

#endif
