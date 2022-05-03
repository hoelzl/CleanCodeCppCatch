#include "shape.h"

#include <cmath>

#include "point.h"

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    return shape.write_to_stream(os);
}

Square::Square(Point bottom_left_corner, double side)
{
    this->bottom_left_corner = bottom_left_corner;
    this->side = side;
}

double Square::compute_area() const { return side * side; }

void Square::move(double x, double y)
{
    const Point new_location{bottom_left_corner + Point{x, y}};
    bottom_left_corner = new_location;
}

std::ostream& Square::write_to_stream(std::ostream& s) const
{
    s << "Square(" << bottom_left_corner << ", " << side << ")";
    return s;
}

Rectangle::Rectangle(Point bottom_left_corner, double width, double height)
{
    this->bottom_left_corner = bottom_left_corner;
    this->width = width;
    this->height = height;
}

double Rectangle::compute_area() const { return width * height; }

void Rectangle::move(double x, double y)
{
    const Point new_location{bottom_left_corner + Point{x, y}};
    bottom_left_corner = new_location;
}

std::ostream& Rectangle::write_to_stream(std::ostream& s) const
{
    s << "Rectangle(" << bottom_left_corner << ", " << width << ", " << height << ")";
    return s;
}

Circle::Circle(Point center, double radius)
{
    this->center = center;
    this->radius = radius;
}

double Circle::compute_area() const { return 4.0 * atan(1.0) * radius * radius; }

void Circle::move(double x, double y)
{
    const Point new_location{center + Point{x, y}};
    center = new_location;
}

std::ostream& Circle::write_to_stream(std::ostream& s) const
{
    s << "Circle(" << center << ", " << radius << ")";
    return s;
}

RawSquare::type RawSquare::make(Point bottom_left_corner, double side)
{
    return RawShape(ShapeKind::Square, bottom_left_corner, side, 0.0);
}

Point RawSquare::get_bottom_left_corner(const type& square) { return square.point; }

void RawSquare::set_bottom_left_corner(type& square, Point point)
{
    square.point = point;
}

double RawSquare::get_side(const type& square) { return square.data1; }

RawRectangle::type
RawRectangle::make(Point bottom_left_corner, double width, double height)
{
    return RawShape(ShapeKind::Rectangle, bottom_left_corner, width, height);
}

Point RawRectangle::get_bottom_left_corner(const type& rectangle)
{
    return rectangle.point;
}

void RawRectangle::set_bottom_left_corner(type& rectangle, Point point)
{
    rectangle.point = point;
}

double RawRectangle::get_width(const type& rectangle) { return rectangle.data1; }

double RawRectangle::get_height(const type& rectangle) { return rectangle.data2; }

RawCircle::type RawCircle::make(Point center, double radius)
{
    return RawShape(ShapeKind::Circle, center, radius, 0.0);
}

Point RawCircle::get_center(const type& circle) { return circle.point; }

void RawCircle::set_center(type& circle, Point point) { circle.point = point; }

double RawCircle::get_radius(const type& circle) { return circle.data1; }

double compute_area(const RawShape& shape)
{
    switch (shape.get_shape_kind()) {
    case ShapeKind::Square: {
        const double side{RawSquare::get_side(shape)};
        return side * side;
    }
    case ShapeKind::Rectangle: {
        const double width{RawRectangle::get_width(shape)};
        const double height{RawRectangle::get_height(shape)};
        return width * height;
    }
    case ShapeKind::Circle: {
        const double radius{RawCircle::get_radius(shape)};
        return 4.0 * atan(1.0) * radius * radius;
    }
    default: throw std::invalid_argument("Invalid shape.");
    }
}

void move(RawShape& shape, double x, double y)
{
    switch (shape.get_shape_kind()) {
    case ShapeKind::Square: {
        const Point new_location{
            RawSquare::get_bottom_left_corner(shape) + Point{x, y}};
        RawSquare::set_bottom_left_corner(shape, new_location);
        break;
    }
    case ShapeKind::Rectangle: {
        const Point new_location{
            RawRectangle::get_bottom_left_corner(shape) + Point{x, y}};
        RawRectangle::set_bottom_left_corner(shape, new_location);
        break;
    }
    case ShapeKind::Circle: {
        const Point new_location{RawCircle::get_center(shape) + Point{x, y}};
        RawCircle::set_center(shape, new_location);
        break;
    }
    default: throw std::invalid_argument("Invalid shape.");
    }
}

std::ostream& operator<<(std::ostream& s, const RawShape& shape)
{
    const RawShape* shape_ptr{&shape};
    if (shape.get_shape_kind() == ShapeKind::Square) {
        s << "RawSquare(" << RawSquare::get_bottom_left_corner(shape) << ", "
          << RawSquare::get_side(shape) << ")";
    }
    else if (shape.get_shape_kind() == ShapeKind::Rectangle) {
        s << "RawRectangle(" << RawRectangle::get_bottom_left_corner(shape) << ", "
          << RawRectangle::get_height(shape) << ", " << RawRectangle::get_width(shape)
          << ")";
    }
    else if (shape.get_shape_kind() == ShapeKind::Circle) {
        s << "RawCircle(" << RawCircle::get_center(shape) << ", "
          << RawCircle::get_radius(shape) << ")";
    }
    else {
        throw std::invalid_argument("Invalid shape.");
    }
    return s;
}
