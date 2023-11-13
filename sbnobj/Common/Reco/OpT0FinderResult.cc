#include "sbnobj/Common/Reco/OpT0FinderResult.h"

// define the constructor
sbn::OpT0Finder::OpT0Finder(int tpc, double time, double score, double measPE, double hypoPE,  
                std::vector<double> measPESpec_vec, 
                std::vector<double> hypoPESpec_vec, 
                std::vector<int> opch_vec)
    : tpc(tpc)
    , time(time)
    , score(score)
    , measPE(measPE)
    , hypoPE(hypoPE)
    , measPESpec(measPESpec_vec)
    , hypoPESpec(hypoPESpec_vec)
    , opch(opch_vec)
{    
}
    