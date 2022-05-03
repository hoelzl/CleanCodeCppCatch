// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef ANIMAL_WITH_SWITCH_H
#define ANIMAL_WITH_SWITCH_H

#include <stdexcept>

enum class AnimalType
{
    Cat,
    Dog
};

class AnimalWithSwitch
{
private:
    AnimalType type{AnimalType::Cat};

public:
    explicit AnimalWithSwitch(AnimalType type = AnimalType::Cat) : type{type} {}

    [[nodiscard]] std::string describe() const
    {
        switch (type) {
        case AnimalType::Cat: return "A cat.";
        case AnimalType::Dog: return "A dog.";
        }
        throw std::domain_error{"Unknown animal type."};
    }

    [[nodiscard]] std::string make_sound() const
    {
        switch (type) {
        case AnimalType::Cat: return "[meow]";
        case AnimalType::Dog: return "[woof]";
        }
        throw std::domain_error{"Unknown animal type."};
    }
    
    [[nodiscard]] std::string provide_detailed_description() const
    {
        switch (type) {
        case AnimalType::Cat: return "A cat (detailed description).";
        case AnimalType::Dog: return "A dog (detailed description).";
        }
        throw std::domain_error{"Unknown animal type."};
    }

};


#endif // ANIMAL_WITH_SWITCH_H