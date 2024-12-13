#include <doctest/doctest.h>
    using doctest::Approx;
#include "test.hpp"
#include "../include/calculisto/iapws/r6.hpp"
#include "../include/calculisto/iapws/r6_inverse.hpp"
    using namespace calculisto::iapws;
    using namespace calculisto::iapws::r6;
#include "../include/calculisto/iapws/detail/data_for_the_tests.hpp"

TEST_CASE("r6.hpp")
{
SUBCASE("base functions")
{
    CHECK(detail::phi_0    (838.025 / 322., 647.096 / 500.) == Approx {  0.204797734e1 }.epsilon (1e-8));
    CHECK(detail::phi_r    (838.025 / 322., 647.096 / 500.) == Approx { -0.342693206e1 }.epsilon (1e-8));
    CHECK(detail::phi_0_d  (838.025 / 322., 647.096 / 500.) == Approx {  0.384236747   }.epsilon (1e-8));
    CHECK(detail::phi_r_d  (838.025 / 322., 647.096 / 500.) == Approx { -0.364366650   }.epsilon (1e-8));
    CHECK(detail::phi_0_dd (838.025 / 322., 647.096 / 500.) == Approx { -0.147637878   }.epsilon (1e-8));
    CHECK(detail::phi_r_dd (838.025 / 322., 647.096 / 500.) == Approx {  0.856063701   }.epsilon (1e-8));
    CHECK(detail::phi_0_t  (838.025 / 322., 647.096 / 500.) == Approx {  0.904611106e1 }.epsilon (1e-8));
    CHECK(detail::phi_r_t  (838.025 / 322., 647.096 / 500.) == Approx { -0.581403435e1 }.epsilon (1e-8));
    CHECK(detail::phi_0_tt (838.025 / 322., 647.096 / 500.) == Approx { -0.193249185e1 }.epsilon (1e-8));
    CHECK(detail::phi_r_tt (838.025 / 322., 647.096 / 500.) == Approx { -0.223440737e1 }.epsilon (1e-8));
    //CHECK(detail::phi_0_dt (838.025 / 322., 647.096 / 500.) == Approx {  0.            }.epsilon (1e-8));
    CHECK(detail::phi_r_dt (838.025 / 322., 647.096 / 500.) == Approx { -0.112176915e1 }.epsilon (1e-8));
    CHECK(detail::phi_0    (358.000 / 322., 647.096 / 647.) == Approx { -0.156319605e1 }.epsilon (1e-8));
    CHECK(detail::phi_r    (358.000 / 322., 647.096 / 647.) == Approx { -0.121202657e1 }.epsilon (1e-8));
    CHECK(detail::phi_0_d  (358.000 / 322., 647.096 / 647.) == Approx {  0.899441341   }.epsilon (1e-8));
    CHECK(detail::phi_r_d  (358.000 / 322., 647.096 / 647.) == Approx { -0.714012024   }.epsilon (1e-8));
    CHECK(detail::phi_0_dd (358.000 / 322., 647.096 / 647.) == Approx { -0.808994726   }.epsilon (1e-8));
    CHECK(detail::phi_r_dd (358.000 / 322., 647.096 / 647.) == Approx {  0.475730696   }.epsilon (1e-8));
    CHECK(detail::phi_0_t  (358.000 / 322., 647.096 / 647.) == Approx {  0.980343918e1 }.epsilon (1e-8));
    CHECK(detail::phi_r_t  (358.000 / 322., 647.096 / 647.) == Approx { -0.321722501e1 }.epsilon (1e-8));
    CHECK(detail::phi_0_tt (358.000 / 322., 647.096 / 647.) == Approx { -0.343316334e1 }.epsilon (1e-8));
    CHECK(detail::phi_r_tt (358.000 / 322., 647.096 / 647.) == Approx { -0.996029507e1 }.epsilon (1e-8));
    //CHECK(detail::phi_0_dt (358.000 / 322., 647.096 / 647.) == Approx {  0.            }.epsilon (1e-8));
    CHECK(detail::phi_r_dt (358.000 / 322., 647.096 / 647.) == Approx { -0.133214720e1 }.epsilon (1e-8));

} // SUBCASE("base functions")
/*
SUBCASE("phi_r_ddd")
{
        auto const
    d0 = 1.;
        auto const
    d1 = 1.2;
        auto const
    n = 1001;
        auto const
    dd = (d1 - d0) / (n - 1);
        auto const
    t = 1.2;
        auto
    a_psi = array_t { 0., 0. };
        auto
    a_Delta = array_t { 0., 0. };
        auto
    a_Delta_b = array_t { 0., 0. };
        auto
    a_s1 = 0.;
        auto
    a_s2 = 0.;
        auto
    a_s3 = 0.;
        auto
    a_s4 = 0.;
        auto
    a_phi_r_ddd = 0.;
    for (auto i = 0; i < n; ++i)
    {
            auto const
        d = d0 + i * dd;
        a_psi       += Psi_ddd   (d, t) * dd;
        a_Delta     += Delta_ddd (d, t) * dd;
        a_Delta_b   += Delta_b_ddd (d, t) * dd;
        a_s1        += s1_ddd (d, t) * dd;
        a_s2        += s2_ddd (d, t) * dd;
        a_s3        += s3_ddd (d, t) * dd;
        a_s4        += s4_ddd (d, t) * dd;
        a_phi_r_ddd += phi_r_ddd (d, t) * dd;
    }
        auto const
    b_psi = Psi_dd (d1, t) - Psi_dd (d0, t);
    MESSAGE("psi[0]: ", a_psi[0], " ", b_psi[0]);
    MESSAGE("psi[1]: ", a_psi[1], " ", b_psi[1]);
        auto const
    b_Delta = Delta_dd (d1, t) - Delta_dd (d0, t);
    MESSAGE("Delta[0]: ", a_Delta[0], " ", b_Delta[0]);
    MESSAGE("Delta[1]: ", a_Delta[1], " ", b_Delta[1]);
        auto const
    b_Delta_b = Delta_b_dd (d1, t) - Delta_b_dd (d0, t);
    MESSAGE("Delta_b[0]: ", a_Delta_b[0], " ", b_Delta_b[0]);
    MESSAGE("Delta_b[1]: ", a_Delta_b[1], " ", b_Delta_b[1]);
        auto const
    b_s1 = s1_dd (d1, t) - s1_dd (d0, t);
    MESSAGE("s1: ", a_s1, " ", b_s1);
        auto const
    b_s2 = s2_dd (d1, t) - s2_dd (d0, t);
    MESSAGE("s2: ", a_s2, " ", b_s2);
        auto const
    b_s3 = s3_dd (d1, t) - s3_dd (d0, t);
    MESSAGE("s3: ", a_s3, " ", b_s3);
        auto const
    b_s4 = s4_dd (d1, t) - s4_dd (d0, t);
    MESSAGE("s4: ", a_s4, " ", b_s4);
        auto const
    b_phi_r_ddd = phi_r_dd (d1, t) - phi_r_dd (d0, t);
    MESSAGE("phi: ", a_phi_r_ddd, " ", b_phi_r_ddd);
} // SUBCASE("phi_r_ddd")
*/
SUBCASE("main API")
{
    for(const auto& e: calculisto::iapws::r6::detail::table_7)
    {
        CHECK(pressure_dt (e.D, e.T) == Approx { e.P }.epsilon (1e-8));
        CHECK(massic_isochoric_heat_capacity_dt (e.D, e.T) == Approx { e.Cv }.epsilon (1e-8));
        CHECK(speed_of_sound_dt (e.D, e.T) == Approx { e.W }.epsilon (1e-8));
        CHECK(massic_entropy_dt (e.D, e.T) == Approx { e.S }.epsilon (1e-8));
    }
} // SUBCASE("main API")
SUBCASE("mixed arguments")
{
    CHECK(pressure_dt (1e3, 300.0l));
}
SUBCASE("Cp, alpha_v, kappa_T")
{
    for (auto iT = 0; iT < ssize (r7::detail::T); ++iT)
    {
            const auto
        T = r7::detail::T[iT] + 273.15;
        for (auto iP = 0; iP < ssize (r7::detail::P); ++iP)
        {
                const auto
            P = r7::detail::P[iP] * 1e5;
                const auto
            D = r6_inverse::density_pt (P, T);
                const auto
            alpha_v = r7::detail::table_9[iT][iP] * 1e-6;
            INFO("T= ", T, ", P= ", P, ", D= ", D, ", a_v = ", alpha_v);
            CHECK(isobaric_cubic_expansion_coefficient_dt (D, T) == Approx { alpha_v }.scale (fabs (alpha_v )).epsilon (1e-2));
        }
    }
}
#if 0
SUBCASE("expansion, compressibility, etc.")
{
        using namespace calculisto::iapws::r7::detail;
    for (auto it = 1u; it != T.size (); ++it)
    {
            auto const
        t = T.at (it) + 273.15;
        for (auto ip = 0u; ip != P.size (); ++ip)
        {
                auto const
            p = P.at (ip) * 1e5;
                auto const
            A = table_9.at (it).at (ip) * 1e-6;
                auto const
            B = table_10.at (it).at (ip) * 1e-9;
                auto const
            C = table_19.at (it).at (ip) * 1e-3;
                auto const
            D = table_20.at (it).at (ip);
                auto const
            AA = r7::isobaric_cubic_expansion_coefficient_pt (p, t);
                auto const
            BB = r7::isothermal_compressibility_pt           (p, t);
                auto const
            CC = r7::relative_pressure_coefficient_pt        (p, t);
                auto const
            DD = r7::isothermal_stress_coefficient_pt        (p, t);
                auto const
            d7 = r7::density_pt (p, t);
                auto const
            [ d, i ] = r6_inverse::density_pt (p, t, 1e-4, info::convergence);
            if (i.converged)
            {
                {
                    INFO ("P = ", p * 1e-5, ", T = ", t - 273.15, ", rho_0 = ", d7, ", rho = ", d, ", r7: ", AA);
                    //CHECK(isobaric_cubic_expansion_coefficient_dt (d, t) == Approx { A }.scale (fabs (A)).epsilon (1e-2));
                }{
                    INFO ("P = ", p * 1e-5, ", T = ", t - 273.15, ", rho_0 = ", d7, ", rho = ", d, ", r7: ", BB);
                    //CHECK(isothermal_compressibility_dt           (d, t) == Approx { B }.scale (B).epsilon (1e-2));
                }{
                    INFO ("P = ", p * 1e-5, ", T = ", t - 273.15, ", rho_0 = ", d7, ", rho = ", d, ", r7: ", CC);
                    CHECK(relative_pressure_coefficient_dt        (d, t) == Approx { C }.scale (fabs (C)).epsilon (1e-2));
                }{
                    INFO ("P = ", p * 1e-5, ", T = ", t - 273.15, ", rho_0 = ", d7, ", rho = ", d, ", r7: ", DD);
                    CHECK(isothermal_stress_coefficient_dt        (d, t) == Approx { D }.scale (fabs (D)).epsilon (1e-2));
                }
            }
            else
            {
                MESSAGE("Failed with ""P = ", p * 1e-5, ", T = ", t - 273.15, ", rho_0 = ", d7);
                /*
                for (auto&& [ v, f, df ]: i.convergence)
                {
                    MESSAGE("  ", v, ", ", f, ", ", df);
                }
                */
            }
        }
    }
}
#endif
} // TEST_CASE("r6.hpp")
