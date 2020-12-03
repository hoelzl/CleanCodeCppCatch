#include "abstract_point.h"
#include "catch.hpp"

const double PI_DIV_4 = atan(1.0);
const double PI_DIV_2 = PI_DIV_4 * 2.0;

TEST_CASE("tests for abstract points")
{
    SECTION("points are created correctly from cartesian coordinates")
    {
        AbstractPoint p{AbstractPoint::from_cartesian(0.0, 2.0)};
        REQUIRE(p.get_x() == Approx(0.0));
        REQUIRE(p.get_y() == Approx(2.0));
    }

    SECTION("points are created correctly from polar coordinates")
    {
        SECTION("when they are on the x axis")
        {
            AbstractPoint p{AbstractPoint::from_polar(2.0, 0.0)};
            REQUIRE(p.get_x() == Approx(2.0));
            REQUIRE(p.get_y() == Approx(0.0));
        }

        AbstractPoint p2{AbstractPoint::from_polar(1.0, PI_DIV_2)};
        REQUIRE(p2.get_x() == Approx(0.0));
        REQUIRE(p2.get_y() == Approx(1.0));

        AbstractPoint p3{AbstractPoint::from_polar(1.0, PI_DIV_4)};
        REQUIRE(p3.get_x() == Approx(sqrt(2.0) / 2.0));
        REQUIRE(p3.get_y() == Approx(sqrt(2.0) / 2.0));
    }

    SECTION("radius and angle is computed correctly")
    {
        AbstractPoint p{AbstractPoint::from_cartesian(0.0, 2.0)};
        REQUIRE(p.get_r() == Approx(2.0));
        REQUIRE(p.get_theta() == Approx(PI_DIV_4));

        AbstractPoint p2{AbstractPoint::from_cartesian(1.0, 0.0)};
        REQUIRE(p2.get_r() == Approx(1.0));
        REQUIRE(p2.get_theta() == Approx(0.0));
    }

    SECTION("Equality compares both coordinates")
    {
        AbstractPoint p1{AbstractPoint::from_cartesian(1.0, 2.0)};
        AbstractPoint p2{AbstractPoint::from_cartesian(1.0, 2.0)};
        AbstractPoint p3{AbstractPoint::from_cartesian(0.0, 2.0)};
        AbstractPoint p4{AbstractPoint::from_cartesian(1.0, 4.0)};

        REQUIRE(p1 == p1);
        REQUIRE(p1 == p2);
        REQUIRE(p1 != p3);
        REQUIRE(p1 != p4);
    }

    SECTION("Addition of points works")
    {
        AbstractPoint p1{AbstractPoint::from_cartesian(1.0, 2.0)};
        AbstractPoint p2{AbstractPoint::from_cartesian(4.0, 6.0)};
        REQUIRE(p1 + p2 == AbstractPoint::from_cartesian(5.0, 8.0));
    }
}
