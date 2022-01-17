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
    [[nodiscard]] std::string get_title() const;
    [[nodiscard]] double determine_amount() const;
    [[nodiscard]] int determine_points() const;
};


#endif // DVDSHOP_RENTAL_H
