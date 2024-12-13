#pragma once
#include "r6.hpp"
#include "r7.hpp"
#include <calculisto/root_finding/root_finding.hpp>
    using namespace calculisto::root_finding;

    namespace
calculisto::iapws::r6_inverse
{
    inline namespace
r6_95_2016
{
    constexpr auto
initial_density (
        auto const& pressure
    , auto const& temperature
){
    return (
            pressure > 100e6 
        || (
                temperature > 1073.15 
            && pressure > 50e6
        ))
    ? 1000.
    : r7::density_pt (pressure, temperature)
;
}

    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density_pt (
      auto const& pressure
    , auto const& temperature
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
        using namespace r6;
        using namespace r6::detail;
        auto
    tau = critical_temperature / temperature;
    return newton (
          [=](auto density)
          { 
            return r6::pressure_dt (density, temperature) - pressure; 
          }
        , [=](auto density)
          {
                using namespace detail;
                auto
            delta = density / critical_density;
            return (1 + 2 * delta * phi_r_d (delta, tau) + delta * delta * phi_r_dd (delta, tau)) * massic_gas_constant * temperature;
          }
        , initial_guess
        , { 
            .converged = [](auto curr, auto prev, auto f)
            { 
                return fabs (f) < 1e-8 || fabs ((curr - prev)/curr) < 1e-8; 
            } 
          } // options
        , info
    );
}
    template <info_tag_t InfoTag>
    constexpr auto
density_pt (
      auto const& pressure
    , auto const& temperature
    , info_t <InfoTag> info
){
    return density_pt (pressure, temperature, initial_density (pressure, temperature), info);
}
    constexpr auto
density_pt (
      auto const& pressure
    , auto const& temperature
){
    return density_pt (pressure, temperature, initial_density (pressure, temperature), info::none);
}
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density_tp (
      auto const& temperature
    , auto const& pressure
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
    return density_pt (pressure, temperature, initial_guess, info);
}
    template <info_tag_t InfoTag>
    constexpr auto
density_tp (
      auto const& temperature
    , auto const& pressure
    , info_t <InfoTag> info
){
    return density_pt (pressure, temperature, info);
}
    constexpr auto
density_tp (
      auto const& temperature
    , auto const& pressure
){
    return density_pt (pressure, temperature, info::none);
}

#define ISTO_IAPWS_R6_INVERSE_GEN(NAME)                                      \
    template <info_tag_t InfoTag = info::tag::none>                          \
    constexpr auto                                                           \
NAME##_pt (                                                                  \
      auto const& pressure                                                   \
    , auto const& temperature                                                \
    , auto const& density_initial_guess                                      \
    , info_t <InfoTag> info = info::none                                     \
){                                                                           \
        const auto                                                           \
    d = density_pt (pressure, temperature, density_initial_guess, info);     \
    if constexpr (InfoTag != info::tag::none)                                \
    {                                                                        \
        return std::pair { r6::NAME##_dt (d.first, temperature), d.second }; \
    }                                                                        \
    else                                                                     \
    {                                                                        \
        return r6::NAME##_dt (d, temperature);                               \
    }                                                                        \
}                                                                            \
                                                                             \
    template <info_tag_t InfoTag>                                            \
    constexpr auto                                                           \
NAME##_pt (                                                                  \
      auto const& pressure                                                   \
    , auto const& temperature                                                \
    , info_t <InfoTag> info                                                  \
){                                                                           \
    return NAME##_pt (                                                       \
          pressure                                                           \
        , temperature                                                        \
        , initial_density (pressure, temperature)                            \
        , info                                                               \
    );                                                                       \
}                                                                            \
                                                                             \
    constexpr auto                                                           \
NAME##_pt (                                                                  \
      auto const& pressure                                                   \
    , auto const& temperature                                                \
){                                                                           \
    return NAME##_pt (                                                       \
          pressure                                                           \
        , temperature                                                        \
        , initial_density (pressure, temperature)                            \
        , info::none                                                         \
    );                                                                       \
}                                                                            \
                                                                             \
    template <info_tag_t InfoTag = info::tag::none>                          \
    constexpr auto                                                           \
NAME##_tp (                                                                  \
      auto const& temperature                                                \
    , auto const& pressure                                                   \
    , auto const& density_initial_guess                                      \
    , info_t <InfoTag> info = info::none                                     \
){                                                                           \
    return NAME##_pt (                                                       \
          pressure                                                           \
        , temperature                                                        \
        , density_initial_guess                                              \
        , info                                                               \
    );                                                                       \
}                                                                            \
                                                                             \
    template <info_tag_t InfoTag>                                            \
    constexpr auto                                                           \
NAME##_tp (                                                                  \
      auto const& temperature                                                \
    , auto const& pressure                                                   \
    , info_t <InfoTag> info                                                  \
){                                                                           \
    return NAME##_pt (                                                       \
          pressure                                                           \
        , temperature                                                        \
        , info                                                               \
    );                                                                       \
}                                                                            \
                                                                             \
    constexpr auto                                                           \
