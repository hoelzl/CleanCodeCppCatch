//
// Created by tc on 08/07/2020.
//

#include "RentalStatement.h"
#include <iomanip>
#include <sstream>
#include <string>

using namespace std::literals::string_literals;

std::string to_string(double d)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << d;
    return stream.str();
}

RentalStatement::RentalStatement(const std::string& customer_name) : customer_name(customer_name)
{
}

void RentalStatement::add_rental(const Rental& rental)
{
    rentals.push_back(rental);
}

std::string RentalStatement::get_customer_name() const
{
    return customer_name;
}
std::string RentalStatement::make_rental_statement()
{
    clear_totals();
    return make_header() + make_rental_items() + make_footer();
}

void RentalStatement::clear_totals()
{
    total_amount = 0;
    frequent_renter_points = 0;
}

std::string RentalStatement::make_header()
{
    return "Rental Record for "s + get_customer_name() + "\n"s;
}

std::string RentalStatement::make_rental_items()
{
    std::string rental_items{};
    for (Rental& rental : rentals) {
        rental_items += make_rental_item(rental);
    }
    return rental_items;
}

std::string RentalStatement::make_rental_item(Rental& rental)
{
    double rental_amount{rental.determine_amount()};
    frequent_renter_points += rental.determine_points();
    total_amount += rental_amount;

    return format_rental_item(rental, rental_amount);
}

std::string RentalStatement::format_rental_item(Rental& rental, double amount)
{
    return "\t"s + rental.get_title() + "\t"s + to_string(amount) + "\n"s;
}

std::string RentalStatement::make_footer()
{
    return "You owed "s + to_string(total_amount) + "\n"s + "You earned "s + std::to_string(frequent_renter_points) +
           " frequent renter points\n"s;
}
double RentalStatement::get_owned() const
{
    return total_amount;
}
int RentalStatement::get_points() const
{
    return frequent_renter_points;
}
