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
        cout << "� ���� ������, � �����" << endl;
    }
};

class Parrot : public Flying {
public:
    Parrot(string name, int weight, string country, int speed_of_flight) : Flying(name, weight, country, speed_of_flight) 
    {
    }

    void sound() override
    {
        cout << "� ���� ������, � �������!" << endl;
    }
};

class Fish : public Swimming {
public:
    Fish(string name, int weight, string country, int time_under_water) : Swimming(name, weight, country, time_under_water) 
    {
    }

    void sound() override
    {
        cout << "� ���� �������, � ����!" << endl;
    }
};

class Penguin : public Walking, public Swimming {
public:
    Penguin(string name, int weight, string country, int time_without_oxygen, int speed) : Walking(name, weight, country, speed), Swimming(name, weight, country, time_without_oxygen) 
    {
    }

    void PrintPenguin() {
        cout << "1.���: " << Walking::getName() << endl;
        cout << "2.���:  " << Walking::getWeight() << endl;
        cout << "3.������: " << Walking::getCountry() << endl;
        cout << "4.�������� ����: " << Walking::getSpeed() << endl;
        cout << "5.����� ������� ��� ���������: " << Swimming::getTimeWithoutOxygen() << endl;
        cout << endl;
    }
    void sound() override
    {
        cout << "� ���� ������ � ������, � �������!" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    int n;

    Squirrel  squirrel("�����", 3, "��������", 5);
    Parrot parrot("�������", 5, "��������", 30);
    Fish fish("����", 3, "�����", 8);
    Penguin penguin("�������", 5, "���������", 5, 10);
    
    while (true) {

        cout << "��������: " << endl;
        cout << "1.�����" << endl;
        cout << "2.�������" << endl;
        cout << "3.����" << endl;
        cout << "4.�������" << endl;
        
        cout << "5.�����" << endl;

        cout << endl;

        cin >> n;
        
        cout << endl;
        
        switch (n) {
        case 1:

            squirrel.PrintWalking(&squirrel);
            cout << "���������� ����: " << endl;
            squirrel.sound();
            cout << endl;
            break;

        case 2:

            parrot.PrintFlying(&parrot);
            cout << "���������� ����: " << endl;
            parrot.sound();
            cout << endl;
            break;

        case 3:

            fish.PrintSwimming(&fish);
            cout << "���������� ����: " << endl;
            fish.sound();
            cout << endl;
            break;

        case 4:

            penguin.PrintPenguin();
            cout << "���������� ����: " << endl;
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