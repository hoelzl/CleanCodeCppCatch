#pragma once

#include <iostream>
#include <string>

class Resource
{
    std::string description;

public:
    explicit Resource(std::string description) : description(std::move(description)) {}

    std::string get_description() const { return description; }
};

inline std::ostream& operator<<(std::ostream& s, const Resource& res)
{
    s << "Resource(" << res.get_description() << ")";
    return s;
}