#include <iostream>

#include "abstract_point.h"
#include "concrete_point.h"

int main()
{
    std::cout << "Creating points." << std::endl;

    ConcretePoint cp1 { 1.0, 2.0 };
    ConcretePoint cp2 { 2.0, 3.0 };
    ConcretePoint cp3 { add(cp1, cp2) };

    print(cp1);
    print(cp2);
    print(cp3);
    std::cout << std::endl;

    AbstractPoint ap1 { AbstractPoint::from_cartesian(1.0, 2.0) };
    AbstractPoint ap2 { AbstractPoint::from_cartesian(2.0, 3.0) };
    AbstractPoint ap3 { ap1 + ap2 };

    // atan(1) is pi/4; and this is not clean code :)
    AbstractPoint ap4 { AbstractPoint::from_polar(sqrt(2), atan(1)) };

    std::cout << ap1 << std::endl;
    std::cout << ap2 << std::endl;
    std::cout << ap3 << std::endl;
    std::cout << ap4 << std::endl;
}
