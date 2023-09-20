#ifndef sbnobj_OpT0FinderVars_H
#define sbnobj_OpT0FinderVars_H
#include <vector>

namespace sbn
{
  class OpT0Finder
  {
  public: 

    int    tpc;     // tpc that the matching was performed in
    double time;    // flash-matched t0  
    double score;   // OpT0 score of the match; is the reciprocal of the LLH score or chi-squared score 
    double measPE;  // total PE of the measured flash 
    double hypoPE;  // total PE of the hypothetical flash 
    std::vector<double> measPESpec; // PE per channel of the measured flash 
    std::vector<double> hypoPESpec; // PE per channel of the hypothetical flash 
    std::vector<int>    opch;       // boolean vector of which opchannels were used for the matching, 1 if used and 0 if not used

    OpT0Finder(
      int tpc, double time, double score, double measPE, double hypoPE,  
      std::vector<double> measPESpec_vec, 
      std::vector<double> hypoPESpec_vec, 
      std::vector<int> opch_vec); // declare the constructor 
    OpT0Finder() {} // default constructor
    
  };
}

#endif
