#ifndef DVDSHOP_NEWRELEASEMOVIE_H
#define DVDSHOP_NEWRELEASEMOVIE_H

#include "Movie.h"

class NewReleaseMovie : public Movie
{
public:
    explicit NewReleaseMovie(const std::string& title);
    [[nodiscard]] double determine_amount(int days_rented) const override;
    [[nodiscard]] int determine_points(int days_rented) const override;
};


#endif // DVDSHOP_NEWRELEASEMOVIE_H
