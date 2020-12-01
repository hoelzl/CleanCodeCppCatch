//
// Created by tc on 07/07/2020.
//

#include "Movie.h"

#include <utility>

Movie::Movie(std::string  title) : title(std::move(title))
{
}

const std::string& Movie::get_title() const
{
    return title;
}
