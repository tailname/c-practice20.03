  // Copyright 2024 Matvey Pavlov

#pragma once
#include<string>
#include<iostream>
#include<cstring>
#include <utility>

class Animal {
 protected:
    float  mass;
    char* sex;
    std::string color;
    int age;
    char* name;
    char kNullChar = '\0';

 public:
    Animal(const char* name_animal = nullptr, const float& mass_animal = 0,
           const char* sex_animal = nullptr,
            const std::string& color_animal = std::string(),
           const int& age_animal = -1);

    Animal(Animal&& animal);
    Animal(const Animal& animal);
    virtual ~Animal();
    Animal& operator=(const Animal& animal);
    Animal& operator=(Animal&& animal);

    float  GetMass() const { return mass; }
    char* GetSex() const;
    char* GetColor() const { return ( char  * )(color.data()); }
    int GetAge() const { return age; }
    char* GetName() const;


    void  SetMass(const float& animal_mass) { mass = animal_mass; }
    void SetSex(const char* sex_animal);
    void SetColor(const std::string& animal_color) { color = animal_color; }
    void SetColor(const char* animal_color) { color = animal_color; }
    void SetAge(const int& animal_age) { age = animal_age; }
    void SetName(const char* animal_name);
    virtual void WhatDoesSay() const = 0;
};

enum class Breed{ kNone, kGermanShepherd, kGoldenRetriever, kBeagle,
                  kDobermanPinscher, kPoodle, kDaschund,
                  kLabradorRetriever, kRottweiler, kBulldog,
                  kJackRussellTerrier, kOther };

class Dog : public Animal {
 protected:
    Breed race;

 public:
    Dog(const char* name_dog = nullptr,
        const float& mass_animal = 0,
        const char* sex_animal = nullptr,
        const std::string& color_animal = std::string(),
        const int& age_animal = -1,
        const Breed& race_dog = Breed::kNone);
    Dog(Dog&& dog);
    Dog(const Dog& dog);
    ~Dog();
    void WhatDoesSay() const override;


    const char* GetRace() const;
    void SetRace(const Breed& race_dog) { race = race_dog; }

    Dog& operator=(Dog&& dog);
    Dog& operator=(const Dog& dog);
};

enum class TypeFox { kRed, kBlack, kYellow, kWhite, kBrown, kNone};


class Fox : public Animal {
 protected:
    TypeFox type;
    int number_rabbits_eaten;

 public:
    Fox(const char* name_fox = nullptr,
        const float& mass_animal = 0,
        const char* sex_animal = nullptr,
        const std::string& color_animal = std::string(),
        const int& age_animal = -1,
        const TypeFox& type_fox = TypeFox::kNone,
        const int& set_number_rabbits_eaten = 0);
    Fox(Fox&& fox);
    Fox(const Fox& fox);
    ~Fox();
    void WhatDoesSay() const override;
    void Eat() {++number_rabbits_eaten;}

    const char* GetType() const;
    int GetNumberRabbitsEaten() { return number_rabbits_eaten; }

    void SetType(const TypeFox& type_fox) { type = type_fox; }
    int SetNumberRabbitsEaten(const int& set_number_rabbits_eaten)
    { number_rabbits_eaten = set_number_rabbits_eaten; }

    Fox& operator=(Fox&& fox);
    Fox& operator=(const Fox& fox);
};
