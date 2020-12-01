#pragma once

#include <utility>
#include <iostream>

class Point {
private:
    double x { 0.0 };
    double y { 0.0 };

public:
    Point(double x = 0.0, double y = 0.0)
    {
        this->x = x;
        this->y = y;
    }

    double get_x() const { return x; }
    double get_y() const { return y; }

    Point operator+(Point rhs) {
        return { x + rhs.get_x(), y + rhs.get_y() };
    }
};

inline std::ostream& operator<<(std::ostream& s, const Point& point) {
    s << "Point(" << point.get_x() << ", " << point.get_y() << ")";
    return s;
}
