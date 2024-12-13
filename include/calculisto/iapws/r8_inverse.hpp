
#pragma once
#include "r8.hpp"
#include "r6_inverse.hpp"
    using namespace calculisto::root_finding;


    namespace 
calculisto::iapws::r8_inverse
{
    inline namespace 
r8_08_2008
{
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
relative_permittivity_pt (
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
              r8::relative_permittivity_dt (density.first, temperature)
            , density.second 
        };
    }
    else
    {
        return r8::relative_permittivity_dt (density, temperature);
    }
}
    template <info_tag_t InfoTag>
    constexpr auto
relative_permittivity_pt (
      auto const& pressure
    , auto const& temperature
    , info_t <InfoTag> info
){
    return relative_permittivity_pt (
          pressure
        , temperature
        , r6_inverse::initial_density (pressure, temperature)
        , info
    );
}
    constexpr auto
relative_permittivity_pt (auto const& pressure, auto const& temperature)
{
    return relative_permittivity_pt (pressure, temperature, info::none);
}

    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
relative_permittivity_tp (
      auto const& temperature
    , auto const& pressure
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
    return relative_permittivity_pt (pressure, temperature, initial_guess, info);
}
    template <info_tag_t InfoTag>
    constexpr auto
relative_permittivity_tp (
      auto const& temperature
    , auto const& pressure
    , info_t <InfoTag> info
){
    return relative_permittivity_pt (pressure, temperature, info);
}
    constexpr auto
relative_permittivity_tp (auto const& temperature, auto const& pressure)
{
    return relative_permittivity_pt (pressure, temperature, info::none);
}
} // namespace r8_08_2008
} // namespace calculisto::iapws::r8_inverse
