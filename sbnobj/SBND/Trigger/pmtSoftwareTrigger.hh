#ifndef pmtSoftwareTrigger_h
#define pmtSoftwareTrigger_h

#include <cstddef>

namespace sbnd::trigger {

  struct pmtSoftwareTrigger{

    bool foundBeamTrigger;
    int triggerTimestamp; // relative to beam window start, in ns
    size_t nAboveThreshold;

    pmtSoftwareTrigger() {}

  };

} // namespace sbnd::trigger

#endif
