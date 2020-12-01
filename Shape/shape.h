#pragma once

#include "point.h"
#include <iostream>
#include <array>

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
    virtual ShapeType get_type() const = 0;
};

struct ConcreteSquare : public ConcreteShape {
    Point bottom_left_corner {};
    double side { 1.0 };

    ConcreteSquare(Point bottom_left_corner, double side);

    ShapeType get_type() const override;
};

struct ConcreteRectangle : public ConcreteShape {
    Point bottom_left_corner {};
    double width { 1.0 };
    double height { 1.0 };

    ConcreteRectangle(Point bottom_left_corner, double width, double height);

    ShapeType get_type() const override;
};

struct ConcreteCircle : public ConcreteShape {
    Point center {};
    double radius { 1.0 };

    ConcreteCircle(Point center, double radius);

    ShapeType get_type() const override;
};

double compute_area(const ConcreteShape& shape);

void move(const ConcreteShape& shape, double x, double y);

std::ostream& operator<<(std::ostream& s, const ConcreteShape& shape);
