#ifndef pmtSoftwareTrigger_h
#define pmtSoftwareTrigger_h

#include <cstddef>
#include <vector>


namespace sbnd::trigger {

  struct pmtPulse{
    double peak;
    double area;
    double t_start;
    double t_peak;
    double t_end;
    double pe;
    pmtPulse() {}
  };

  struct pmtInfo{ 
    int channel;
    double baseline;
    double baselineSigma; 
    std::vector<sbnd::trigger::pmtPulse> pulseVec;
    pmtInfo() {}
  };

  struct pmtSoftwareTrigger{

    bool foundBeamTrigger; 
    int nAboveThreshold;
    int triggerTimestamp;  // relative to beam window start, in ns
    double promptPE;       // total PE for the 100 ns following trigger time 
    double prelimPE;       // total PE for the 1 us before trigger time
    std::vector<sbnd::trigger::pmtInfo> pmtInfoVec;
    pmtSoftwareTrigger() {}
  };

} // namespace sbnd::trigger

#endif
