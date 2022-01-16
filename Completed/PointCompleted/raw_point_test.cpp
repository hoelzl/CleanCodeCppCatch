#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "raw_point.h"

using Catch::Approx;

const double PI_DIV_4 = atan(1.0);
const double PI_DIV_2 = PI_DIV_4 * 2.0;

TEST_CASE("tests for concrete points")
{
    SECTION("points are created correctly from cartesian coordinates")
    {
        RawPoint p{0.0, 2.0};
        REQUIRE(p.x == Approx(0.0));
        REQUIRE(p.y == Approx(2.0));
    }

    SECTION("points are created correctly from polar coordinates")
    {
        RawPoint p{point_from_polar(2.0, 0.0)};
        REQUIRE(p.x == Approx(2.0));
        REQUIRE(p.y == Approx(0.0));

        RawPoint p2{point_from_polar(1.0, PI_DIV_2)};
        // REQUIRE(p2.x == Approx(0.0));
        REQUIRE(p2.x <= 0.00001);
        REQUIRE(p2.x >= -0.00001);
        REQUIRE(p2.y == Approx(1.0));

        RawPoint p3{point_from_polar(1.0, PI_DIV_4)};
        REQUIRE(p3.x == Approx(sqrt(2.0) / 2.0));
        REQUIRE(p3.y == Approx(sqrt(2.0) / 2.0));
    }

    SECTION("radius and angle is computed correctly")
    {
        RawPoint p{0.0, 2.0};
        REQUIRE(point_r(p) == Approx(2.0));
        REQUIRE(point_theta(p) == Approx(PI_DIV_4));

        RawPoint p2{1.0, 0.0};
        REQUIRE(point_r(p2) == Approx(1.0));
        REQUIRE(point_theta(p2) == Approx(0.0));
    }
}