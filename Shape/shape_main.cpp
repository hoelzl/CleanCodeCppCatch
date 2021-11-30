#include "shape.h"
#include <iostream>

void print_encapsulated_shape(const AbstractShape& shape)
{
    std::cout << shape << ", area: " << shape.compute_area() << std::endl;
}

void test_encapsulated_shape(AbstractShape& shape)
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
    Square abstract_square{Point{}, 2.0};
    test_encapsulated_shape(abstract_square);
    Rectangle abstract_rectangle{Point{}, 2.0, 3.0};
    test_encapsulated_shape(abstract_rectangle);
    Circle abstract_circle{Point{}, 1.0};
    test_encapsulated_shape(abstract_circle);

    RawSquare::type concrete_square{RawSquare::make(Point{}, 2.0)};
    test_raw_shape(concrete_square);
    RawRectangle::type concrete_rectangle{RawRectangle::make(Point{}, 2.0, 3.0)};
    test_raw_shape(concrete_rectangle);
    RawCircle::type concrete_circle{RawCircle::make(Point{}, 1.0)};
    test_raw_shape(concrete_circle);
}
