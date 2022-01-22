#pragma once
#include <iostream>
#include "Animal.cpp"

using namespace std;
using namespace animal;

namespace flying {
    class Flying : protected virtual Animal {
    private:
        int speed_of_flight;

    public:
        Flying(string name, int weight, string country, int speed_of_flight) : Animal(name, weight, country) {
            this->speed_of_flight = speed_of_flight;
        }
        virtual int getSpeedOfFlight() {
            return speed_of_flight;
        }

        virtual void sound() override {
            cout << "Звук крыльев" << endl;
        }

        virtual void PrintFlying(Flying* flying) {
            cout << "1.Название: " << flying->getName() << endl;
            cout << "2.Вес:  " << flying->getWeight() << endl;
            cout << "3.Страна: " << flying->getCountry() << endl;
            cout << "4.Скорость полёта: " << flying->getSpeedOfFlight() << endl;
            cout << endl;
        }

    };
}