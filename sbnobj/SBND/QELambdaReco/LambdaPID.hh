#ifndef SBND_LAMBDAPID_H
#define SBND_LAMBDAPID_H

#include <limits>

namespace qelambda {

  struct QELambdaPID {
    float VtxX          = -999;
    float VtxY          = -999;
    float VtxZ          = -999;
    float ProtonKE      = -999;
    float PionKE        = -999;
    float ProtonPX    = -999;
    float ProtonPY    = -999;
    float ProtonPZ    = -999;
    float PionPX      = -999;
    float PionPY      = -999;
    float PionPZ      = -999;

    void SetDefault();
  };

} // namespace qelambda

#endif // SBND_LAMBDAPID_H