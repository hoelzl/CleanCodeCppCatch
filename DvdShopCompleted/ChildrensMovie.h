#ifndef DVDSHOP_CHILDRENSMOVIE_H
#define DVDSHOP_CHILDRENSMOVIE_H


#include "Movie.h"
class ChildrensMovie : public Movie
{
public:
    ChildrensMovie(const std::string& title);
    double determine_amount(int days_rented) const override;
    int determine_points(int days_rented) const override;
};


#endif//DVDSHOP_CHILDRENSMOVIE_H
