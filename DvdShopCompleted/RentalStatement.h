//
// Created by tc on 08/07/2020.
//

#ifndef DVDSHOP_RENTALSTATEMENT_H
#define DVDSHOP_RENTALSTATEMENT_H

#include "Rental.h"
#include <string>
#include <vector>

class RentalStatement
{
private:
    std::string customer_name;
    std::vector<Rental> rentals{};
    double total_amount{};
    int frequent_renter_points{};

public:
    explicit RentalStatement(const std::string& customer_name);
    void add_rental(const Rental& rental);
    [[nodiscard]] std::string get_customer_name() const;
    std::string make_rental_statement();
    void clear_totals();
    std::string make_header();
    std::string make_rental_items();
    std::string make_rental_item(Rental& rental);
    std::string format_rental_item(Rental& rental, double amount);
    std::string make_footer();
    [[nodiscard]] double get_owned() const;
    [[nodiscard]] int get_points() const;
};


#endif//DVDSHOP_RENTALSTATEMENT_H
