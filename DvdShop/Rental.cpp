//
// Created by tc on 07/07/2020.
//

#include "Rental.h"
Rental::Rental(const Movie& movie, int days_rented) : movie(movie), days_rented(days_rented)
{
}
const Movie& Rental::get_movie() const
{
    return movie;
}
int Rental::get_days_rented() const
{
    return days_rented;
}
