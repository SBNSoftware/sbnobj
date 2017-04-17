////////////////////////////////////////////////////////////////////////
/// \file   NoNoise.cc
/// \author F. Varanini
////////////////////////////////////////////////////////////////////////

#include <cmath>
#include "IGenNoise.h"
#include "art/Utilities/ToolMacros.h"
#include "messagefacility/MessageLogger/MessageLogger.h"
#include "cetlib/exception.h"

namespace icarus_tool
{

class NoNoise : IGenNoise
{
public:
    explicit NoNoise(const fhicl::ParameterSet& pset);
    
    ~NoNoise();
    
    void configure(const fhicl::ParameterSet& pset)                          override;

    void GenerateNoise(std::vector<float> &noise, double noise_factor) const override;
    
private:

};
    
//----------------------------------------------------------------------
// Constructor.
NoNoise::NoNoise(const fhicl::ParameterSet& pset)
{
    configure(pset);
}
    
NoNoise::~NoNoise()
{
}
    
void NoNoise::configure(const fhicl::ParameterSet& pset)
{
    // Nothing to do here
    return;
}

void NoNoise::GenerateNoise(std::vector<float> &noise, double noise_factor) const
{
    // Set all values to 0
    std::fill(noise.begin(), noise.end(), 0.);

    return;
}
    
DEFINE_ART_CLASS_TOOL(NoNoise)
}
