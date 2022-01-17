#include "Movie.h"

#include <string>
#include <utility>

Movie::Movie(std::string title) : title(std::move(title)) {}

const std::string& Movie::get_title() const { return title; }
