//
// Created by tc on 07/07/2020.
//

#include "Movie.h"
Movie::Movie(const std::string& title, int price_code) : title(title), price_code(price_code)
{
}
int Movie::get_price_code() const
{
    return price_code;
}
void Movie::set_price_code(int price_code)
{
    Movie::price_code = price_code;
}
const std::string& Movie::get_title() const
{
    return title;
}
