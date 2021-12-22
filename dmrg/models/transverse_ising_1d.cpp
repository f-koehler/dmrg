#include "transverse_ising_1d.hpp"

#include <itensor/util/iterate.h>
#include <nlohmann/json.hpp>
#include <algorithm>
#include <cstddef>
#include <map>
#include <vector>

#include "/home/fkoehler/code/ising/dependencies/dmrg/dmrg/json.hpp"
#include "/home/fkoehler/code/ising/dependencies/dmrg/dmrg/terms.hpp"
#include "/home/fkoehler/code/ising/dependencies/dmrg/dmrg/types.hpp"

TransverseIsing1D::TransverseIsing1D(int L, bool periodic, const Real &J, const Real &hx, const Real &hz)
    : SpinHalf1D(L, periodic, false, false), m_J(J), m_hx(hx), m_hz(hz)
{
    m_one_body_terms.reserve(static_cast<std::size_t>(2 * L));
    m_two_body_terms.reserve(static_cast<std::size_t>(L));

    for (auto i : itensor::range1(L))
    {
        m_one_body_terms.push_back({-2.0 * hx, "Sx", i});
        m_one_body_terms.push_back({-2.0 * hz, "Sz", i});
    }

    for (auto i : itensor::range1(L - 1))
    {
        m_two_body_terms.push_back({-4.0 * J, "Sz", i, "Sz", i + 1});
    }
    if (periodic)
    {
        m_two_body_terms.push_back({-4.0 * J, "Sz", 1, "Sz", L});
    }
}

TransverseIsing1D::TransverseIsing1D(const json &js)
    : TransverseIsing1D(js["L"].get<int>(), js["periodic"].get<bool>(), js["J"].get<Real>(), js["hx"].get<Real>(),
                        js["hz"].get<Real>())
{
}

const Real &TransverseIsing1D::getJ() const
{
    return m_J;
}
const Real &TransverseIsing1D::getHx() const
{
    return m_hx;
}
const Real &TransverseIsing1D::getHz() const
{
    return m_hz;
}