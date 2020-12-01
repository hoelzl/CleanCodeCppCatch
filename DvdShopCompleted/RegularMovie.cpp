//
// Created by tc on 08/07/2020.
//

#include "RegularMovie.h"

RegularMovie::RegularMovie(const std::string& title) : Movie(title)
{
}

double RegularMovie::determine_amount(int days_rented) const
{
    double this_amount{2.0};
    if (days_rented > 2) {
        this_amount += (days_rented - 2) * 1.5;
    }
    return this_amount;
}

int RegularMovie::determine_points(int days_rented) const
{
    return 1;
}
