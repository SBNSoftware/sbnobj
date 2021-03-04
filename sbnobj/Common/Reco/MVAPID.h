// Class for holding the result of fitting a Landau-Guassian convolution

#ifndef sbncode_MVAPID_H
#define sbncode_MVAPID_H

#include <map>
#include <string>

namespace sbn {
class MVAPID {
  public:
  MVAPID() {}

  std::map<int, float> mMVAScoreMap; // MVA Scores: Key is PDG of hypothesis and value is the MVA score

  void AddScore(int pdg, float score); // Function to call to add a new score to the map

  std::pair<int, float> BestIter();                      // Funtion to return the map iterator with the highest score
  int BestPDG() { return this->BestIter().first; };      // Funtion to return the hypothesis with the highest score
  float BestScore() { return this->BestIter().second; }; // Function to return the highest score from any hypothesis
};
}

#endif
