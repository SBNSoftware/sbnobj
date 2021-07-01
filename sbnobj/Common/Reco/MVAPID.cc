#include "sbnobj/Common/Reco/MVAPID.h"

#include "cetlib_except/exception.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include <algorithm>

void sbn::MVAPID::AddScore(int pdg, float score)
{
  if (!MVAScoreMap.try_emplace(pdg, score).second)
    throw cet::exception("MVAPID") << "Failed to add entry: " << pdg << " to MVA PID score map as it already exists" << std::endl;
}

std::pair<int, float> sbn::MVAPID::BestIter() const
{
  auto iter = std::max_element(MVAScoreMap.begin(), MVAScoreMap.end(), [](auto const& lhs, auto const& rhs) { return lhs.second < rhs.second; });

  if (iter == MVAScoreMap.end()) {
    mf::LogError("MVAPID") << "Failed to find max element in map" << std::endl;
    return {-1, std::numeric_limits<float>::lowest()};
  }

  return *iter;
}
