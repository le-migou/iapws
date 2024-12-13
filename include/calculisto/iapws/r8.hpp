#pragma once
#include <numbers>
#include "detail/common.hpp"
#include "r6.hpp"

    namespace
calculisto::iapws::r8
{
    inline namespace
r8_09_1997
{
    namespace
detail
{
        constexpr auto
    N = array_t
    {
           0.978224486826
        , -0.957771379375
        ,  0.237511794148
        ,  0.714692244396
        , -0.298217036956
        , -0.108863472196
        ,  0.949327488264e-1
        , -0.980469816509e-2
        ,  0.165167634970e-4
        ,  0.937359795772e-4
        , -0.123179218720e-9
    };

        constexpr auto
    N_12 = 0.196096504426e-2;

        constexpr auto
    i = array_t
    {
          1.
        , 1.
        , 1.
        , 2.
        , 3.
        , 3.
        , 4.
        , 5.
        , 6.
        , 7.
        , 10.
    };

        constexpr auto
    j = array_t
    {
          0.25
        , 1.
        , 2.5
        , 1.5
        , 1.5
        , 2.5
        , 2.
        , 2.
        , 5.
        , 0.5
        , 10.
    };

        constexpr auto
    permittivity_of_free_space = 
        1. / (4e-7 * std::numbers::pi * 299792458 * 299792458);

        constexpr auto
    mean_molecular_polarizability = 1.636e-40;

        constexpr auto
    molecular_dipole_moment = 6.138e-30;

        constexpr auto
    boltzmann_constant = 1.380658e-23;

        constexpr auto
    avogadro_number = 6.0221367e23;

        constexpr auto
    molar_mass_of_water = 0.018015268;
    
        constexpr auto
    critical_molar_density = 322 / molar_mass_of_water;

        constexpr auto
    critical_temperature = 647.096;

        constexpr auto
    g (auto const& molar_density, auto const& temperature)
    {
            using std::pow;
            const auto
        rho = molar_density / critical_molar_density;
            const auto
        tau = critical_temperature / temperature;
        return 
              1 
            + sum (N * pow (rho, i) * pow (tau, j)) 
            + N_12 * rho * pow (temperature / 228 - 1, -1.2)
        ;
    }
        constexpr auto
    dgdt (auto const& molar_density, auto const& temperature)
    {
            using std::pow;
            const auto
        rho = molar_density / critical_molar_density;
            const auto
        tau = critical_temperature / temperature;
        return 
              sum (
                -j / critical_temperature * N * pow (rho, i) * pow (tau, j + 1)
              ) 
            - 1.2 / 228 * N_12 * rho * pow (temperature / 228 - 1, -2.2)
        ;
    }
        constexpr auto
    dgdtt (auto const& molar_density, auto const& temperature)
    {
            using std::pow;
            const auto
        rho = molar_density / critical_molar_density;
            const auto
        tau = critical_temperature / temperature;
        return 
              sum (
                  j * (j + 1) / critical_temperature / critical_temperature 
                * N * pow (rho, i) * pow (tau, j + 2)
              ) 
            + 2.64 / 51984 * N_12 * rho * pow (temperature / 228 - 1, -3.2)
        ;
    }
        constexpr auto
    dgdr (auto const& molar_density, auto const& temperature)
    {
            using std::pow;
            const auto
        rho = molar_density / critical_molar_density;
            const auto
        tau = critical_temperature / temperature;
        return 
              sum (
                i * N / critical_molar_density * pow (rho, i - 1) * pow (tau, j)
              ) 
            + N_12 / critical_molar_density * pow (temperature / 228 - 1, -1.2)
        ;
    }
        constexpr auto
    dgdrr (auto const& molar_density, auto const& temperature)
    {
            using std::pow;
            const auto
        rho = molar_density / critical_molar_density;
            const auto
        tau = critical_temperature / temperature;
        return 
              sum (
                  i * (i - 1) * N 
                / critical_molar_density / critical_molar_density 
                * pow (rho, i - 2) * pow (tau, j)
              ) 
        ;
    }
        constexpr auto
    dgdtr (auto const& molar_density, auto const& temperature)
    {
            using std::pow;
            const auto
        rho = molar_density / critical_molar_density;
            const auto
        tau = critical_temperature / temperature;
        return 
              sum (
                -j * i / critical_temperature / critical_molar_density * N 
                * pow (rho, i - 1) * pow (tau, j + 1)
              ) 
            - 1.2 / 228 * N_12 / critical_molar_density 
            * pow (temperature / 228 - 1, -2.2)
        ;
    }
        constexpr auto
    a (
          auto const& molar_density
        , auto const& temperature
        , auto const& g
    ){
        return 
              avogadro_number 
            * molecular_dipole_moment 
            * molecular_dipole_moment 
            / permittivity_of_free_space 
            / boltzmann_constant 
            * molar_density 
            / temperature
            * g
        ;
    }
        constexpr auto
    dadt (
          auto const& molar_density
        , auto const& temperature
        , auto const& g
        , auto const& dgdt
    ){
        return 
              avogadro_number 
            * molecular_dipole_moment 
            * molecular_dipole_moment 
            / permittivity_of_free_space 
            / boltzmann_constant 
            * molar_density 
            / temperature
            * (dgdt - g / temperature)
        ;
    }
        constexpr auto
    dadtt (
          auto const& molar_density
        , auto const& temperature
        , auto const& g
        , auto const& dgdt
        , auto const& dgdtt
    ){
        return 
              avogadro_number 
            * molecular_dipole_moment 
            * molecular_dipole_moment 
            / permittivity_of_free_space 
            / boltzmann_constant 
            * molar_density 
            / temperature
            * (
                  dgdtt 
                - 2 * dgdt / temperature
                + 2 * g / temperature / temperature
              )
        ;
    }
        constexpr auto
    dadr (
          auto const& molar_density
        , auto const& temperature
        , auto const& g
        , auto const& dgdr
    ){
        return 
              avogadro_number 
            * molecular_dipole_moment 
            * molecular_dipole_moment 
            / permittivity_of_free_space 
            / boltzmann_constant 
            / temperature
            * (dgdr * molar_density + g)
        ;
    }
        constexpr auto
    dadrr (
          auto const& molar_density
        , auto const& temperature
        , auto const& dgdr
        , auto const& dgdrr
    ){
        return 
              avogadro_number 
            * molecular_dipole_moment 
            * molecular_dipole_moment 
            / permittivity_of_free_space 
            / boltzmann_constant 
            / temperature
            * (dgdrr * molar_density + 2 * dgdr)
        ;
    }
        constexpr auto
    dadtr (
          auto const& molar_density
        , auto const& temperature
        , auto const& g
        , auto const& dgdt
        , auto const& dgdr
        , auto const& dgdtr
    ){
        return 
              avogadro_number 
            * molecular_dipole_moment 
            * molecular_dipole_moment 
            / permittivity_of_free_space 
            / boltzmann_constant 
            / temperature
            * (
                  molar_density * dgdtr 
                + dgdt 
                - (g + molar_density * dgdr) / temperature
              )
        ;
    }
        constexpr auto
    b (auto const& molar_density)
    {
        return
              avogadro_number
            * mean_molecular_polarizability
            * molar_density
            / 3
            / permittivity_of_free_space
        ;
    }
        constexpr auto
    dbdr ()
    {
        return
              avogadro_number
            * mean_molecular_polarizability
            / 3
            / permittivity_of_free_space
        ;
    }
        constexpr auto
    c (auto const& A, auto const& B)
    {
        return 9 + 2 * A + 18 * B + A * A + 10 * A * B + 9 * B * B;
    }
        constexpr auto
    half_dcdt (auto const& A, auto const& B, auto const& dAdt)
    {
        return dAdt * (1 + A + 5 * B);
    }
        constexpr auto
    half_dcdtt (
          auto const& A
        , auto const& B
        , auto const& dAdt
        , auto const& dAdtt
    ){
        return dAdtt * (1 + A + 5 * B) + dAdt * dAdt;
    }
        constexpr auto
    half_dcdr (auto const& A, auto const& B, auto const& dAdr, auto const& dBdr)
    {
        return dAdr * (1 + A + 5 * B) + dBdr * (9 + 5 * A + 9 * B);
    }
        constexpr auto
    half_dcdrr (
          auto const& A
        , auto const& B
        , auto const& dAdr
        , auto const& dAdrr
        , auto const& dBdr
    ){
        return dAdrr * (1 + A + 5 * B) 
            + dAdr * dAdr 
            + 10 * dAdr * dBdr 
            + 9 * dBdr * dBdr
        ;
    }
        constexpr auto
    half_dcdtr (
          auto const& A
        , auto const& B
        , auto const& dAdt
        , auto const& dAdr
        , auto const& dBdr
        , auto const& dAdtr
    ){
        return dAdtr * (1 + A + 5 * B) + dAdt * (dAdr + 5 * dBdr);
    }
        constexpr auto
    d (auto const& A, auto const& B, auto const& sqrtC)
    {
        return 1 + A + 5 * B + sqrtC;
    }
        constexpr auto
    dddt (
          auto const& dAdt
        , auto const& half_dCdt
        , auto const& sqrtC
    ){
        return dAdt + half_dCdt / sqrtC;
    }
        constexpr auto
    dddtt (
          auto const& dAdtt
        , auto const& half_dCdt
        , auto const& half_dCdtt
        , auto const& C
        , auto const& sqrtC
    ){
        return dAdtt + half_dCdtt / sqrtC - half_dCdt * half_dCdt / C / sqrtC;
    }
        constexpr auto
    dddr (
          auto const& dAdr
        , auto const& dBdr
        , auto const& half_dCdr
        , auto const& sqrtC
    ){
        return dAdr + 5 * dBdr + half_dCdr / sqrtC;
    }
        constexpr auto
    dddrr (
          auto const& dAdrr
        , auto const& half_dCdr
        , auto const& half_dCdrr
        , auto const& C
        , auto const& sqrtC
    ){
        return dAdrr + half_dCdrr / sqrtC - half_dCdr * half_dCdr / C / sqrtC
        ;
    }
        constexpr auto
    dddtr (
          auto const& dAdtr
        , auto const& half_dCdt
        , auto const& half_dCdr
        , auto const& half_dCdtr
        , auto const& C
        , auto const& sqrtC
    ){
        return dAdtr + half_dCdtr / sqrtC - half_dCdt * half_dCdr / C / sqrtC;;
    }
        constexpr auto
    e (auto const& molar_density, auto const& temperature)
    {
            const auto
        G = g (molar_density, temperature);
            const auto
        A = a (molar_density, temperature, G);
            const auto
        B = b (molar_density);
            using std::sqrt;
            const auto
        sqrtC = sqrt (c (A, B));
            const auto
        D = d (A, B, sqrtC);
        return D / 4 / (1 - B);
    }
        constexpr auto
    dedt (auto const& molar_density, auto const& temperature)
    {
            const auto
        G = g (molar_density, temperature);
            const auto
        A = a (molar_density, temperature, G);
            const auto
        B = b (molar_density);
            using std::sqrt;
            const auto
        sqrtC = sqrt (c (A, B));
            const auto
        dGdt = dgdt (molar_density, temperature);
            const auto
        dAdt = dadt (molar_density, temperature, G, dGdt);
            const auto
        half_dCdt = half_dcdt (A, B, dAdt);
            const auto
        dDdt = dddt (dAdt, half_dCdt, sqrtC);
        return dDdt / 4 / (1 - B);
    }
        constexpr auto
    dedr (auto const& molar_density, auto const& temperature)
    {
            const auto
        G = g (molar_density, temperature);
            const auto
        A = a (molar_density, temperature, G);
            const auto
        B = b (molar_density);
            using std::sqrt;
            const auto
        sqrtC = sqrt (c (A, B));
            const auto
        D = d (A, B, sqrtC);
            const auto
        dGdr = dgdr (molar_density, temperature);
            const auto
        dAdr = dadr (molar_density, temperature, G, dGdr);
            const auto
        dBdr = dbdr ();
            const auto
        half_dCdr = half_dcdr (A, B, dAdr, dBdr);
            const auto
        dDdr = dddr (dAdr, dBdr, half_dCdr, sqrtC);
        return (dDdr + D * dBdr / (1 - B)) / 4 / (1 - B);
    }
        constexpr auto
    dedtt (auto const& molar_density, auto const& temperature)
    {
            const auto
        G = g (molar_density, temperature);
            const auto
        A = a (molar_density, temperature, G);
            const auto
        B = b (molar_density);
            const auto
        C = c (A, B);
            using std::sqrt;
            const auto
        sqrtC = sqrt (C);
            const auto
        dGdt = dgdt (molar_density, temperature);
            const auto
        dGdtt = dgdtt (molar_density, temperature);
            const auto
        dAdt = dadt (molar_density, temperature, G, dGdt);
            const auto
        dAdtt = dadtt (molar_density, temperature, G, dGdt, dGdtt);
            const auto
        half_dCdt = half_dcdt (A, B, dAdt);
            const auto
        half_dCdtt = half_dcdtt (A, B, dAdt, dAdtt);
            const auto
        dDdtt = dddtt (dAdtt, half_dCdt, half_dCdtt, C, sqrtC);
        return dDdtt / 4 / (1 - B);
    }
        constexpr auto
    dedtr (auto const& molar_density, auto const& temperature)
    {
            const auto
        G = g (molar_density, temperature);
            const auto
        A = a (molar_density, temperature, G);
            const auto
        B = b (molar_density);
            const auto
        C = c (A, B);
            using std::sqrt;
            const auto
        sqrtC = sqrt (C);
            const auto
        dGdt = dgdt (molar_density, temperature);
            const auto
        dGdr = dgdr (molar_density, temperature);
            const auto
        dGdtr = dgdtr (molar_density, temperature);
            const auto
        dAdt = dadt (molar_density, temperature, G, dGdt);
            const auto
        dAdr = dadr (molar_density, temperature, G, dGdr);
            const auto
        dBdr = dbdr ();
            const auto
        dAdtr = dadtr (molar_density, temperature, G, dGdt, dGdr, dGdtr);
            const auto
        half_dCdtr = half_dcdtr (A, B, dAdt, dAdr, dBdr, dAdtr);
            const auto
        half_dCdt = half_dcdt (A, B, dAdt);
            const auto
        half_dCdr = half_dcdr (A, B, dAdr, dBdr);
            const auto
        dDdt = dddt (dAdt, half_dCdt, sqrtC);
            const auto
        dDdtr = dddtr (dAdtr, half_dCdt, half_dCdr, half_dCdtr, C, sqrtC);
        return (dDdtr + dBdr * dDdt / (1 - B)) / 4 / (1 - B);
        /*
        return (
              dBdr * (dAdt + half_dCdt / sqrtC) / (1 - B)
            + dAdtr
            + (half_dCdtr - half_dCdt * half_dCdr / C) / sqrtC
        ) / 4 / (1 - B);
        */
    }
        constexpr auto
    dedrr (auto const& molar_density, auto const& temperature)
    {
            const auto
        G = g (molar_density, temperature);
            const auto
        A = a (molar_density, temperature, G);
            const auto
        B = b (molar_density);
            const auto
        C = c (A, B);
            using std::sqrt;
            const auto
        sqrtC = sqrt (c (A, B));
            const auto
        D = d (A, B, sqrtC);
            const auto
        dGdr = dgdr (molar_density, temperature);
            const auto
        dAdr = dadr (molar_density, temperature, G, dGdr);
            const auto
        dAdrr = dadrr (molar_density, temperature, dgdr, dgdrr);
            const auto
        dBdr = dbdr ();
            const auto
        half_dCdr = half_dcdr (A, B, dAdr, dBdr);
            const auto
        half_dCdrr = half_dcdrr (A, B, dAdr, dAdrr, dBdr);
            const auto
        dDdr = dddr (dAdr, dBdr, half_dCdr, sqrtC);
            const auto
        dDdrr = dddrr (dAdrr, half_dCdr, half_dCdrr, C, sqrtC);
        return (
              dDdrr / 2 
            + dBdr * dDdr / (1 - B)
            - dBdr * dBdr * D / (1 - B) / (1 - B)
        ) / 2 / (1 - B);
    }
} // namespace detail

    using namespace detail;

    constexpr auto
relative_permittivity_dt (auto const& density, auto const& temperature)
{
    return e (density / molar_mass_of_water, temperature);
}

    constexpr auto
d_relative_permittivity_d_p_dt (auto const& density, auto const& temperature)
{
        const auto
    rho = density / molar_mass_of_water;
        using namespace calculisto::iapws::r6;
    return 
          dedr (rho, temperature) 
        * molar_mass_of_water * rho * rho 
        / pressure_dt (density, temperature)
        / isothermal_stress_coefficient_dt (density, temperature)
    ;
}

    constexpr auto
d_relative_permittivity_d_t_dt (auto const& density, auto const& temperature)
{
        const auto
    rho = density / molar_mass_of_water;
        using namespace calculisto::iapws::r6;
    return 
          dedt (rho, temperature)
        - dedr (rho, temperature)
        * molar_mass_of_water * rho * rho
        * relative_pressure_coefficient_dt (density, temperature)
        / isothermal_stress_coefficient_dt (density, temperature)
    ;
}    constexpr auto

d_relative_permittivity_d_tt_dt (auto const& density, auto const& temperature)
{
        const auto
    rho = density / molar_mass_of_water;
        using namespace calculisto::iapws::r6;
    return 
          dedtt (rho, temperature)
        - dedtr (rho, temperature)
        * molar_mass_of_water * rho * rho
        * relative_pressure_coefficient_dt (density, temperature)
        / isothermal_stress_coefficient_dt (density, temperature)
    ;
}
    namespace
born
{
    constexpr auto
z (auto const& density, auto const& temperature)
{
    return -1 / e (density / molar_mass_of_water, temperature);
}
    constexpr auto
q (auto const& density, auto const& temperature)
{
        const auto
    rho = density / molar_mass_of_water;
        const auto
    E = e (rho, temperature);
        using namespace calculisto::iapws::r6;
    return 
          dedr (rho, temperature)
        * molar_mass_of_water * rho * rho
        / pressure_dt (density, temperature)
        / isothermal_stress_coefficient_dt (density, temperature)
        / E / E
    ;
}
    constexpr auto
y (auto const& density, auto const& temperature)
{
        const auto
    rho = density / molar_mass_of_water;
        const auto
    E = e (rho, temperature);
        using namespace calculisto::iapws::r6;
    return (
          dedt (rho, temperature)
        - dedr (rho, temperature)
        * molar_mass_of_water * rho * rho
        * relative_pressure_coefficient_dt (density, temperature)
        / isothermal_stress_coefficient_dt (density, temperature)
    ) / E / E;
}
    constexpr auto
x (auto const& density, auto const& temperature)
{
        const auto
    rho = density / molar_mass_of_water;
        const auto
    E = e (rho, temperature);
        const auto
    Y = y (rho, temperature);
        using namespace calculisto::iapws::r6;
    return (
          dedtt (rho, temperature)
        - dedtr (rho, temperature)
        * molar_mass_of_water * rho * rho
        * relative_pressure_coefficient_dt (density, temperature)
        / isothermal_stress_coefficient_dt (density, temperature)
    ) / E / E - 2 * E * Y * Y;
}

} // namespace born
} // namespace r8_09_1997
} // namespace calculisto::iapws::r8
