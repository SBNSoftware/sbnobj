#include "sbnobj/Common/Reco/MVAPID.h"

#include "cetlib_except/exception.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include <algorithm>

void sbn::MVAPID::AddScore(int pdg, float score)
{
  auto [iter, success] = mMVAScoreMap.try_emplace(pdg, score);
  if (!success)
    throw cet::exception("MVAPID") << "Failed to add entry: " << pdg << " to MVA PID score map as it already exists" << std::endl;
}

std::pair<int, float> sbn::MVAPID::BestIter() const
{
  auto iter = std::max_element(mMVAScoreMap.begin(), mMVAScoreMap.end(), [](auto const& lhs, auto const& rhs) { return lhs.second < rhs.second; });

  if (iter == mMVAScoreMap.end()) {
    mf::LogError("MVAPID") << "Failed to find max element in map" << std::endl;
    return std::make_pair<int, float>(-1, std::numeric_limits<float>::lowest());
  }

  return *iter;
}
