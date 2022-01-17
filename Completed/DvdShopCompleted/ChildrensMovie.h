#ifndef DVDSHOP_CHILDRENSMOVIE_H
#define DVDSHOP_CHILDRENSMOVIE_H

#include "Movie.h"

class ChildrensMovie : public Movie
{
public:
    explicit ChildrensMovie(const std::string& title);
    [[nodiscard]] double determine_amount(int days_rented) const override;
    [[nodiscard]] int determine_points(int days_rented) const override;
};


#endif // DVDSHOP_CHILDRENSMOVIE_H
