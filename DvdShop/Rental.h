//
// Created by tc on 07/07/2020.
//

#ifndef DVDSHOP_RENTAL_H
#define DVDSHOP_RENTAL_H


#include "Movie.h"
class Rental
{
private:
    Movie movie;
    int days_rented;

public:
    Rental(const Movie& movie, int days_rented);
    [[nodiscard]] const Movie& get_movie() const;
    [[nodiscard]] int get_days_rented() const;
};


#endif//DVDSHOP_RENTAL_H
