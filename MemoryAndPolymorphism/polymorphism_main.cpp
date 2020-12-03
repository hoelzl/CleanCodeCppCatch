#define OMIT_VIRTUAL_DESTRUCTOR 1
#define SHOW_ANIMAL_INSTANCE_LIFE_CYCLE 1

#include "animal.h"
#include "dog.h"
#include "cat.h"

#include <iostream>
#include <memory>
#include <string>

void describe_animal(const Animal* animal)
{
    std::cout << "Describing an animal.\n";
    std::cout << animal->describe() << std::endl;
    std::cout << animal->make_sound() << std::endl;
    std::cout << animal->provide_detailed_description() << std::endl;
}

int main()
{
    Dog fluffy{};
    std::cout << fluffy.describe() << std::endl;
    std::cout << fluffy.make_sound() << std::endl;
    std::cout << fluffy.provide_detailed_description() << std::endl;

    Cat garfield{};
    std::cout << garfield.describe() << std::endl;
    std::cout << garfield.make_sound() << std::endl;
    std::cout << garfield.provide_detailed_description() << std::endl;

    Animal* animal{new Dog};
    describe_animal(animal);
    delete animal;

    animal = new Cat;
    describe_animal(animal);
    delete animal;

    std::unique_ptr<Animal> smart_animal{std::make_unique<Dog>()};
    describe_animal(smart_animal.get());
    smart_animal = std::make_unique<Cat>();
    describe_animal(smart_animal.get());
}