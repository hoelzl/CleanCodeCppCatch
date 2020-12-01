#include "shape.h"
#include "point.h"
#include <cmath>

std::ostream& operator<<(std::ostream& s, const AbstractShape& shape)
{
    const AbstractShape* shape_ptr{&shape};
    if (auto square = dynamic_cast<const AbstractSquare*>(shape_ptr)) {
        s << *square;
    } else if (auto rectangle =
                       dynamic_cast<const AbstractRectangle*>(shape_ptr)) {
        s << *rectangle;
    } else if (auto circle = dynamic_cast<const AbstractCircle*>(shape_ptr)) {
        s << *circle;
    } else {
        throw std::invalid_argument("Invalid shape.");
    }
    return s;
}

AbstractSquare::AbstractSquare(Point bottom_left_corner, double side)
{
    this->bottom_left_corner = bottom_left_corner;
    this->side = side;
}

double AbstractSquare::compute_area() const
{
    return side * side;
}

void AbstractSquare::move(double x, double y)
{
    Point new_location{bottom_left_corner + Point{x, y}};
    bottom_left_corner = new_location;
}

std::ostream& operator<<(std::ostream& s, const AbstractSquare& square)
{
    s << "AbstractSquare(" << square.bottom_left_corner << ", " << square.side
      << ")";
    return s;
}

AbstractRectangle::AbstractRectangle(Point bottom_left_corner, double width,
                                     double height)
{
    this->bottom_left_corner = bottom_left_corner;
    this->width = width;
    this->height = height;
}

double AbstractRectangle::compute_area() const
{
    return width * height;
}

void AbstractRectangle::move(double x, double y)
{
    Point new_location{bottom_left_corner + Point{x, y}};
    bottom_left_corner = new_location;
}

std::ostream& operator<<(std::ostream& s, const AbstractRectangle& rect)
{
    s << "AbstractRectangle(" << rect.bottom_left_corner << ", " << rect.width
      << ", " << rect.height << ")";
    return s;
}

AbstractCircle::AbstractCircle(Point center, double radius)
{
    this->center = center;
    this->radius = radius;
}

double AbstractCircle::compute_area() const
{
    return 4.0 * atan(1.0) * radius * radius;
}

void AbstractCircle::move(double x, double y)
{
    Point new_location{center + Point{x, y}};
    center = new_location;
}

std::ostream& operator<<(std::ostream& s, const AbstractCircle& circle)
{
    s << "AbstractCircle(" << circle.center << ", " << circle.radius << ")";
    return s;
}

ConcreteSquare::type ConcreteSquare::make(Point bottom_left_corner, double side)
{
    return ConcreteShape(ShapeType::Square, bottom_left_corner, side, 0.0);
}

Point ConcreteSquare::get_bottom_left_corner(const type& square)
{
    return square.point;
}

void ConcreteSquare::set_bottom_left_corner(type& square, Point point)
{
    square.point = point;
}

double ConcreteSquare::get_side(const type& square)
{
    return square.data1;
}

ConcreteRectangle::type ConcreteRectangle::make(Point bottom_left_corner,
                                                double width, double height)
{
    return ConcreteShape(ShapeType::Rectangle, bottom_left_corner, width,
                         height);
}

Point ConcreteRectangle::get_bottom_left_corner(const type& rectangle)
{
    return rectangle.point;
}

void ConcreteRectangle::set_bottom_left_corner(type& rectangle, Point point)
{
    rectangle.point = point;
}

double ConcreteRectangle::get_width(const type& rectangle)
{
    return rectangle.data1;
}

double ConcreteRectangle::get_height(const type& rectangle)
{
    return rectangle.data2;
}

ConcreteCircle::type ConcreteCircle::make(Point center, double radius)
{
    return ConcreteShape(ShapeType::Circle, center, radius, 0.0);
}

Point ConcreteCircle::get_center(const type& circle)
{
    return circle.point;
}

void ConcreteCircle::set_center(type& circle, Point point)
{
    circle.point = point;
}

double ConcreteCircle::get_radius(const type& circle)
{
    return circle.data1;
}

double compute_area(const ConcreteShape& shape)
{
    switch (shape.get_type()) {
        case ShapeType::Square: {
            double side{ConcreteSquare::get_side(shape)};
            return side * side;
        }
        case ShapeType::Rectangle: {
            double width{ConcreteRectangle::get_width(shape)};
            double height{ConcreteRectangle::get_height(shape)};
            return width * height;
        }
        case ShapeType::Circle: {
            double radius{ConcreteCircle::get_radius(shape)};
            return 4.0 * atan(1.0) * radius * radius;
        }
        default: throw std::invalid_argument("Invalid shape.");
    }
}

void move(ConcreteShape& shape, double x, double y)
{
    switch (shape.get_type()) {
        case ShapeType::Square: {
            Point new_location{ConcreteSquare::get_bottom_left_corner(shape) +
                               Point{x, y}};
            ConcreteSquare::set_bottom_left_corner(shape, new_location);
            break;
        }
        case ShapeType::Rectangle: {
            Point new_location{
                    ConcreteRectangle::get_bottom_left_corner(shape) +
                    Point{x, y}};
            ConcreteRectangle::set_bottom_left_corner(shape, new_location);
            break;
        }
        case ShapeType::Circle: {
            Point new_location{ConcreteCircle::get_center(shape) + Point{x, y}};
            ConcreteCircle::set_center(shape, new_location);
            break;
        }
        default: throw std::invalid_argument("Invalid shape.");
    }
}

std::ostream& operator<<(std::ostream& s, const ConcreteShape& shape)
{
    const ConcreteShape* shape_ptr{&shape};
    if (shape.get_type() == ShapeType::Square) {
        s << "ConcreteSquare(" << ConcreteSquare::get_bottom_left_corner(shape)
          << ", " << ConcreteSquare::get_side(shape) << ")";
    } else if (shape.get_type() == ShapeType::Rectangle) {
        s << "ConcreteRectangle("
          << ConcreteRectangle::get_bottom_left_corner(shape) << ", "
          << ConcreteRectangle::get_height(shape) << ", "
          << ConcreteRectangle::get_width(shape) << ")";
    } else if (shape.get_type() == ShapeType::Circle) {
        s << "ConcreteCircle(" << ConcreteCircle::get_center(shape) << ", "
          << ConcreteCircle::get_radius(shape) << ")";
    } else {
        throw std::invalid_argument("Invalid shape.");
    }
    return s;
}
