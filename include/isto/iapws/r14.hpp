#pragma once
#include "detail/common.hpp"

    namespace 
isto::iapws::r14
{
    inline namespace 
r14_08_2011
{
    namespace
ih
{
    constexpr auto
melting_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
        using std::pow;
        auto const
    theta = temperature / (273.16 ISTO_IAPWS_U_T);
    return (
          1.
        + 0.119539337e7 * (1. - pow (theta, 0.300000e1))
        + 0.808183159e5 * (1. - pow (theta, 0.257500e2))
        + 0.333826860e4 * (1. - pow (theta, 0.103750e3))
    ) * (611.657 ISTO_IAPWS_U_P);
}
    constexpr auto
sublimation_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
        using std::pow, std::exp;
        auto const
    theta = temperature / (273.16 ISTO_IAPWS_U_T);
    return exp ((1. / theta) * (
          -0.212144006e2 * pow (theta, 0.333333333e-2)
        +  0.273203819e2 * pow (theta, 0.120666667e1 )
        + -0.610598130e1 * pow (theta, 0.170333333e1 )
    )) * (611.657 ISTO_IAPWS_U_P);
}
} // namespace ih
    namespace
iii
{
    constexpr auto
melting_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
        using std::pow;
        auto const
    theta = temperature / (251.165 ISTO_IAPWS_U_T);
    return (
        1. - 0.299948 * (1. - pow (theta, 60.))
    ) * (208.566e6 ISTO_IAPWS_U_P);
}
    constexpr auto
melting_temperature_p (ISTO_IAPWS_P auto const& pressure)
{
        using std::pow;
        auto const
    pi = pressure / (208.566e6 ISTO_IAPWS_U_P);
    return pow ((pi - 1. + 0.299948) / 0.299948, 1. / 60.) * (251.165 ISTO_IAPWS_U_T);
}
} // namespace iii
    namespace
v
{
    constexpr auto
melting_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
        using std::pow;
        auto const
    theta = temperature / (256.164 ISTO_IAPWS_U_T);
    return (
        1. - 1.18721 * (1. - pow (theta, 8.))
    ) * (350.1e6 ISTO_IAPWS_U_P);
}
    constexpr auto
melting_temperature_p (ISTO_IAPWS_P auto const& pressure)
{
        using std::pow;
        auto const
    pi = pressure / (350.1e6 ISTO_IAPWS_U_P);
    return pow ((pi - 1. + 1.18721) / 1.18721, 1. / 8.) * (256.164 ISTO_IAPWS_U_T);
}
} // namespace v
    namespace
vi
{
    constexpr auto
melting_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
        using std::pow;
        auto const
    theta = temperature / (273.31 ISTO_IAPWS_U_T);
    return (
        1. - 1.07476 * (1. - pow (theta, 4.6))
    ) * (632.4e6 ISTO_IAPWS_U_P);
}
    constexpr auto
melting_temperature_p (ISTO_IAPWS_P auto const& pressure)
{
        using std::pow;
        auto const
    pi = pressure / (632.4e6 ISTO_IAPWS_U_P);
    return pow ((pi - 1. + 1.07476) / 1.07476, 1. / 4.6) * (273.31 ISTO_IAPWS_U_T);
}
} // namespace vi
    namespace
vii
{
    constexpr auto
melting_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
        using std::pow, std::exp;
        auto const
    theta = temperature / (355. ISTO_IAPWS_U_T);
    return ( exp (
          0.173683e1  * (1. - pow (theta, -1.))
        - 0.544606e-1 * (1. - pow (theta,  5.))
        + 0.806106e-7 * (1. - pow (theta, 22.))
    )) * (2216e6 ISTO_IAPWS_U_P);
}
} // namespace vii
/* Not possible.
    constexpr auto
melting_pressure_t (ISTO_IAPWS_T auto const& temperature)
{

}
*/
    constexpr auto
sublimation_pressure_t (ISTO_IAPWS_T auto const& temperature)
{
    return ih::sublimation_pressure_t (temperature);
}

} // namespace r14_08_2011
} // namespace isto::iapws::r14

/*
Triple points:
ice Ih  – ice III – liquid 251.165 208.566e6
ice III – ice V   – liquid 256.164 350.1e6
ice V   – ice VI  – liquid 273.31  632.4e6
ice VI  – ice VII – liquid 355.    2216e6
*/
