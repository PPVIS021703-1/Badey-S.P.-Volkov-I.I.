#pragma once
#include <iostream>
#include "Animal.cpp"

using namespace std;
using namespace animal;

namespace walking {
    class Walking :protected virtual Animal {
    private:
        int speed;
    public:

        Walking(string name, int weight, string country, int speed) : Animal(name, weight, country) {
            this->speed = speed;
        }

        virtual int getSpeed() {
            return speed;
        }

        virtual void sound() override {
            cout << "Я ходящее животное" << endl;
        }

        virtual void PrintWalking(Walking* walking) {
            cout << "1.Имя: " << walking->getName() << endl;
            cout << "2.Вес:  " << walking->getWeight() << endl;
            cout << "3.Страна: " << walking->getCountry() << endl;
            cout << "4.Скорость бега: " << walking->getSpeed() << endl;
            cout << endl;
        };
    };
}