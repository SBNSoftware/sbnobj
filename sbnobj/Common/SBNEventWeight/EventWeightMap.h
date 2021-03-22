#ifndef _SBN_EVENTWEIGHTMAP_H_
#define _SBN_EVENTWEIGHTMAP_H_

#include <map>
#include <vector>
#include <string>

namespace sbn {
  namespace evwgh {

/**
 * @typedef EventWeightMap
 * @brief Container for event-level weights
 *
 * Provides a mapping from a string identifier for a particular weight
 * calculator to the corresponding set of weights for each universe.
 */
typedef std::map<std::string, std::vector<float> > EventWeightMap;

  }  // namespace evwgh
}  // namespace sbn

#endif  // _SBN_EVENTWEIGHTMAP_H_

