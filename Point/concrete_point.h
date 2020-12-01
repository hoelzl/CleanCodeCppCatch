#pragma once
#include <iostream>

struct ConcretePoint {
    double x;
    double y;
};

double point_r(ConcretePoint point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

double point_theta(ConcretePoint point)
{
    return (point.x == 0.0) ? 0.0 : atan(point.y / point.x);
}

inline ConcretePoint add(ConcretePoint lhs, ConcretePoint rhs)
{
    return { lhs.x + rhs.x, lhs.y + rhs.y };
}

inline void print(ConcretePoint p)
{
    std::cout << "ConcretePoint(" << p.x << ", " << p.y << ")" << std::endl;
}
