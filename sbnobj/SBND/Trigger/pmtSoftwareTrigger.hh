#ifndef pmtSoftwareTrigger_h
#define pmtSoftwareTrigger_h

#include <cstddef>

namespace sbnd::trigger {

  struct pmtSoftwareTrigger{

    size_t nAboveThreshold;
    int triggerTimestamp; // relative to beam window start, in ns

    pmtSoftwareTrigger() {}

  };

} // namespace sbnd::trigger

#endif
