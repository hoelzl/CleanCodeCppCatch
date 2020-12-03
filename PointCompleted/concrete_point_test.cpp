#include "catch.hpp"
#include "concrete_point.h"
const double PI_DIV_4 = atan(1.0);
const double PI_DIV_2 = PI_DIV_4 * 2.0;

TEST_CASE("tests for concrete points")
{
    SECTION("points are created correctly from cartesian coordinates")
    {
        ConcretePoint p{0.0, 2.0};
        REQUIRE(p.x == Approx(0.0));
        REQUIRE(p.y == Approx(2.0));
    }

    SECTION("points are created correctly from polar coordinates")
    {
        ConcretePoint p{point_from_polar(2.0, 0.0)};
        REQUIRE(p.x == Approx(2.0));
        REQUIRE(p.y == Approx(0.0));

        ConcretePoint p2{point_from_polar(1.0, PI_DIV_2)};
        REQUIRE(p2.x == Approx(0.0));
        REQUIRE(p2.y == Approx(1.0));

        ConcretePoint p3{point_from_polar(1.0, PI_DIV_4)};
        REQUIRE(p3.x == Approx(sqrt(2.0) / 2.0));
        REQUIRE(p3.y == Approx(sqrt(2.0) / 2.0));
    }

    SECTION("radius and angle is computed correctly")
    {
        ConcretePoint p{0.0, 2.0};
        REQUIRE(point_r(p) == Approx(2.0));
        REQUIRE(point_theta(p) == Approx(PI_DIV_4));

        ConcretePoint p2{1.0, 0.0};
        REQUIRE(point_r(p2) == Approx(1.0));
        REQUIRE(point_theta(p2) == Approx(0.0));
    }
}