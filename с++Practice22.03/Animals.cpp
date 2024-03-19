  // Copyright 2024 Matvey Pavlov

#include"Animals.h"



Animal::Animal(Animal&& animal) :mass(animal.GetMass()),
sex(animal.GetSex()), color(animal.GetColor()),
age(animal.GetAge()), name(animal.GetName()) {
    animal.name = nullptr;
    animal.sex = nullptr;
    animal.SetAge(-1);
    animal.SetMass(0);
    animal.SetColor(std::string());
}
Animal::Animal(const Animal& animal) :
               mass(animal.GetMass()),
               color(animal.GetColor()),
age(animal.GetAge()) {
    SetSex(animal.GetSex());
    SetName(animal.GetName());
}

Animal::Animal(const char* name_animal,
    const float& mass_animal,
    const char* sex_animal,
    const std::string& color_animal,
    const int& age_animal): mass(mass_animal),
    color(color_animal), age(age_animal) {
    sex = nullptr;
    name = nullptr;
    SetSex(sex_animal);

    SetName(name_animal);
}

Animal::~Animal() {
    delete[] sex;
    delete[] name;
    age = -1;
    mass = 0;
    sex = nullptr;
    name = nullptr;
}

Animal& Animal::operator=(const Animal& animal) {
    if (this == &animal) return *this;
    mass = animal.GetMass();
    SetSex(animal.GetSex());
    color = animal.GetColor();
    age = animal.GetAge();
    return *this;
}
Animal& Animal::operator=(Animal&& animal) {
    if (this == &animal) return *this;
    mass = animal.mass;
    animal.mass = 0;
    sex = animal.sex;
    animal.sex = nullptr;
    color = animal.color;
    animal.color.clear();
    age = animal.age;
    animal.age = 0;
    name = animal.name;
    animal.name = nullptr;
    return *this;
}
char* Animal::GetName() const {
    if (name == nullptr) return ( char * ) & kNullChar;
    return name;
}
char* Animal::GetSex() const {
    if (sex == nullptr) return ( char *) & kNullChar;
    return sex;
}
void Animal::SetSex(const char* sex_animal) {
    delete[] sex;
    if (sex_animal == nullptr) {
        sex = nullptr;
        return;
    }
    int len = strlen(sex_animal) + 1;
    sex = new char[len];
    strcpy_s(sex, len, sex_animal);
}
void Animal::SetName(const char* animal_name) {
    delete[]name;
    if (animal_name == nullptr) {
        name = nullptr;
        return;
    }
    int len = strlen(animal_name) + 1;
    name = new char[len];
    strcpy_s(name, len, animal_name);
}
Dog::Dog(
    const char* name_dog,
    const float& mass_animal,
    const char* sex_animal,
    const std::string& color_animal,
    const int& age_animal,
    const Breed& race_dog) :
    Animal(name_dog, mass_animal, sex_animal, color_animal, age_animal),
    race(race_dog) {}

Dog::Dog(Dog&& dog): Animal(std::move(dog)), race(dog.race) {
    dog.SetRace(Breed::kNone);
}
Dog::Dog(const Dog& dog) :Animal(dog), race(dog.race) {}

void Dog::WhatDoesSay() const {
    std::cout << "собака говорит: \" гав \"" << std::endl;
}
Dog::~Dog() {}

const char* Dog::GetRace() const {
    switch (race) {
    case Breed::kBulldog: {
        return "Bulldog";
    }
    case Breed::kBeagle: {
        return "Beagle";
    }
    case Breed::kDaschund: {
        return "Daschund";
    }
    case Breed::kDobermanPinscher: {
        return "Doberman Pinscher";
    }
    case Breed::kGermanShepherd: {
        return "German Shepherd";
    }
    case Breed::kGoldenRetriever: {
        return "Golden Retriever";
    }
    case Breed::kJackRussellTerrier: {
        return "Jack Russell Terrier";
    }
    case Breed::kLabradorRetriever: {
        return "Labrador Retriever";
    }
    case Breed::kNone: {
        return "none";
    }
    }
}



Dog& Dog::operator=(Dog&& dog) {
    if (this == &dog) return *this;
    Animal::operator=(std::move(dog));
    race = dog.race;
    dog.SetRace(Breed::kNone);
    return *this;
}
Dog& Dog::operator=(const Dog& dog) {
    Animal::operator=(dog);

    race = dog.race;
    return *this;
}

