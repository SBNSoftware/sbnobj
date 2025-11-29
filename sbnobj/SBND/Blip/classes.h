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
//#include "lardata/Utilities/AssociationUtil.h"
#include "canvas/Persistency/Common/Assns.h"
#include "lardataobj/RecoBase/PFParticle.h"
#include "lardataobj/RecoBase/Hit.h"
#include "nusimdata/SimulationBase/MCTruth.h"
#include "sbnobj/SBND/Blip/BlipDataTypes.h"
#include "lardataobj/RecoBase/SpacePoint.h"

//
// Only include objects that we would like to be able to put into the event.
// Do not include the objects they contain internally.
//
<class name="std::map<int,geo::Point_t>"/>;
<class name="blip::HitClust" ClassVersion="10" />;
<class name="vector<blip::HitClust>"/>;
<class name="art::Wrapper<std::vector<blip::HitClust> >"/>;
<class name="blip::Blip" ClassVersion="10" />;
<class name="std::vector<blip::Blip>"/>;
<class name="art::Wrapper<std::vector<blip::Blip> >"/>;
<class name="blip::TrueBlip" ClassVersion="10" />;
<class name="art::Assns<blip::Blip,recob::Hit,void>"/>;
<class name="art::Assns<recob::Hit, blip::Blip,void>"/>;
<class name="art::Assns<blip::Blip,recob::SpacePoint,void>"/>;
<class name="art::Wrapper<art::Assns<blip::Blip,recob::Hit,void> >"/>;
<class name="art::Wrapper<art::Assns<recob::Hit,blip::Blip,void> >"/>;
<class name="art::Wrapper<art::Assns<blip::Blip,recob::SpacePoint,void> >"/>;