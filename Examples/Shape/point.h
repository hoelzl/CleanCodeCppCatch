#pragma once

#include <iostream>

class Point
{
public:
    Point(double x = 0.0, double y = 0.0) : x{x}, y{y} {}

    [[nodiscard]] double get_x() const { return x; }
    [[nodiscard]] double get_y() const { return y; }

    Point operator+(Point rhs) const { return {x + rhs.get_x(), y + rhs.get_y()}; }

private:
    double x{0.0};
    double y{0.0};
};

inline std::ostream& operator<<(std::ostream& s, const Point& point)
{
    s << "Point(" << point.get_x() << ", " << point.get_y() << ")";
    return s;
}
