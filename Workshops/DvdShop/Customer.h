#ifndef DVDSHOP_CUSTOMER_H
#define DVDSHOP_CUSTOMER_H

#include <string>
#include <vector>

#include "Rental.h"

using namespace std::literals::string_literals;

class Customer
{
private:
    std::string name;
    std::vector<Rental> rentals{};
    static std::string to_string(double d);

public:
    explicit Customer(std::string name);
    void add_rental(const Rental& rental);
    [[nodiscard]] const std::string& get_name() const;
    std::string statement();
};


#endif // DVDSHOP_CUSTOMER_H
