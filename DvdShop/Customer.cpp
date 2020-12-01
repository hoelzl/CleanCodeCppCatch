//
// Created by tc on 07/07/2020.
//

#include "Customer.h"

#include <iomanip>
#include <sstream>
#include <utility>
Customer::Customer(std::string name) : name(std::move(name))
{
}
void Customer::add_rental(const Rental& rental)
{
    rentals.push_back(rental);
}
const std::string& Customer::get_name() const
{
    return name;
}

std::string Customer::statement()
{
    double total_amount{0.0};
    int frequent_renter_points{0};
    auto it{std::begin(rentals)};
    std::string result{"Rental Record for "s + name + "\n"s};

    while (it != std::end(rentals)) {
        double this_amount{0.0};
        Rental& each{*it};

        // Determines the amount for each line
        switch (it->get_movie().get_price_code()) {
            case Movie::REGULAR:
                this_amount += 2.0;
                if (it->get_days_rented() > 2) {
                    this_amount += (it->get_days_rented() - 2) * 1.5;
                }
                break;
            case Movie::NEW_RELEASE: this_amount += it->get_days_rented() * 3.0; break;
            case Movie::CHILDRENS:
                this_amount += 1.5;
                if (it->get_days_rented() > 3) {
                    this_amount += (it->get_days_rented() - 3) * 1.5;
                }
                break;
        }

        frequent_renter_points++;

        if (it->get_movie().get_price_code() == Movie::NEW_RELEASE && it->get_days_rented() > 1) {
            frequent_renter_points++;
        }

        result += "\t" + it->get_movie().get_title() + "\t" + to_string(this_amount) + "\n";
        total_amount += this_amount;
        ++it;
    }

    result += "You owed " + to_string(total_amount) + "\n";
    result += "You earned " + std::to_string(frequent_renter_points) + " frequent renter points\n";

    return result;
}
std::string Customer::to_string(double d)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << d;
    return stream.str();
}
