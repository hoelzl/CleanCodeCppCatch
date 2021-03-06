#pragma once
#include <iostream>

class AbstractPoint
{
private:
    double x;
    double y;

    AbstractPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

public:
    static AbstractPoint from_cartesian(double x, double y)
    {
        return {x, y};
    }
    static AbstractPoint from_polar(double r, double theta)
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

    AbstractPoint operator+(AbstractPoint rhs)
    {
        return {x + rhs.get_x(), y + rhs.get_y()};
    }

    bool operator==(AbstractPoint rhs)
    {
        return get_x() == rhs.get_x() && get_y() == rhs.get_y();
    }

    bool operator!=(AbstractPoint rhs)
    {
        return !(*this == rhs);
    }
};

inline std::ostream& operator<<(std::ostream& s, const AbstractPoint& point) {
    s << "AbstractPoint(" << point.get_x() << ", " << point.get_y() << ")";
    return s;
}
