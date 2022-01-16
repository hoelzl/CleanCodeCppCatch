#pragma once

#include <string>
#include <iostream>

class Resource
{
    std::string description;

public:
    Resource(std::string description) : description(description)
    {
    }

    std::string get_description() const
    {
        return description;
    }
};

inline std::ostream& operator<<(std::ostream& s, const Resource& res)
{
    s << "Resource(" << res.get_description() << ")";
    return s;
}