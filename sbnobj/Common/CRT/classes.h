#include "canvas/Persistency/Common/Wrapper.h"
#include "canvas/Persistency/Common/Assns.h"
#include "lardataobj/AnalysisBase/T0.h"
#include "lardataobj/Simulation/AuxDetSimChannel.h"
#include "sbnobj/Common/CRT/CRTHit.hh"
#include "sbnobj/Common/CRT/CRTTrack.hh"
#include "lardataobj/AnalysisBase/T0.h"
#include "lardataobj/RecoBase/OpFlash.h"
#include "sbnobj/Common/CRT/CRTTzero.hh"
#include "sbnobj/Common/CRT/CRTPMTMatching.hh"
#include "sbnobj/Common/CRT/CRTHit_Legacy.hh"
#include "sbnobj/Common/CRT/CRTTrack_Legacy.hh"
#include "sbnobj/Common/CRT/CRTTzero_Legacy.hh"
#include <vector>
#include <map>
#include <utility>

namespace{
  sbn::crt::CRTPMTMatchingInfo meta1;

  art::Assns<sbn::crt::CRTHit, recob::OpFlash, sbn::crt::CRTPMTMatchingInfo> assn11;
  art::Assns<recob::OpFlash, sbn::crt::CRTHit, sbn::crt::CRTPMTMatchingInfo> assn12;

  art::Assns<recob::OpFlash, sbn::crt::CRTPMTMatching> assn21;
  art::Assns<sbn::crt::CRTPMTMatching, recob::OpFlash> assn22;

  art::Assns<sbn::crt::CRTHit, sbn::crt::CRTPMTMatching> assn31;
  art::Assns<sbn::crt::CRTPMTMatching, sbn::crt::CRTHit> assn32;

}
