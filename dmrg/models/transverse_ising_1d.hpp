#ifndef DMRG_MODELS_TRANSVERSE_ISING_1D
#define DMRG_MODELS_TRANSVERSE_ISING_1D

#include "../json.hpp"
#include "../types.hpp"
#include "spin_half_1d.hpp"

class TransverseIsing1D : public SpinHalf1D
{
  protected:
    Real m_J;
    Real m_hx;
    Real m_hz;

  public:
    explicit TransverseIsing1D(int L, bool periodic, const Real &J, const Real &hx, const Real &hz);
    explicit TransverseIsing1D(const json &js);

    const Real &getJ() const;
    const Real &getHx() const;
    const Real &getHz() const;
};

#endif /* DMRG_MODELS_TRANSVERSE_ISING_1D */
