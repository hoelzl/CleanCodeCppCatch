#include "ChildrensMovie.h"

ChildrensMovie::ChildrensMovie(const std::string& title) : Movie(title) {}

double ChildrensMovie::determine_amount(int days_rented) const
{
    constexpr auto this_amount{1.5};
    if (days_rented > 3) {
        return this_amount + (days_rented - 3.0) * 1.5;
    }
    return this_amount;
}

int ChildrensMovie::determine_points(int days_rented) const { return 1; }
