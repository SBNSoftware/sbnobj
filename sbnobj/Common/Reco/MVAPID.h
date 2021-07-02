// Class for holding the result of an MVA PID

#ifndef sbncode_MVAPID_H
#define sbncode_MVAPID_H

#include <map>

namespace sbn {
class MVAPID {
  public:
  MVAPID() {}

  std::map<int, float> mvaScoreMap; // MVA Scores: Key is PDG of hypothesis and value is the MVA score

  void AddScore(int pdg, float score); // Add a new score to the map

  std::pair<int, float> BestIter() const;                             // Returns the map iterator with the highest score
  inline int BestPDG() const { return this->BestIter().first; };      // Returns the hypothesis with the highest score
  inline float BestScore() const { return this->BestIter().second; }; // Returns the highest score from any hypothesis
};
}

#endif
