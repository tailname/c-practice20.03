  //  Copyright 2024 Matvey Pavlov


#include <iostream>
#include"Animals.h"

int main() {
    setlocale(LC_ALL, "RU");
    Dog();
    Fox();
    std::cout << "Проверка Конструктора инициализации для Dog" << std::endl;
    Dog first("Bobic", 70.0, "male", "white-gray", 6, Breed::kBeagle);
    std::cout << first.GetName() << std::endl;
    std::cout << first.GetMass() << std::endl;
    std::cout << first.GetSex() << std::endl;
    std::cout << first.GetColor() << std::endl;
    std::cout << first.GetAge() << std::endl;
    std::cout << first.GetRace() << std::endl;
    first.WhatDoesSay();

    std::cout << std::endl << std::endl;
    std::cout << "Проверка сетеров и гетеров для Dog" << std::endl;
    first.SetName("Bobik");
    first.SetMass(4);
    first.SetSex("male");
    first.SetColor("green");
    first.SetAge(12);
    first.SetRace(Breed::kBulldog);
    std::cout << first.GetName() << std::endl;
    std::cout << first.GetMass() << std::endl;
    std::cout << first.GetSex() << std::endl;
    std::cout << first.GetColor() << std::endl;
    std::cout << first.GetAge() << std::endl;
    std::cout << first.GetRace() << std::endl;
    first.WhatDoesSay();
    std::cout << std::endl << std::endl;

    std::cout << "Конструктор инициализации для Fox" << std::endl;
    Fox third("Bublic", 23, "male", "gray", 4, TypeFox::kBrown, 0);
    std::cout << third.GetName() << std::endl;
    std::cout << third.GetMass() << std::endl;
    std::cout << third.GetSex() << std::endl;
    std::cout << third.GetColor() << std::endl;
    std::cout << third.GetAge() << std::endl;
    std::cout << third.GetNumberRabbitsEaten() << std::endl;
    std::cout << third.GetType() << std::endl;
    third.WhatDoesSay();
    third.Eat();
    std::cout << third.GetNumberRabbitsEaten() << std::endl;
    std::cout << std::endl << std::endl;


    std::cout << "Проверка сетеров и гетеров для Fox" << std::endl;
    Fox second;
    second.SetName("Pirojok");
    second.SetMass(20);
    second.SetSex("male");
    second.SetColor("black AND white");
    second.SetAge(6);
    second.SetType(TypeFox::kRed);
    std::cout << second.GetName() << std::endl;
    std::cout << second.GetMass() << std::endl;
    std::cout << second.GetSex() << std::endl;
    std::cout << second.GetColor() << std::endl;
    std::cout << second.GetAge() << std::endl;
    std::cout << second.GetNumberRabbitsEaten() << std::endl;
    std::cout << second.GetType() << std::endl;
    second.WhatDoesSay();
    second.Eat();
    second.Eat();
    second.Eat();
    std::cout << second.GetNumberRabbitsEaten() << std::endl;
    std::cout << std::endl << std::endl;




    std::cout << "Конструктор копирования для Dog" << std::endl;
    Dog fourth(first);
    std::cout << fourth.GetName() << std::endl;
    std::cout << fourth.GetMass() << std::endl;
    std::cout << fourth.GetSex() << std::endl;
    std::cout << fourth.GetColor() << std::endl;
    std::cout << fourth.GetAge() << std::endl;
    std::cout << fourth.GetRace() << std::endl;
    fourth.WhatDoesSay();
    std::cout << std::endl << std::endl;

    std::cout << "Конструктор копирования для Fox" << std::endl;
    Fox fifth(second);
    std::cout << fifth.GetName() << std::endl;
    std::cout << fifth.GetMass() << std::endl;
    std::cout << fifth.GetSex() << std::endl;
    std::cout << fifth.GetColor() << std::endl;
    std::cout << fifth.GetAge() << std::endl;
    std::cout << fifth.GetNumberRabbitsEaten() << std::endl;
    std::cout << second.GetType() << std::endl;
    fifth.WhatDoesSay();
    fifth.Eat();
    fifth.Eat();
    fifth.Eat();
    std::cout << fifth.GetNumberRabbitsEaten() << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Оператор копирования для Fox" << std::endl;
    Fox six = third;
    std::cout << six.GetName() << std::endl;
    std::cout << six.GetMass() << std::endl;
    std::cout << six.GetSex() << std::endl;
    std::cout << six.GetColor() << std::endl;
    std::cout << six.GetAge() << std::endl;
    std::cout << six.GetNumberRabbitsEaten() << std::endl;
    std::cout << six.GetType() << std::endl;
    six.WhatDoesSay();
    six.Eat();
    std::cout << six.GetNumberRabbitsEaten() << std::endl;
    std::cout << std::endl << std::endl;



    std::cout << "Оператор копирования для Dog" << std::endl;
    Dog seven("", 2, "male", "green", 5, Breed::kBulldog);
    Dog eight = seven;
    std::cout << eight.GetName() << std::endl;
    std::cout << eight.GetMass() << std::endl;
    std::cout << eight.GetSex() << std::endl;
    std::cout << eight.GetColor() << std::endl;
    std::cout << eight.GetAge() << std::endl;
    std::cout << eight.GetRace() << std::endl;
    eight.WhatDoesSay();
    std::cout << std::endl << std::endl;


    std::cout << "Конструктор перемещения для Dog" << std::endl;
    Dog helpful("", 12, "male", "yellow", 8, Breed::kGoldenRetriever);
    Dog nine = std::move(helpful);
    std::cout << nine.GetName() << std::endl;
    std::cout << nine.GetMass() << std::endl;
    std::cout << nine.GetSex() << std::endl;
    std::cout << nine.GetColor() << std::endl;
    std::cout << nine.GetAge() << std::endl;

    std::cout << nine.GetRace() << std::endl;
    nine.WhatDoesSay();
    std::cout << std::endl << std::endl;


    std::cout << "Конструктор перемещения для Fox" << std::endl;
    Fox ten("", 14, "female", "Red", 1, TypeFox::kYellow, 112);
    Fox eleven = std::move(ten);
    std::cout << eleven.GetName() << std::endl;
    std::cout << eleven.GetMass() << std::endl;
    std::cout << eleven.GetSex() << std::endl;
    std::cout << eleven.GetColor() << std::endl;
    std::cout << eleven.GetAge() << std::endl;
    std::cout << eleven.GetNumberRabbitsEaten() << std::endl;
    std::cout << eleven.GetType() << std::endl;
    eleven.WhatDoesSay();
    eleven.Eat();
    std::cout << eleven.GetNumberRabbitsEaten() << std::endl;
    std::cout << std::endl << std::endl;


    std::cout << "оператор перемещение для Dog" << std::endl;
    Dog move_dog;
    move_dog = std::move(helpful);
    std::cout << move_dog.GetName() << std::endl;
    std::cout << move_dog.GetMass() << std::endl;
    std::cout << move_dog.GetSex() << std::endl;
    std::cout << move_dog.GetColor() << std::endl;
    std::cout << move_dog.GetAge() << std::endl;
    std::cout << move_dog.GetRace() << std::endl;
    move_dog.WhatDoesSay();
    std::cout << std::endl << std::endl;


    std::cout << "оператор перемещение для Fox" << std::endl;

    Fox move_fox;
    move_fox = std::move(eleven);
    std::cout << move_fox.GetName() << std::endl;
    std::cout << move_fox.GetMass() << std::endl;
    std::cout << move_fox.GetSex() << std::endl;
    std::cout << move_fox.GetColor() << std::endl;
    std::cout << move_fox.GetAge() << std::endl;
    std::cout << move_fox.GetNumberRabbitsEaten() << std::endl;
    std::cout << move_fox.GetType() << std::endl;
    move_fox.WhatDoesSay();
    move_fox.Eat();
    std::cout << move_fox.GetNumberRabbitsEaten() << std::endl;
    std::cout << std::endl << std::endl;
    return 0;
}
