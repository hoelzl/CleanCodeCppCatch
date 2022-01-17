#include "Movie.h"

Movie::Movie(std::string title, int price_code)
    : title(std::move(title)), price_code(price_code)
{}

int Movie::get_price_code() const { return price_code; }

void Movie::set_price_code(int price_code) { Movie::price_code = price_code; }

const std::string& Movie::get_title() const { return title; }
