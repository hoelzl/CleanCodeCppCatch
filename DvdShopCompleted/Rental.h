//
// Created by tc on 07/07/2020.
//

#ifndef DVDSHOP_RENTAL_H
#define DVDSHOP_RENTAL_H


#include "Movie.h"
class Rental
{
private:
    const Movie& movie;
    int days_rented;

public:
    Rental(const Movie& movie, int days_rented);
    std::string get_title() const;
    double determine_amount() const;
    int determine_points() const;
};


#endif//DVDSHOP_RENTAL_H
