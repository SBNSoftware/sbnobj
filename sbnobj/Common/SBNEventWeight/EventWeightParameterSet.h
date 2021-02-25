#ifndef _SBN_EVENTWEIGHTPARAMETERSET_H_
#define _SBN_EVENTWEIGHTPARAMETERSET_H_

#include <string>
#include <map>
#include <vector>
#include "TMatrixD.h"

namespace CLHEP { class HepRandomEngine; }

namespace sbn {
  namespace evwgh {

struct EventWeightParameter {
  EventWeightParameter() : fName(""), fMean(0), fWidth(1), fCovIndex(0) {}
  EventWeightParameter(std::string name, float mean, float width, size_t covIndex=0)
      : fName(name), fMean(mean), fWidth(width), fCovIndex(covIndex) {}

  friend bool operator<(const EventWeightParameter& lhs, const EventWeightParameter& rhs) {
    return lhs.fName < rhs.fName;
  }

  std::string fName;  //!< Parameter name
  float fMean;  //!< Gaussian mean
  float fWidth;  //!< Gaussian sigma
  size_t fCovIndex;  //!< Index in the covariance matrix (if any)
};


class EventWeightParameterSet {
public:
  typedef enum rwtype { kMultisim, kPMNSigma, kFixed, kDefault } ReweightType;

  EventWeightParameterSet() : fCovarianceMatrix(nullptr), fRWType(kDefault) {}

  void Configure(std::string name, ReweightType rwtype, size_t nuni=1);

  void Configure(std::string name, std::string rwtype_string, size_t nuni=1);

  void AddParameter(std::string name, float width,
                    float mean=0, size_t covIndex=0);

  void SetCovarianceMatrix(TMatrixD* cov) { fCovarianceMatrix = cov; }

  void Sample(CLHEP::HepRandomEngine& engine);

  std::map<EventWeightParameter, std::vector<float> > fParameterMap;
  TMatrixD* fCovarianceMatrix;

  std::string fName;
  ReweightType fRWType;
  size_t fNuniverses;
};

  }  // namespace evwgh
}  // namespace sbn

#endif  // _SBN_EVENTWEIGHTPARAMETERSET_H_

