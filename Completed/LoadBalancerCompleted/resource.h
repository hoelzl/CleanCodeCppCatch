// ReSharper disable CppClangTidyCppcoreguidelinesProTypeReinterpretCast
// ReSharper disable CppClangTidyBugproneExceptionEscape
#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#define SHOW_RESOURCE_LIFECYCLE 1

class Resource
{
    std::string description;

public:
    Resource(std::string description) : description(std::move(description))
    {
#if SHOW_RESOURCE_LIFECYCLE
        std::cout << "Creating resource " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
#endif
    }

#if SHOW_RESOURCE_LIFECYCLE
    Resource(const Resource& res) noexcept : description(res.description)
    {
        std::cout << "Creating resource " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << " via copy constructor."
                  << std::endl;
    }

    Resource(Resource&& res) noexcept : description(std::move(res.description))
    {
        std::cout << "Creating resource " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << " via move constructor."
                  << std::endl;
    }

    Resource& operator=(const Resource& res) noexcept
    {
        std::cout << "Copy assigning resource " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
        this->description = res.description;
        return *this;
    }

    Resource& operator=(Resource&& res) noexcept
    {
        std::cout << "Move assigning resource " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
        this->description = std::move(res.description);
        return *this;
    }

    ~Resource()
    {
        std::cout << "Releasing resource " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
    }
#endif

    [[nodiscard]] std::string get_description() const { return description; }
};

inline std::ostream& operator<<(std::ostream& s, const Resource& res)
{
    s << "Resource(" << res.get_description() << ")";
    return s;
}