NAME##_tp (                                                                  \
      auto const& temperature                                                \
    , auto const& pressure                                                   \
){                                                                           \
    return NAME##_pt (                                                       \
          pressure                                                           \
        , temperature                                                        \
        , info::none                                                         \
    );                                                                       \
}                                                                                      

ISTO_IAPWS_R6_INVERSE_GEN(massic_internal_energy)
ISTO_IAPWS_R6_INVERSE_GEN(massic_entropy)
ISTO_IAPWS_R6_INVERSE_GEN(massic_enthalpy)
ISTO_IAPWS_R6_INVERSE_GEN(massic_isochoric_heat_capacity)
ISTO_IAPWS_R6_INVERSE_GEN(massic_isobaric_heat_capacity)
//ISTO_IAPWS_R6_INVERSE_GEN(joule_thompson_coefficient)
ISTO_IAPWS_R6_INVERSE_GEN(massic_gibbs_free_energy)
ISTO_IAPWS_R6_INVERSE_GEN(speed_of_sound)
ISTO_IAPWS_R6_INVERSE_GEN(isothermal_stress_coefficient)
ISTO_IAPWS_R6_INVERSE_GEN(relative_pressure_coefficient)
//ISTO_IAPWS_R6_INVERSE_GEN(isobaric_cubic_expansion_coefficient)
//ISTO_IAPWS_R6_INVERSE_GEN(isothermal_compressibility)
#undef ISTO_IAPWS_R6_INVERSE_GEN

#ifdef ISTO_IAPWS_FLAVOR_CONSTRAINED
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density (
      auto const& pressure
    , auto const& temperature
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
    return density_pt (pressure, temperature, initial_guess, info);
}
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density (
      auto const& pressure
    , auto const& temperature
    , info_t <InfoTag> info = info::none
){
    return density_pt (pressure, temperature, info);
}
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density (
      auto const& temperature
    , auto const& pressure
    , auto const& initial_guess
    , info_t <InfoTag> info = info::none
){
    return density_tp (temperature, pressure, initial_guess, info);
}
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density (
      auto const& temperature
    , auto const& pressure
    , info_t <InfoTag> info = info::none
){
    return density_tp (temperature, pressure, info);
}

#define ISTO_IAPWS_R6_INVERSE_GEN(NAME)                            \
    template <info_tag_t InfoTag = info::tag::none>                \
    constexpr auto                                                 \
NAME (                                                             \
      auto const& pressure                                         \
    , auto const& temperature                                      \
    , auto const& initial_guess                                    \
    , info_t <InfoTag> info = info::none                           \
){                                                                 \
    return NAME##_pt (pressure, temperature, initial_guess, info); \
}                                                                  \
    template <info_tag_t InfoTag = info::tag::none>                \
    constexpr auto                                                 \
NAME (                                                             \
      auto const& pressure                                         \
    , auto const& temperature                                      \
    , info_t <InfoTag> info = info::none                           \
){                                                                 \
    return NAME##_pt (pressure, temperature, info);                \
}                                                                  \
    template <info_tag_t InfoTag = info::tag::none>                \
    constexpr auto                                                 \
NAME (                                                             \
      auto const& temperature                                      \
    , auto const& pressure                                         \
    , auto const& initial_guess                                    \
    , info_t <InfoTag> info = info::none                           \
){                                                                 \
    return NAME##_tp (temperature, pressure, initial_guess, info); \
}                                                                  \
    template <info_tag_t InfoTag = info::tag::none>                \
    constexpr auto                                                 \
NAME (                                                             \
      auto const& temperature                                      \
    , auto const& pressure                                         \
    , info_t <InfoTag> info = info::none                           \
){                                                                 \
    return NAME##_tp (temperature, pressure, info);                \
}

ISTO_IAPWS_R6_INVERSE_GEN(massic_internal_energy)
ISTO_IAPWS_R6_INVERSE_GEN(massic_entropy)
ISTO_IAPWS_R6_INVERSE_GEN(massic_enthalpy)
ISTO_IAPWS_R6_INVERSE_GEN(massic_isochoric_heat_capacity)
ISTO_IAPWS_R6_INVERSE_GEN(massic_isobaric_heat_capacity)
//ISTO_IAPWS_R6_INVERSE_GEN(joule_thompson_coefficient)
ISTO_IAPWS_R6_INVERSE_GEN(massic_gibbs_free_energy)
ISTO_IAPWS_R6_INVERSE_GEN(speed_of_sound)
ISTO_IAPWS_R6_INVERSE_GEN(isothermal_stress_coefficient)
ISTO_IAPWS_R6_INVERSE_GEN(relative_pressure_coefficient)
//ISTO_IAPWS_R6_INVERSE_GEN(isobaric_cubic_expansion_coefficient)
//ISTO_IAPWS_R6_INVERSE_GEN(isothermal_compressibility)
#undef ISTO_IAPWS_R6_INVERSE_GEN
#endif
} // inline namespace r6_95_2016
} // namespace calculisto::iapws::r6_inverse
