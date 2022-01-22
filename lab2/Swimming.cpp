#pragma once
#include "Animal.cpp"

using namespace std;
using namespace animal;

namespace swimming {
    class Swimming : private Animal {
    private:
        int time_without_oxygen;

    public:
        Swimming(string name, int weight, string country, int time_without_oxygen) : Animal(name, weight, country) {
            this->time_without_oxygen = time_without_oxygen;
        }
        virtual int getTimeWithoutOxygen() {
            return time_without_oxygen;
        }

        virtual void PrintSwimming(Swimming* swimming) {
            cout << "1.Имя: " << swimming->getName() << endl;
            cout << "2.Вес:  " << swimming->getWeight() << endl;
            cout << "3.Страна: " << swimming->getCountry() << endl;
            cout << "4.Может пробыть без кислорода: " << swimming->getTimeWithoutOxygen() << endl;
            cout << endl;
        }
    };
}