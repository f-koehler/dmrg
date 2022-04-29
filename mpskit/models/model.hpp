#ifndef MPSKIT_MODELS_MODEL
#define MPSKIT_MODELS_MODEL

#include <itensor/mps/mpo.h>
#include <itensor/mps/mps.h>
#include <itensor/mps/siteset.h>
#include <map>
#include <string>
#include <vector>

#include "../observable.hpp"
#include "../point_functions.hpp"

struct Observable;
struct OnePointFunction;
struct TwoPointFunction;

class Model
{
  protected:
    itensor::SiteSet m_sites;

  public:
    explicit Model(itensor::SiteSet sites);
    virtual ~Model() = default;

    virtual itensor::MPS getInitialState(const std::string &initial_state) const = 0;
    virtual itensor::MPO getHamiltonian() const = 0;
    virtual std::map<std::string, Observable> getObservables() const;
    virtual std::map<std::string, std::vector<OnePointFunction>> getOnePointFunctions() const;
    virtual std::map<std::string, std::vector<TwoPointFunction>> getTwoPointFunctions() const;

    const itensor::SiteSet &getSites() const;
};

#endif /* MPSKIT_MODELS_MODEL */
