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


int main() {
    Employer* employees[3];

    President president;
    Manager manager;
    Worker worker;

    employees[0] = &president;
    employees[1] = &manager;
    employees[2] = &worker;

    for (int i = 0; i < 3; i++) {
        employees[i]->Print();
        cout << "------------------" << endl;
    }

    return 0;
}