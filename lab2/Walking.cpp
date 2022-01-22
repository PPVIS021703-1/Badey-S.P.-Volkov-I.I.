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
            cout << "� ������� ��������" << endl;
        }

        virtual void PrintWalking(Walking* walking) {
            cout << "1.���: " << walking->getName() << endl;
            cout << "2.���:  " << walking->getWeight() << endl;
            cout << "3.������: " << walking->getCountry() << endl;
            cout << "4.�������� ����: " << walking->getSpeed() << endl;
            cout << endl;
        };
    };
}