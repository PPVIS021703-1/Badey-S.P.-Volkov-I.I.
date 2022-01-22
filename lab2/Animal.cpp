#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace animal {
    class Animal
    {
    protected:

        string name;
        int weight;
        string country;

    public:

        Animal() 
        {
        }

        Animal(string name, int weight, string country)
        {
            this->name = name;
            this->weight = weight;
            this->country = country;
        }

        string getName() {
            return name;
        }
        int getWeight() {
            return weight;
        }
        string getCountry() {
            return country;
        }

        virtual void sound() = 0;
    };
}