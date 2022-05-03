#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdelete-abstract-non-virtual-dtor"
#endif

#define OMIT_VIRTUAL_DESTRUCTOR 0
#define SHOW_ANIMAL_INSTANCE_LIFE_CYCLE 1

#include <iostream>
#include <memory>
#include <string>

#include "animal.h"
#include "animal_with_switch.h"
#include "cat.h"
#include "dog.h"

void describe_animal(AnimalWithSwitch animal)
{
    std::cout << "Describing an animal.\n";
    std::cout << animal.describe() << std::endl;
    std::cout << animal.make_sound() << std::endl;
    std::cout << animal.provide_detailed_description() << std::endl;
}

void describe_animal(const Animal* animal)
{
    std::cout << "Describing an animal.\n";
    std::cout << animal->describe() << std::endl;
    std::cout << animal->make_sound() << std::endl;
    std::cout << animal->provide_detailed_description() << std::endl;
}

int main()
{
    std::cout << "AnimalWithSwitch animal_with_switch{Dog}====================="
              << std::endl;
    AnimalWithSwitch animal_with_switch{AnimalType::Dog};
    describe_animal(animal_with_switch);

    std::cout << "animal_with_switch = AnimalWithSwitch{AnimalType::Cat}======="
              << std::endl;
    animal_with_switch = AnimalWithSwitch{AnimalType::Cat};
    describe_animal(animal_with_switch);


    std::cout << "Dog fluffy{} ================================================"
              << std::endl;
    const Dog fluffy{};
    std::cout << fluffy.describe() << std::endl;
    std::cout << fluffy.make_sound() << std::endl;
    std::cout << fluffy.provide_detailed_description() << std::endl;

    std::cout << "Cat garfield{} =============================================="
              << std::endl;
    const Cat garfield{};
    std::cout << garfield.describe() << std::endl;
    std::cout << garfield.make_sound() << std::endl;
    std::cout << garfield.provide_detailed_description() << std::endl;

    std::cout << "Animal* animal{new Dog} ====================================="
              << std::endl;
    const Animal* animal{new Dog};
    describe_animal(animal);
    delete animal;

    std::cout << "animal = new Cat ============================================"
              << std::endl;
    animal = new Cat;
    describe_animal(animal);
    delete animal;

    std::cout << "std::unique_ptr<Animal> smart_animal{std::make_unique<Dog>()}"
              << std::endl;
    std::unique_ptr<const Animal> smart_animal{std::make_unique<Dog>()};
    describe_animal(smart_animal.get());

    std::cout << "smart_animal = std::make_unique<Cat>() ======================"
              << std::endl;
    smart_animal = std::make_unique<Cat>();
    describe_animal(smart_animal.get());
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
