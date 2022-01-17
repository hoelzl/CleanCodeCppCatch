#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "encapsulated_point.h"

using Catch::Approx;

const double PI_DIV_4 = atan(1.0);
const double PI_DIV_2 = PI_DIV_4 * 2.0;

TEST_CASE("tests for abstract points")
{
    SECTION("points are created correctly from cartesian coordinates")
    {
        EncapsulatedPoint p{EncapsulatedPoint::from_cartesian(0.0, 2.0)};
        REQUIRE(p.get_x() == Approx(0.0));
        REQUIRE(p.get_y() == Approx(2.0));
    }

    SECTION("points are created correctly from polar coordinates")
    {
        SECTION("when they are on the x axis")
        {
            EncapsulatedPoint p{EncapsulatedPoint::from_polar(2.0, 0.0)};
            REQUIRE(p.get_x() == Approx(2.0));
            REQUIRE(p.get_y() == Approx(0.0));
        }

        EncapsulatedPoint p2{EncapsulatedPoint::from_polar(1.0, PI_DIV_2)};
        //REQUIRE(p2.get_x() == Approx(0.0));
        //double epsilon{std::numeric_limits<double>::epsilon() * 1000.0};
        //REQUIRE(p2.get_x() == Approx(0.0).epsilon(epsilon));
        REQUIRE(p2.get_x() == Approx(0.0).scale(1e-10));
        REQUIRE(p2.get_x() == Approx(0.0).margin(1e-15));
        REQUIRE(p2.get_y() == Approx(1.0));

        EncapsulatedPoint p3{EncapsulatedPoint::from_polar(1.0, PI_DIV_4)};
        REQUIRE(p3.get_x() == Approx(sqrt(2.0) / 2.0));
        REQUIRE(p3.get_y() == Approx(sqrt(2.0) / 2.0));
    }

    SECTION("radius and angle is computed correctly")
    {
        EncapsulatedPoint p{EncapsulatedPoint::from_cartesian(0.0, 2.0)};
        REQUIRE(p.get_r() == Approx(2.0));
        REQUIRE(p.get_theta() == Approx(PI_DIV_4));

        EncapsulatedPoint p2{EncapsulatedPoint::from_cartesian(1.0, 0.0)};
        REQUIRE(p2.get_r() == Approx(1.0));
        REQUIRE(p2.get_theta() == Approx(0.0));
    }

    SECTION("Equality compares both coordinates")
    {
        EncapsulatedPoint p1{EncapsulatedPoint::from_cartesian(1.0, 2.0)};
        EncapsulatedPoint p2{EncapsulatedPoint::from_cartesian(1.0, 2.0)};
        EncapsulatedPoint p3{EncapsulatedPoint::from_cartesian(0.0, 2.0)};
        EncapsulatedPoint p4{EncapsulatedPoint::from_cartesian(1.0, 4.0)};

        REQUIRE(p1 == p1);
        REQUIRE(p1 == p2);
        REQUIRE(p1 != p3);
        REQUIRE(p1 != p4);
    }

    SECTION("Addition of points works")
    {
        EncapsulatedPoint p1{EncapsulatedPoint::from_cartesian(1.0, 2.0)};
        EncapsulatedPoint p2{EncapsulatedPoint::from_cartesian(4.0, 6.0)};
        REQUIRE(p1 + p2 == EncapsulatedPoint::from_cartesian(5.0, 8.0));
    }
}
