#pragma once
#include <cmath>
#include <iostream>

class EncapsulatedPoint
{
private:
    double x;
    double y;

    EncapsulatedPoint(double x, double y) : x(x), y(y) {}

public:
    static EncapsulatedPoint from_cartesian(double x, double y) { return {x, y}; }
    static EncapsulatedPoint from_polar(double r, double theta)
    {
        return {r * std::cos(theta), r * std::sin(theta)};
    }

    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_r() const { return std::sqrt(x * x + y * y); }
    double get_theta() const { return x == 0.0 ? std::atan(1.0) : std::atan(y / x); }

    EncapsulatedPoint operator+(EncapsulatedPoint rhs) const
    {
        return {x + rhs.get_x(), y + rhs.get_y()};
    }
};

inline bool operator==(EncapsulatedPoint lhs, EncapsulatedPoint rhs)
{
    return lhs.get_x() == rhs.get_x() && lhs.get_y() == rhs.get_y();
}

inline bool operator!=(EncapsulatedPoint lhs, EncapsulatedPoint rhs)
{
    return !(lhs == rhs);
}

inline std::ostream& operator<<(std::ostream& s, const EncapsulatedPoint& point)
{
    s << "EncapsulatedPoint(" << point.get_x() << ", " << point.get_y() << ")";
    return s;
}
