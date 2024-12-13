#pragma once
#include "r12.hpp"
#include "r6_inverse.hpp"
    using namespace calculisto::root_finding;


    namespace 
calculisto::iapws::r12_inverse
{
    inline namespace 
r12_08_2008
{
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
viscosity_pt (
      auto const& pressure
    , auto const& temperature
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
        const auto
    density = r6_inverse::density_pt (
          pressure
        , temperature
        , initial_guess
        , info
    );
    if constexpr (InfoTag != info::tag::none)
    {
        return std::pair { 
              r12::viscosity_dt (density.first, temperature)
            , density.second 
        };
    }
    else
    {
        return r12::viscosity_dt (density, temperature);
    }
}
    template <info_tag_t InfoTag>
    constexpr auto
viscosity_pt (
      auto const& pressure
    , auto const& temperature
    , info_t <InfoTag> info
){
    return viscosity_pt (
          pressure
        , temperature
        , r6_inverse::initial_density (pressure, temperature)
        , info
    );
}
    constexpr auto
viscosity_pt (auto const& pressure, auto const& temperature)
{
    return viscosity_pt (pressure, temperature, info::none);
}

    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
viscosity_tp (
      auto const& temperature
    , auto const& pressure
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
    return viscosity_pt (pressure, temperature, initial_guess, info);
}
    template <info_tag_t InfoTag>
    constexpr auto
viscosity_tp (
      auto const& temperature
    , auto const& pressure
    , info_t <InfoTag> info
){
    return viscosity_pt (pressure, temperature, info);
}
    constexpr auto
viscosity_tp (auto const& temperature, auto const& pressure)
{
    return viscosity_pt (pressure, temperature, info::none);
}
} // namespace r12_08_2008
} // namespace calculisto::iapws::r12_inverse
