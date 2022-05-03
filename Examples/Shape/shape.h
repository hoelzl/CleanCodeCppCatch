// ReSharper disable CppClangTidyCppcoreguidelinesNonPrivateMemberVariablesInClasses
#pragma once

#include <iostream>

#include "point.h"

class Shape
{
public:
    Shape() = default;
    Shape(const Shape& other) = delete;
    Shape(Shape&& other) noexcept = delete;
    Shape& operator=(const Shape& other) = delete;
    Shape& operator=(Shape&& other) noexcept = delete;
    virtual ~Shape() = default;

    [[nodiscard]] virtual double compute_area() const = 0;
    virtual void move(double x, double y) = 0;

protected:
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
    virtual std::ostream& write_to_stream(std::ostream& s) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Shape& shape);

class Square : public Shape
{
    Point bottom_left_corner{};
    double side{1.0};

public:
    Square(Point bottom_left_corner, double side);

    [[nodiscard]] double compute_area() const override;
    void move(double x, double y) override;

protected:
    std::ostream& write_to_stream(std::ostream& s) const override;
};

class Rectangle : public Shape
{
    Point bottom_left_corner{};
    double width{1.0};
    double height{1.0};

public:
    Rectangle(Point bottom_left_corner, double width, double height);

    [[nodiscard]] double compute_area() const override;
    void move(double x, double y) override;

protected:
    std::ostream& write_to_stream(std::ostream& s) const override;
};

class Circle : public Shape
{
    Point center{};
    double radius{1.0};

public:
    Circle(Point center, double radius);
    [[nodiscard]] double compute_area() const override;
    void move(double x, double y) override;

protected:
    std::ostream& write_to_stream(std::ostream& s) const override;
};

enum class ShapeKind
{
    Square,
    Rectangle,
    Circle
};

struct RawShape
{
    RawShape(ShapeKind shape_kind, Point point, double data1 = 0.0, double data2 = 0.0)
        : point{point}, data1{data1}, data2{data2}, shape_kind{shape_kind}
    {}

    Point point;
    double data1;
    double data2;

    [[nodiscard]] ShapeKind get_shape_kind() const { return shape_kind; }

private:
    ShapeKind shape_kind;
};

namespace RawSquare {
using type = RawShape;

RawSquare::type make(Point bottom_left_corner, double side);
Point get_bottom_left_corner(const type& square);
void set_bottom_left_corner(type& square, Point point);
double get_side(const type& square);
} // namespace RawSquare

namespace RawRectangle {
using type = RawShape;

RawSquare::type make(Point bottom_left_corner, double width, double height);
Point get_bottom_left_corner(const type& rectangle);
void set_bottom_left_corner(type& rectangle, Point point);
double get_width(const type& rectangle);
double get_height(const type& rectangle);
} // namespace RawRectangle

namespace RawCircle {
using type = RawShape;

RawSquare::type make(Point center, double radius);
Point get_center(const type& circle);
void set_center(type& circle, Point point);
double get_radius(const type& circle);
} // namespace RawCircle

double compute_area(const RawShape& shape);

void move(RawShape& shape, double x, double y);

std::ostream& operator<<(std::ostream& s, const RawShape& shape);
