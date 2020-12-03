#pragma once
#include <iostream>
#include <cstdint>
#include <string>

using namespace std::string_literals;

class Animal
{
public:
#if SHOW_ANIMAL_INSTANCE_LIFE_CYCLE
    Animal() noexcept
    {
        std::cout << "Creating animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this)
                  << " via default constructor." << std::endl;
    }
    Animal(const Animal& animal)
    {
        std::cout << "Creating animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this)
                  << " via copy constructor." << std::endl;
    }

    Animal(Animal&& animal)
    {
        std::cout << "Creating animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this)
                  << " via move constructor." << std::endl;
    }

    Animal& operator=(const Animal& animal)
    {
        std::cout << "Copy assigning animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
        return *this;
    }

    Animal& operator=(Animal&& animal)
    {
        std::cout << "Move assigning animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
        return *this;
    }
#endif

#if OMIT_VIRTUAL_DESTRUCTOR
#if SHOW_ANIMAL_INSTANCE_LIFE_CYCLE
    ~Animal()
    {
        std::cout << "Destroying animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
    }
#else
    ~Animal() = default;
#endif
#else
#if SHOW_ANIMAL_INSTANCE_LIFE_CYCLE
    virtual ~Animal()
    {
        std::cout << "Destroying animal instance " << std::hex
                  << reinterpret_cast<std::uintptr_t>(this) << "." << std::endl;
    }
#else
    virtual ~Animal() = default;
#endif
#endif

    // Use Non-virtual inheritance pattern
    std::string describe() const
    {
        return describe_impl();
    }

    std::string make_sound() const
    {
        return make_sound_impl();
    }

    std::string provide_detailed_description() const
    {
        return provide_detailed_description_impl();
    }

protected:
    virtual std::string describe_impl() const = 0;
    virtual std::string make_sound_impl() const = 0;

    virtual std::string provide_detailed_description_impl() const
    {
        std::string description{};
        description.append({});
        return "Detailed description:\n\n"s + describe_impl() + "\n\n"s +
               "The sound it makes is "s + make_sound_impl() + "\n"s;
    }
};
