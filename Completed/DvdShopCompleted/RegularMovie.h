#ifndef DVDSHOP_REGULARMOVIE_H
#define DVDSHOP_REGULARMOVIE_H

#include "Movie.h"

class RegularMovie : public Movie
{
public:
    explicit RegularMovie(const std::string& title);
    [[nodiscard]] double determine_amount(int days_rented) const override;
    [[nodiscard]] int determine_points(int days_rented) const override;
};


#endif // DVDSHOP_REGULARMOVIE_H
