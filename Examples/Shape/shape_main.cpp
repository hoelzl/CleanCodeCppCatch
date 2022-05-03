#include <iostream>

#include "shape.h"

void print_encapsulated_shape(const Shape& shape)
{
    std::cout << shape << ", area: " << shape.compute_area() << std::endl;
}

void test_encapsulated_shape(Shape& shape)
{
    print_encapsulated_shape(shape);
    shape.move(1.0, 2.0);
    print_encapsulated_shape(shape);
    std::cout << std::endl;
}

void print_raw_shape(const RawShape& shape)
{
    std::cout << shape << ", area: " << compute_area(shape) << std::endl;
}

void test_raw_shape(RawShape& shape)
{
    print_raw_shape(shape);
    move(shape, 1.0, 2.0);
    print_raw_shape(shape);
    std::cout << std::endl;
}

int main()
{
    Square square{Point{}, 2.0};
    test_encapsulated_shape(square);
    Rectangle rectangle{Point{}, 2.0, 3.0};
    test_encapsulated_shape(rectangle);
    Circle circle{Point{}, 1.0};
    test_encapsulated_shape(circle);

    // Don't do this...
    Shape* shape_ptr{new Square{Point{}, 2.0}};
    test_encapsulated_shape(*shape_ptr);
    delete shape_ptr;
    shape_ptr = new Rectangle{Point{}, 2.0, 3.0};
    test_encapsulated_shape(*shape_ptr);
    delete shape_ptr;
    shape_ptr = new Circle{Point{}, 1.0};
    test_encapsulated_shape(*shape_ptr);
    delete shape_ptr;

    // Do this instead.
    std::unique_ptr<Shape> shape{std::make_unique<Square>(Point{}, 2.0)};
    test_encapsulated_shape(*shape);
    shape = std::make_unique<Rectangle>(Point{}, 2.0, 3.0);
    test_encapsulated_shape(*shape);
    shape = std::make_unique<Circle>(Point{}, 1.0);
    test_encapsulated_shape(*shape);

    RawSquare::type concrete_square{RawSquare::make(Point{}, 2.0)};
    test_raw_shape(concrete_square);
    RawRectangle::type concrete_rectangle{RawRectangle::make(Point{}, 2.0, 3.0)};
    test_raw_shape(concrete_rectangle);
    RawCircle::type concrete_circle{RawCircle::make(Point{}, 1.0)};
    test_raw_shape(concrete_circle);
}
