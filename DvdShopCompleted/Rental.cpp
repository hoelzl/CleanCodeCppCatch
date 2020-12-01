//
// Created by tc on 07/07/2020.
//

#include "Rental.h"
Rental::Rental(const Movie& movie, int days_rented) : movie(movie), days_rented(days_rented)
{
}

std::string Rental::get_title() const
{
    return movie.get_title();
}

double Rental::determine_amount() const
{
    return movie.determine_amount(days_rented);
}

int Rental::determine_points() const
{
    return movie.determine_points(days_rented);
}
