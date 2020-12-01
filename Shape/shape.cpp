#include "shape.h"
#include "point.h"
#include <cmath>

std::ostream& operator<<(std::ostream& s, const AbstractShape& shape)
{
    const AbstractShape* shape_ptr { &shape };
    if (auto square = dynamic_cast<const AbstractSquare*>(shape_ptr)) {
        s << *square;
    } else if (auto rectangle = dynamic_cast<const AbstractRectangle*>(shape_ptr)) {
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
    Point new_location { bottom_left_corner + Point { x, y } };
    bottom_left_corner = new_location;
}

std::ostream& operator<<(std::ostream& s, const AbstractSquare& square)
{
    s << "AbstractSquare(" << square.bottom_left_corner << ", " << square.side << ")";
    return s;
}

AbstractRectangle::AbstractRectangle(Point bottom_left_corner, double width, double height)
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
    Point new_location { bottom_left_corner + Point { x, y } };
    bottom_left_corner = new_location;
}

std::ostream& operator<<(std::ostream& s, const AbstractRectangle& rect)
{
    s << "AbstractRectangle(" << rect.bottom_left_corner << ", "
      << rect.width << ", " << rect.height << ")";
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
    Point new_location { center + Point { x, y } };
    center = new_location;
}

std::ostream& operator<<(std::ostream& s, const AbstractCircle& circle)
{
    s << "AbstractCircle(" << circle.center << ", " << circle.radius << ")";
    return s;
}

ConcreteSquare::ConcreteSquare(Point bottom_left_corner, double side)
{
    this->bottom_left_corner = bottom_left_corner;
    this->side = side;
}

ShapeType ConcreteSquare::get_type() const
{
    return ShapeType::Square;
}

ConcreteRectangle::ConcreteRectangle(Point bottom_left_corner, double width, double height)
{
    this->bottom_left_corner = bottom_left_corner;
    this->width = width;
    this->height = height;
}

ShapeType ConcreteRectangle::get_type() const
{
    return ShapeType::Rectangle;
}

ConcreteCircle::ConcreteCircle(Point center, double radius)
{
    this->center = center;
    this->radius = radius;
}

ShapeType ConcreteCircle::get_type() const
{
    return ShapeType::Circle;
}

double compute_area(const ConcreteShape& shape)
{
    switch (shape.get_type()) {
    case ShapeType::Square: {
        auto square { static_cast<const ConcreteSquare&>(shape) };
        return square.side * square.side;
    }
    case ShapeType::Rectangle: {
        auto rectangle { static_cast<const ConcreteRectangle&>(shape) };
        return rectangle.width * rectangle.height;
    }
    case ShapeType::Circle: {
        auto circle { static_cast<const ConcreteCircle&>(shape) };
        return 4.0 * atan(1.0) * circle.radius * circle.radius;
    }
    default:
        throw std::invalid_argument("Invalid shape.");
    }
}

void move(const ConcreteShape& shape, double x, double y)
{
    switch (shape.get_type()) {
    case ShapeType::Square: {
        auto square { static_cast<const ConcreteSquare&>(shape) };
        Point new_location { square.bottom_left_corner + Point { x, y } };
        square.bottom_left_corner = new_location;
        break;
    }
    case ShapeType::Rectangle: {
        auto rectangle { static_cast<const ConcreteRectangle&>(shape) };
        Point new_location { rectangle.bottom_left_corner + Point { x, y } };
        rectangle.bottom_left_corner = new_location;
        break;
    }
    case ShapeType::Circle: {
        auto circle { static_cast<const ConcreteCircle&>(shape) };
        Point new_location { circle.center + Point { x, y } };
        circle.center = new_location;
        break;
    }
    default:
        throw std::invalid_argument("Invalid shape.");
    }
}

template <typename T>
void move_shape_with_bottom_left_corner(const ConcreteShape& shape, double x, double y)
{
    auto downcast_shape { static_cast<const T&>(shape) };
    Point new_location { downcast_shape.bottom_left_corner + Point { x, y } };
    downcast_shape.bottom_left_corner = new_location;
}

void move_v2(const ConcreteShape& shape, double x, double y)
{
    switch (shape.get_type()) {
    case ShapeType::Square:
        move_shape_with_bottom_left_corner<ConcreteSquare>(shape, x, y);
        break;
    case ShapeType::Rectangle:
        move_shape_with_bottom_left_corner<ConcreteRectangle>(shape, x, y);
        break;
    case ShapeType::Circle: {
        auto circle { static_cast<const ConcreteCircle&>(shape) };
        Point new_location { circle.center + Point { x, y } };
        circle.center = new_location;
        break;
    }
    default:
        throw std::invalid_argument("Invalid shape.");
    }
}

std::ostream& operator<<(std::ostream& s, const ConcreteShape& shape)
{
    const ConcreteShape* shape_ptr { &shape };
    if (auto square = dynamic_cast<const ConcreteSquare*>(shape_ptr)) {
        s << "ConcreteSquare(" << square->bottom_left_corner
          << ", " << square->side << ")";
    } else if (auto rectangle = dynamic_cast<const ConcreteRectangle*>(shape_ptr)) {
        s << "ConcreteRectangle(" << rectangle->bottom_left_corner
          << ", " << rectangle->height
          << ", " << rectangle->width << ")";
    } else if (auto circle = dynamic_cast<const ConcreteCircle*>(shape_ptr)) {
        s << "ConcreteCircle(" << circle->center
          << ", " << circle->radius << ")";
    } else {
        throw std::invalid_argument("Invalid shape.");
    }
    return s;
}
