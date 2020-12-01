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
    int price_code;

public:
    static constexpr int CHILDRENS{2};
    static constexpr int REGULAR{0};
    static constexpr int NEW_RELEASE{1};

    Movie(const std::string& title, int price_code);
    [[nodiscard]] int get_price_code() const;
    void set_price_code(int price_code);
    [[nodiscard]] const std::string& get_title() const;
};


#endif//DVDSHOP_MOVIE_H