Fox::Fox(const char* name_fox, const float& mass_animal,
    const char* sex_animal,
    const std::string& color_animal,
    const int& age_animal,
    const TypeFox& type_fox,
    const int& set_number_rabbits_eaten):
    Animal(name_fox, mass_animal, sex_animal, color_animal,
    age_animal), type(type_fox),
    number_rabbits_eaten(set_number_rabbits_eaten) {}
Fox::Fox(Fox&& fox): Animal(std::move(fox)), type(fox.type),
                     number_rabbits_eaten(std::move(
                     fox.number_rabbits_eaten)) {
    fox.SetType(TypeFox::kNone);
}
Fox::Fox(const Fox& fox) : Animal(fox), type(fox.type),
                           number_rabbits_eaten(
                           fox.number_rabbits_eaten) {}
Fox::~Fox() {}

void Fox::WhatDoesSay() const {
    switch (type) {
    case TypeFox::kRed:
        std::cout << "Ring-ding-ding-ding-dingeringeding!" << std::endl;
        break;
    case TypeFox::kBlack:
        std::cout << "Gering-ding-ding-ding-dingeringeding!" << std::endl;
        break;
    case TypeFox::kYellow:
        std::cout << "Wa-pa-pa-pa-pa-pa-pow!" << std::endl;
        break;
    case TypeFox::kWhite:
        std::cout << "Hatee-hatee-hatee-ho!" << std::endl;
        break;
    case TypeFox::kBrown:
        std::cout << "Joff-tchoff-tchoffo-tchoffo-tchoff!" << std::endl;
        break;
    case TypeFox::kNone:
        std::cout << "Jacha-chacha-chacha-chow!" << std::endl;
        break;
    default:
        break;
    }
}
const char* Fox::GetType() const {
    switch (type) {
    case TypeFox::kRed:
        return "Red";
        break;
    case TypeFox::kBlack:
        return "Black";
        break;
    case TypeFox::kYellow:
        return "Yellow";
        break;
    case TypeFox::kWhite:
        return "White";
        break;
    case TypeFox::kBrown:
        return "Brown";
        break;
    case TypeFox::kNone:
        return "None";
        break;
    default:
        break;
    }
}

Fox& Fox::operator=(Fox&& fox) {
    if (this == &fox) return *this;
    Animal::operator=(std::move(fox));
    number_rabbits_eaten = std::move(fox.number_rabbits_eaten);
    type = fox.type;
    fox.type = TypeFox::kNone;
    return *this;
}
Fox& Fox::operator=(const Fox& fox) {
    if (this == &fox) return *this;
    Animal::operator=(fox);
    number_rabbits_eaten = fox.number_rabbits_eaten;
    type = fox.type;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const TypeFox& fox) {
    switch (fox) {
    case TypeFox::kRed:
        os << "Red";
        break;
    case TypeFox::kBlack:
        os << "Black";
        break;
    case TypeFox::kYellow:
        os << "Yellow";
        break;
    case TypeFox::kWhite:
        os << "White";
        break;
    case TypeFox::kBrown:
        os << "Brown";
        break;
    case TypeFox::kNone:
        os << "None";
        break;
    default:
        break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, Breed& dog) {
    switch (dog) {
    case Breed::kNone:
        os << "None";
        break;
    case Breed::kGermanShepherd:
        os << "German Shepherd";
        break;
    case Breed::kGoldenRetriever:
        os << "Golden Retriever";
        break;
    case Breed::kBeagle:
        os << "Beagle";
        break;
    case Breed::kDobermanPinscher:
        os << "Doberman Pinscher";
        break;
    case Breed::kPoodle:
        os << "Poodle";
        break;
    case Breed::kDaschund:
        os << "Daschund";
        break;
    case Breed::kLabradorRetriever:
        os << "Labrador Retriever";
        break;
    case Breed::kRottweiler:
        os << "Rottweiler";
        break;
    case Breed::kBulldog:
        os << "Bulldog";
        break;
    case Breed::kJackRussellTerrier:
        os << "Jack Russell Terrier";
        break;
    case Breed::kOther:
        os << "Other";
        break;
    default:
        break;
    }
    return os;
}
