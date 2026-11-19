#include <iostream>
#include <string>
using namespace std;

/*
Завдання N 1
Створити базовий клас Employer (служ-
бовець) з чисто віртуальною функцією Print (). Створіть
три похідних класи: President, Manager, Worker. Переви-
значите функцію Print() для виведення інформації, що
відповідає кожному типу службовця.
Завдання N 2
Створити базовий клас «Транспортний
засіб» і похідні класи «Автомобіль», «Велосипед», «Віз».
Підрахувати час і вартість перевезення пасажирів і
вантажів кожним транспортним засобом.
*/

// -=-=-=-=-=- ЗАВДАННЯ №1 -=-=-=-=-=-

class Employer {
public:
    virtual void Print() = 0;
    virtual ~Employer() {}
};

class President : public Employer {
public:
    void Print() override {
        cout << "Посада: Президент" << endl;
        cout << "Керує всією компанією." << endl;
    }
};
class Manager : public Employer {
public:
    void Print() override {
        cout << "Посада: Менеджер" << endl;
        cout << "Керує відділом та працівниками." << endl;
    }
};
class Worker : public Employer {
public:
    void Print() override {
        cout << "Посада: Працівник" << endl;
        cout << "Виконує робочі завдання." << endl;
    }
};


// -=-=-=-=-=- ЗАВДАННЯ №2 -=-=-=-=-=-

class Transport {
protected:
    double speed;
    double price;

public:
    Transport(double s, double p) {
        speed = s;
        price = p;
    }

    virtual void Calculate(double distance) = 0;

    virtual ~Transport() {}
};

class Car : public Transport {
public:
    Car() : Transport(80, 15) {}

    void Calculate(double distance) override {
        cout << "Автомобіль:" << endl;
        cout << "Час: " << distance / speed << " год." << endl;
        cout << "Вартість: " << distance * price << " грн." << endl;
    }
};
class Bicycle : public Transport {
public:
    Bicycle() : Transport(15, 0) {}

    void Calculate(double distance) override {
        cout << "Велосипед:" << endl;
        cout << "Час: " << distance / speed << " год." << endl;
        cout << "Вартість: " << distance * price << " грн." << endl;
    }
};
class Cart : public Transport {
public:
    Cart() : Transport(5, 5) {}

    void Calculate(double distance) override {
        cout << "Віз:" << endl;
        cout << "Час: " << distance / speed << " год." << endl;
        cout << "Вартість: " << distance * price << " грн." << endl;
    }
};


int main() {
    setlocale(LC_ALL, "ukr");

    // -=-=-=-=-=- Завдання №1 -=-=-=-=-=-
    cout << "-=-=-=-=-=- ЗАВДАННЯ №1 -=-=-=-=-=-" << endl;

    President president;
    Manager manager;
    Worker worker;

    Employer* employees[3] = {
        &president, &manager, &worker
    };

    for (int i = 0; i < 3; i++) {
        employees[i]->Print();
        cout << "-=-=-=-=-=-=-=-=-=-" << endl;
    }

    // -=-=-=-=-=- Завдання №2 -=-=-=-=-=-
    cout << "\n-=-=-=-=-=- ЗАВДАННЯ №2 -=-=-=-=-=-" << endl;

    double distance;

    cout << "Введіть відстань (км): ";
    cin >> distance;

    Car car;
    Bicycle bicycle;
    Cart cart;

    Transport* transports[3] = {
        &car, &bicycle, &cart
    };

    for (int i = 0; i < 3; i++) {
        transports[i]->Calculate(distance);
        cout << "-=-=-=-=-=-=-=-=-=-" << endl;
    }
}