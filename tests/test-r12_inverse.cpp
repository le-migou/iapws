#include <doctest/doctest.h>
    using doctest::Approx;
#include "../include/calculisto/iapws/r12_inverse.hpp"
    using namespace calculisto::iapws::r12_inverse;
    using namespace calculisto::iapws::r6;

TEST_CASE("r12_inverse.hpp")
{
    CHECK(viscosity_tp ( 298.15, pressure_td ( 298.15,  998.)) == Approx {  889.735100e-6 }.scale (1e-3).epsilon (1e-6));
    CHECK(viscosity_tp ( 298.15, pressure_td ( 298.15, 1200.)) == Approx { 1437.649467e-6 }.scale (1e-2).epsilon (1e-6));
    CHECK(viscosity_tp ( 373.15, pressure_td ( 373.15, 1000.)) == Approx {  307.883622e-6 }.scale (1e-3).epsilon (1e-6));
    CHECK(viscosity_tp ( 433.15, pressure_td ( 433.15,    1.)) == Approx {   14.538324e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp ( 433.15, pressure_td ( 433.15, 1000.)) == Approx {  217.685358e-6 }.scale (1e-3).epsilon (1e-6));
    CHECK(viscosity_tp ( 873.15, pressure_td ( 873.15,    1.)) == Approx {   32.619287e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp ( 873.15, pressure_td ( 873.15,  100.)) == Approx {   35.802262e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp ( 873.15, pressure_td ( 873.15,  600.)) == Approx {   77.430195e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp (1173.15, pressure_td (1173.15,    1.)) == Approx {   44.217245e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp (1173.15, pressure_td (1173.15,  100.)) == Approx {   47.640433e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp (1173.15, pressure_td (1173.15,  400.)) == Approx {   64.154608e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_tp ( 647.35, pressure_td ( 647.35,  122.)) == Approx { 25.520677e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_tp ( 647.35, pressure_td ( 647.35,  222.)) == Approx { 31.337589e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_tp ( 647.35, pressure_td ( 647.35,  272.)) == Approx { 36.228143e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_tp ( 647.35, pressure_td ( 647.35,  322.)) == Approx { 42.961579e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_tp ( 647.35, pressure_td ( 647.35,  372.)) == Approx { 45.688204e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_tp ( 647.35, pressure_td ( 647.35,  422.)) == Approx { 49.436256e-6 }.scale (1e-5).epsilon (1e-8));

    CHECK(viscosity_pt (pressure_dt ( 998.,  298.15),  298.15) == Approx {  889.735100e-6 }.scale (1e-3).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt (1200.,  298.15),  298.15) == Approx { 1437.649467e-6 }.scale (1e-2).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt (1000.,  373.15),  373.15) == Approx {  307.883622e-6 }.scale (1e-3).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt (   1.,  433.15),  433.15) == Approx {   14.538324e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt (1000.,  433.15),  433.15) == Approx {  217.685358e-6 }.scale (1e-3).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt (   1.,  873.15),  873.15) == Approx {   32.619287e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt ( 100.,  873.15),  873.15) == Approx {   35.802262e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt ( 600.,  873.15),  873.15) == Approx {   77.430195e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt (   1., 1173.15), 1173.15) == Approx {   44.217245e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt ( 100., 1173.15), 1173.15) == Approx {   47.640433e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt ( 400., 1173.15), 1173.15) == Approx {   64.154608e-6 }.scale (1e-4).epsilon (1e-6));
    CHECK(viscosity_pt (pressure_dt ( 122.,  647.35),  647.35) == Approx { 25.520677e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_pt (pressure_dt ( 222.,  647.35),  647.35) == Approx { 31.337589e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_pt (pressure_dt ( 272.,  647.35),  647.35) == Approx { 36.228143e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_pt (pressure_dt ( 322.,  647.35),  647.35) == Approx { 42.961579e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_pt (pressure_dt ( 372.,  647.35),  647.35) == Approx { 45.688204e-6 }.scale (1e-5).epsilon (1e-8));
    CHECK(viscosity_pt (pressure_dt ( 422.,  647.35),  647.35) == Approx { 49.436256e-6 }.scale (1e-5).epsilon (1e-8));
}
