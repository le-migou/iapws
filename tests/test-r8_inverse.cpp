#include <doctest/doctest.h>
    using doctest::Approx;
#include "../include/calculisto/iapws/r8_inverse.hpp"
    using namespace calculisto::iapws::r8_inverse;
    using namespace calculisto::iapws::r6;

TEST_CASE("r8_inverse.hpp")
{

    CHECK (relative_permittivity_pt (   0.101325e6, 240.) == Approx { 104.34982 }.scale (1e2).epsilon (1e-7));
    CHECK (relative_permittivity_pt (   0.101325e6, 300.) == Approx {  77.74735 }.scale (1e1).epsilon (1e-7));
    CHECK (relative_permittivity_pt (  10e6       , 300.) == Approx {  78.11269 }.scale (1e1).epsilon (1e-7));
    CHECK (relative_permittivity_pt (1000e6       , 300.) == Approx { 103.69632 }.scale (1e2).epsilon (1e-7));
    CHECK (relative_permittivity_pt (  10e6       , 650.) == Approx {   1.26715 }.scale (1e0).epsilon (1e-5));
    CHECK (relative_permittivity_pt ( 100e6       , 650.) == Approx {  17.71733 }.scale (1e1).epsilon (1e-6));
    CHECK (relative_permittivity_pt ( 500e6       , 650.) == Approx {  26.62132 }.scale (1e1).epsilon (1e-7));
    CHECK (relative_permittivity_pt (  10e6       , 870.) == Approx {   1.12721 }.scale (1e0).epsilon (1e-6));
    CHECK (relative_permittivity_pt ( 100e6       , 870.) == Approx {   4.98281 }.scale (1e0).epsilon (1e-6));
    CHECK (relative_permittivity_pt ( 500e6       , 870.) == Approx {  15.09746 }.scale (1e1).epsilon (1e-7));

    CHECK (relative_permittivity_tp (240.,    0.101325e6) == Approx { 104.34982 }.scale (1e2).epsilon (1e-7));
    CHECK (relative_permittivity_tp (300.,    0.101325e6) == Approx {  77.74735 }.scale (1e1).epsilon (1e-7));
    CHECK (relative_permittivity_tp (300.,   10e6       ) == Approx {  78.11269 }.scale (1e1).epsilon (1e-7));
    CHECK (relative_permittivity_tp (300., 1000e6       ) == Approx { 103.69632 }.scale (1e2).epsilon (1e-7));
    CHECK (relative_permittivity_tp (650.,   10e6       ) == Approx {   1.26715 }.scale (1e0).epsilon (1e-5));
    CHECK (relative_permittivity_tp (650.,  100e6       ) == Approx {  17.71733 }.scale (1e1).epsilon (1e-6));
    CHECK (relative_permittivity_tp (650.,  500e6       ) == Approx {  26.62132 }.scale (1e1).epsilon (1e-7));
    CHECK (relative_permittivity_tp (870.,   10e6       ) == Approx {   1.12721 }.scale (1e0).epsilon (1e-6));
    CHECK (relative_permittivity_tp (870.,  100e6       ) == Approx {   4.98281 }.scale (1e0).epsilon (1e-6));
    CHECK (relative_permittivity_tp (870.,  500e6       ) == Approx {  15.09746 }.scale (1e1).epsilon (1e-7));
}
