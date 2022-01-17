#pragma once
#include <iostream>
#include <cmath>

struct RawPoint {
    double x;
    double y;
};

inline RawPoint point_from_polar(double r, double theta)
{
    return {r * std::cos(theta), r * std::sin(theta)};
}

inline double point_r(RawPoint point)
{
    return std::sqrt(point.x * point.x + point.y * point.y);
}

inline double point_theta(RawPoint point)
{
    return (point.x == 0.0) ? std::atan(1.0) : std::atan(point.y / point.x);
}

inline RawPoint operator+(RawPoint lhs, RawPoint rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

inline std::ostream& operator<<(std::ostream& s, const RawPoint& point)
{
    s << "RawPoint(" << point.x << ", " << point.y << ")";
    return s;
}
