//
// Build a dictionary.
//
// $Id: classes.h,v 1.8 2010/04/12 18:12:28  Exp $
// $Author:  $
// $Date: 2010/04/12 18:12:28 $
// 
// Original author Rob Kutschke, modified by wes
//

#include "canvas/Persistency/Common/Wrapper.h"

// data-products
// lardataobj
#include "canvas/Persistency/Common/Assns.h"
#include "lardataobj/RecoBase/Hit.h"
#include "sbnobj/SBND/Blip/BlipDataTypes.h"
#include "lardataobj/RecoBase/SpacePoint.h"

//
// Only include objects that we would like to be able to put into the event.
// Do not include the objects they contain internally.
//

template class art::Assns<recob::Hit,blip::BlipReco>;
template class art::Wrapper<art::Assns<recob::Hit,blip::BlipReco> >;
template class std::vector<blip::BlipReco>;
template class art::Wrapper<std::vector<blip::BlipReco> >;
template class art::Assns<blip::BlipReco,recob::Hit>;
template class art::Wrapper<art::Assns<blip::BlipReco,recob::Hit> >;
template class art::Assns<blip::BlipReco,recob::SpacePoint>;
template class art::Wrapper<art::Assns<blip::BlipReco,recob::SpacePoint> >;
