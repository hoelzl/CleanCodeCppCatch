//
// Created by tc on 08/07/2020.
//

#ifndef DVDSHOP_REGULARMOVIE_H
#define DVDSHOP_REGULARMOVIE_H

#include "Movie.h"

class RegularMovie : public Movie
{
public:
    RegularMovie(const std::string & title);
    double determine_amount(int days_rented) const override;
    int determine_points(int days_rented) const override;
};


#endif//DVDSHOP_REGULARMOVIE_H
