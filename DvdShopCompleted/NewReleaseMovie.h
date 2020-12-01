//
// Created by tc on 08/07/2020.
//

#ifndef DVDSHOP_NEWRELEASEMOVIE_H
#define DVDSHOP_NEWRELEASEMOVIE_H

#include "Movie.h"

class NewReleaseMovie : public Movie
{
public:
    NewReleaseMovie(const std::string & title);
    double determine_amount(int days_rented) const override;
    int determine_points(int days_rented) const override;
};


#endif//DVDSHOP_NEWRELEASEMOVIE_H
