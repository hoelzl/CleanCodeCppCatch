#include "shape.h"
#include <iostream>

void print_abstract_shape(const AbstractShape& shape)
{
    std::cout << shape << ", area: " << shape.compute_area() << std::endl;
}

void test_abstract_shape(AbstractShape& shape)
{
    print_abstract_shape(shape);
    shape.move(1.0, 1.0);
    print_abstract_shape(shape);
    std::cout << std::endl;
}

void print_concrete_shape(const ConcreteShape& shape)
{
    std::cout << shape << ", area: " << compute_area(shape) << std::endl;
}

void test_concrete_shape(ConcreteShape& shape)
{
    print_concrete_shape(shape);
    move(shape, 1.0, 1.0);
    print_concrete_shape(shape);
    std::cout << std::endl;
}


int main()
{
    AbstractSquare abstract_square{Point{}, 2.0};
    test_abstract_shape(abstract_square);
    AbstractRectangle abstract_rectangle{Point{}, 2.0, 3.0};
    test_abstract_shape(abstract_rectangle);
    AbstractCircle abstract_circle{Point{}, 1.0};
    test_abstract_shape(abstract_circle);

    ConcreteSquare::type concrete_square{ConcreteSquare::make(Point{}, 2.0)};
    test_concrete_shape(concrete_square);
    ConcreteRectangle::type concrete_rectangle{
            ConcreteRectangle::make(Point{}, 2.0, 3.0)};
    test_concrete_shape(concrete_rectangle);
    ConcreteCircle::type concrete_circle{ConcreteCircle::make(Point{}, 1.0)};
    test_concrete_shape(concrete_circle);
}
