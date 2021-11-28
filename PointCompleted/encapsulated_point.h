#pragma once
#include <iostream>

class EncapsulatedPoint
{
private:
    double x;
    double y;

    EncapsulatedPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

public:
    static EncapsulatedPoint from_cartesian(double x, double y)
    {
        return {x, y};
    }
    static EncapsulatedPoint from_polar(double r, double theta)
    {
        return {r * cos(theta), r * sin(theta)};
    }

    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }
    double get_r() const
    {
        return sqrt(x * x + y * y);
    }
    double get_theta() const
    {
        return x == 0.0 ? atan(1.0) : atan(y / x);
    }

    EncapsulatedPoint operator+(EncapsulatedPoint rhs)
    {
        return {x + rhs.get_x(), y + rhs.get_y()};
    }

    bool operator==(EncapsulatedPoint rhs)
    {
        return get_x() == rhs.get_x() && get_y() == rhs.get_y();
    }

    bool operator!=(EncapsulatedPoint rhs)
    {
        return !(*this == rhs);
    }
};

inline std::ostream& operator<<(std::ostream& s, const EncapsulatedPoint& point)
{
    s << "EncapsulatedPoint(" << point.get_x() << ", " << point.get_y() << ")";
    return s;
}
