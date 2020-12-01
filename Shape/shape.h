#pragma once

#include "point.h"
#include <array>
#include <iostream>

class AbstractShape {
public:
    virtual double compute_area() const = 0;
    virtual void move(double x, double y) = 0;
};

std::ostream& operator<<(std::ostream& s, const AbstractShape& square);

class AbstractSquare : public AbstractShape {
    friend std::ostream& operator<<(std::ostream& s, const AbstractSquare& square);

    Point bottom_left_corner {};
    double side { 1.0 };

public:
    AbstractSquare(Point bottom_left_corner, double side);

    double compute_area() const override;
    void move(double x, double y) override;
};

std::ostream& operator<<(std::ostream& s, const AbstractSquare& square);

class AbstractRectangle : public AbstractShape {
    friend std::ostream& operator<<(std::ostream& s, const AbstractRectangle& rect);
    Point bottom_left_corner {};
    double width { 1.0 };
    double height { 1.0 };

public:
    AbstractRectangle(Point bottom_left_corner, double width, double height);

    double compute_area() const override;
    void move(double x, double y) override;
};

std::ostream& operator<<(std::ostream& s, const AbstractRectangle& rect);

class AbstractCircle : public AbstractShape {
    friend std::ostream& operator<<(std::ostream& s, const AbstractCircle& circle);
    Point center {};
    double radius { 1.0 };

public:
    AbstractCircle(Point center, double radius);
    double compute_area() const override;
    void move(double x, double y) override;
};

std::ostream& operator<<(std::ostream& s, const AbstractCircle& circle);

enum class ShapeType {
    Square,
    Rectangle,
    Circle
};

struct ConcreteShape {
    ConcreteShape(ShapeType shape_type, Point point, double data1 = 0.0, double data2 = 0.0)
        : shape_type { shape_type }
        , point { point }
        , data1 { data1 }
        , data2 { data2 }
    {
    }

    Point point;
    double data1;
    double data2;

    ShapeType get_type() const
    {
        return shape_type;
    }

private:
    ShapeType shape_type;
};

namespace ConcreteSquare {

using type = ConcreteShape;

ConcreteSquare::type make(Point bottom_left_corner, double side);
Point get_bottom_left_corner(const type& square);
void set_bottom_left_corner(type& square, Point point);
double get_side(const type& square);
}

namespace ConcreteRectangle {

using type = ConcreteShape;

ConcreteSquare::type make(Point bottom_left_corner, double width, double height);
Point get_bottom_left_corner(const type& rectangle);
void set_bottom_left_corner(type& rectangle, Point point);
double get_width(const type& rectangle);
double get_height(const type& rectangle);
}

namespace ConcreteCircle {

using type = ConcreteShape;

ConcreteSquare::type make(Point center, double radius);
Point get_center(const type& circle);
void set_center(type& circle, Point point);
double get_radius(const type& circle);
}

double compute_area(const ConcreteShape& shape);

void move(ConcreteShape& shape, double x, double y);

std::ostream& operator<<(std::ostream& s, const ConcreteShape& shape);
