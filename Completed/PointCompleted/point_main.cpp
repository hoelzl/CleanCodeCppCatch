#include <iostream>

#include "encapsulated_point.h"
#include "raw_point.h"

int main()  // NOLINT(bugprone-exception-escape)
{
    std::cout << "Creating points." << std::endl;

    constexpr RawPoint cp1{1.0, 2.0};
    constexpr RawPoint cp2{2.0, 3.0};
    const RawPoint cp3{cp1 + cp2};

    // atan(1) is pi/4; and this is not clean code :)
    const RawPoint cp4{point_from_polar(sqrt(2), atan(1))};

    std::cout << cp1 << "\n";
    std::cout << cp2 << "\n";
    std::cout << cp3 << "\n";
    std::cout << cp4 << "\n";

    std::cout << std::endl;

    const EncapsulatedPoint ap1{EncapsulatedPoint::from_cartesian(1.0, 2.0)};
    const EncapsulatedPoint ap2{EncapsulatedPoint::from_cartesian(2.0, 3.0)};
    const EncapsulatedPoint ap3{ap1 + ap2};
    const EncapsulatedPoint ap4{EncapsulatedPoint::from_polar(sqrt(2), atan(1))};

    std::cout << ap1 << "\n";
    std::cout << ap2 << "\n";
    std::cout << ap3 << "\n";
    std::cout << ap4 << "\n";
}
