#pragma once
#include <iostream>

struct RawPoint {
    double x;
    double y;
};

inline RawPoint point_from_polar(double r, double theta)
{
    return {r * cos(theta), r * sin(theta)};
}

inline double point_r(RawPoint point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

inline double point_theta(RawPoint point)
{
    return (point.x == 0.0) ? atan(1.0) : atan(point.y / point.x);
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
