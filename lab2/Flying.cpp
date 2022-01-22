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
            cout << "���� �������" << endl;
        }

        virtual void PrintFlying(Flying* flying) {
            cout << "1.��������: " << flying->getName() << endl;
            cout << "2.���:  " << flying->getWeight() << endl;
            cout << "3.������: " << flying->getCountry() << endl;
            cout << "4.�������� �����: " << flying->getSpeedOfFlight() << endl;
            cout << endl;
        }

    };
}