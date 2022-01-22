#include <iostream>

#include <string>
#include "Walking.cpp"
#include "Flying.cpp"
#include "Animal.cpp"
#include "Swimming.cpp"


using namespace std;
using namespace walking;
using namespace flying;
using namespace swimming;


class Squirrel : public Walking {
public:
    Squirrel(string name, int weight, string country, int speed) : Walking (name, weight, country, speed) {}
    void sound() override
    {
        cout << "Я умею ходить, я белка" << endl;
    }
};

class Parrot : public Flying {
public:
    Parrot(string name, int weight, string country, int speed_of_flight) : Flying(name, weight, country, speed_of_flight) 
    {
    }

    void sound() override
    {
        cout << "Я умею летать, я попугай!" << endl;
    }
};

class Fish : public Swimming {
public:
    Fish(string name, int weight, string country, int time_under_water) : Swimming(name, weight, country, time_under_water) 
    {
    }

    void sound() override
    {
        cout << "Я умею плавать, я рыба!" << endl;
    }
};

class Penguin : public Walking, public Swimming {
public:
    Penguin(string name, int weight, string country, int time_without_oxygen, int speed) : Walking(name, weight, country, speed), Swimming(name, weight, country, time_without_oxygen) 
    {
    }

    void PrintPenguin() {
        cout << "1.Имя: " << Walking::getName() << endl;
        cout << "2.Вес:  " << Walking::getWeight() << endl;
        cout << "3.Страна: " << Walking::getCountry() << endl;
        cout << "4.Скорость бега: " << Walking::getSpeed() << endl;
        cout << "5.Может пробыть без кислорода: " << Swimming::getTimeWithoutOxygen() << endl;
        cout << endl;
    }
    void sound() override
    {
        cout << "Я умею ходить и летать, я пингвин!" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    int n;

    Squirrel  squirrel("Белка", 3, "Беларусь", 5);
    Parrot parrot("Попугай", 5, "Бразилия", 30);
    Fish fish("Рыба", 3, "Океан", 8);
    Penguin penguin("Пенгвин", 5, "Австралия", 5, 10);
    
    while (true) {

        cout << "Просмотр: " << endl;
        cout << "1.Белка" << endl;
        cout << "2.Попугай" << endl;
        cout << "3.Рыба" << endl;
        cout << "4.Пенгвин" << endl;
        
        cout << "5.Выход" << endl;

        cout << endl;

        cin >> n;
        
        cout << endl;
        
        switch (n) {
        case 1:

            squirrel.PrintWalking(&squirrel);
            cout << "Издаваемый звук: " << endl;
            squirrel.sound();
            cout << endl;
            break;

        case 2:

            parrot.PrintFlying(&parrot);
            cout << "Издаваемый звук: " << endl;
            parrot.sound();
            cout << endl;
            break;

        case 3:

            fish.PrintSwimming(&fish);
            cout << "Издаваемый звук: " << endl;
            fish.sound();
            cout << endl;
            break;

        case 4:

            penguin.PrintPenguin();
            cout << "Издаваемый звук: " << endl;
            penguin.sound();
            cout << endl;
            break;

        case 5:

            return 0;
            break;

        }

    }

    system("pause");
    return 0;
}