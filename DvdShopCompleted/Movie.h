//
// Created by tc on 07/07/2020.
//

#ifndef DVDSHOP_MOVIE_H
#define DVDSHOP_MOVIE_H

#include <string>

class Movie
{
private:
    std::string title;

public:
    explicit Movie(std::string  title);
    [[nodiscard]] const std::string& get_title() const;

    [[nodiscard]] virtual double determine_amount(int days_rented) const = 0;
    [[nodiscard]] virtual int determine_points(int days_rented) const = 0;
};


#endif//DVDSHOP_MOVIE_H
