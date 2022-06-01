#ifndef _SBN_EVENTWEIGHTPARAMETERSET_H_
#define _SBN_EVENTWEIGHTPARAMETERSET_H_

#include <string>
#include <map>
#include <vector>
#include "TMatrixD.h"

namespace CLHEP { class HepRandomEngine; }

namespace sbn {
  namespace evwgh {

/**
 * @struct EventWeightParameter
 * @brief A single parameter to be reweighted.
 */
struct EventWeightParameter {
  /** Default constructor. */
  EventWeightParameter() : fName(""), fMean(0), fWidth(1), fCovIndex(0) {}

  /** Constructor specifying all parameter properties. */
  EventWeightParameter(std::string name, float mean, float width, size_t covIndex=0)
      : fName(name), fMean(mean), fWidth(width), fCovIndex(covIndex) {}

  EventWeightParameter(std::string name, float mean, std::vector<float> widths, size_t covIndex=0)
      : fName(name), fMean(mean), fWidth(0), fCovIndex(covIndex), fWidths(widths) {}

  /** Comparison operator (required for use as an std::map key). */
  inline friend bool operator<(const EventWeightParameter& lhs,
                               const EventWeightParameter& rhs) {
    return lhs.fName < rhs.fName;
  }

  /** Equality operator, testing equality of all members. */
  inline friend bool operator==(const EventWeightParameter& lhs,
                                const EventWeightParameter& rhs) {
    return (lhs.fName == rhs.fName &&
            lhs.fMean == rhs.fMean &&
            lhs.fWidth == rhs.fWidth &&
            lhs.fCovIndex == rhs.fCovIndex &&
            lhs.fWidths == rhs.fWidths);
  }

  std::string fName;  //!< Parameter name
  float fMean;  //!< Gaussian mean
  float fWidth;  //!< Gaussian sigma
  size_t fCovIndex;  //!< Index in the covariance matrix (if any)
  std::vector<float> fWidths; //!< for multi sigma modes
};


/**
 * @class EventWeightParameterSet
 * @brief Container for a set of reweightable parameters
 *
 * This class performs the random sampling of reweightable parameters
 * according to user configuration and provides persistence of the sampled
 * values.
 */
class EventWeightParameterSet {
public:
  /** The type of random throws to perform. */
  //==== ReweightType_t in sbnanaobj/StandardRecord/SREnums.h should be synchronized to this
  typedef enum rwtype
  {
    kDefault = -1,
    kMultisim = 0,
    kPMNSigma = 1,
    kFixed = 2,
    kMultisigma = 3,
  } ReweightType;

  /** Default constructor. */
  EventWeightParameterSet() : fCovarianceMatrix(nullptr), fRWType(kDefault) {}

  /** Equality operator, testing equality of all members. */
  inline friend bool operator==(const EventWeightParameterSet& lhs,
                                const EventWeightParameterSet& rhs) {
    return (lhs.fParameterMap == rhs.fParameterMap &&
            lhs.fCovarianceMatrix == rhs.fCovarianceMatrix &&
            lhs.fName == rhs.fName &&
            lhs.fRWType == rhs.fRWType &&
            lhs.fNuniverses == rhs.fNuniverses);
  }

  /**
   * Configure the parameter set.
   *
   * @param name Name of the parameter set
   * @param rwtype Specifies the type of random throws to perform
   * @param nuni Number of random throws (universes)
   */
  void Configure(std::string name, ReweightType rwtype, size_t nuni=1);

  /**
   * Configure the parameter set with a string reweight type,
   *
   * @param name Name of the parameter set
   * @param rwtype_string Specifies the type of random throws to perform
   * @param nuni Number of random throws (universes)
   */
  void Configure(std::string name, std::string rwtype_string, size_t nuni=1);

  /**
   * Add a new parameter to the set.
   *
   * @param name Name of the parameter
   * @param width Standard deviation for Gaussian throws
   * @param mean Optional nonzero mean for Gaussian throws
   * @param covIndex Optional Index in the (optional) covariance matrix
   */
  void AddParameter(std::string name, float width, float mean=0, size_t covIndex=0);
  void AddParameter(std::string name, std::vector<float> widths, float mean=0, size_t covIndex=0);

  /**
   * Specify a covariance matrix for correlated throws.
   *
   * Note: use the covIndex argument to AddParameter to specify the index
   * in the covariance matrix that corresponds to a particular parameter.
   *
   * @param cov The covariance matrix
   */
  void SetCovarianceMatrix(TMatrixD* cov) { fCovarianceMatrix = cov; }

  /**
   * Perform the random sampling.
   *
   * This function should be called only after the parameter set has been
   * configured and all parameters have been added. It will perform the
   * random sampling of all parameters to populate the parameter map
   * (fParameterMap) which contains the parameter values for universe for
   * each parameter.
   *
   * A random number generator engine is provided here, to enable throws with
   * different, fixed user-controlled random seeds for each parameter set.
   *
   * @param engine The random number generator engine to use for sampling.
   */
  void Sample(CLHEP::HepRandomEngine& engine);

public:
  std::map<EventWeightParameter, std::vector<float> > fParameterMap;  //!< Mapping of definitions to the set of values
  TMatrixD* fCovarianceMatrix;  //!< Covariance matrix for correlated throws (optional)
  std::string fName;  //!< Name of the parameter set
  ReweightType fRWType;  //!< Type of throws (the same for all parameters in a set)
  size_t fNuniverses;  //!< Number of universes (i.e. random throws)
};

  }  // namespace evwgh
}  // namespace sbn

#endif  // _SBN_EVENTWEIGHTPARAMETERSET_H_

