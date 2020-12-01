//
// Created by tc on 08/07/2020.
//

#include "NewReleaseMovie.h"

NewReleaseMovie::NewReleaseMovie(const std::string & title) : Movie(title){}

double NewReleaseMovie::determine_amount(int days_rented) const
{
    return days_rented * 3.0;
}

int NewReleaseMovie::determine_points(int days_rented) const
{
    return (days_rented > 1) ? 2 : 1;
}
