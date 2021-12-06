#ifndef pmtTrigger_hh_
#define pmtTrigger_hh_
#include <cstdint>

#include <vector>

namespace sbnd::comm {

  struct pmtTrigger{

    std::vector<int> numPassed;
    int maxPMTs;

    pmtTrigger() {}

  };

} // namespace sbnd::comm

#endif
