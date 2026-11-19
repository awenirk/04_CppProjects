#include <iostream>
#include <string>
using namespace std;

/*
ТЕМА: AGGREGATION. COMPOSITION
Завдання 1:
Розробити клас Car з набором необхідних параметрів та складових
(двигун, кузов, колеса, двері, коробка передач, фари і тд.)
Кожна складова описується окремим класом та міститься як композиція в класі Car.
Набір необхідних характеристик та методів описати на ваш розсуд.
Завдання 2:
До попереднього завдання (створення класу Car з використанням композиції) додати агрегацію об'єкта:
Об'єктом буде клас Driver, який матиме наступні характеристики:
-	ім'я
-	прізвище
-	вік
-	стаж керування ТЗ (транспортний засіб)
Конструктор(и)
Методи:
-	Показ інформації про водія
Клас Car повинен мати можливість додавати собі водія методом агрегації, іншими словами, агрегувати водія.
В класі Car буде міститися вказівник на клас Driver та можливість додати його двома способами:
1.	Через параметр конструктора, разом зі всіма іншими даними авто (написати ще один перевантажений конструктор)
2.	Викликавши метод AddDriver та передавши адресу водія
Метод Show для авто повинен також виводити інформацію про водія, якщо він відсутній – відповідне повідомлення.
Протестувати роботу програми, створивши самостійний екземпляр класу Driver, після цього екземпляр класу Car.
Додати водія до створеного авто (якщо цього не було зроблено через конструктор)
та показати інформацію про автомобіль.
*/

enum TypeEngine { V4, V6, V8, V10, V12 };
enum TypeDoor { Outward, Forward };
enum TypeLights { HALOGEN, XENON, LED, LASER, MATRIX, DIGITAL };

class Engine {
    TypeEngine type;
    float value;
    int horsepower;
public:
    Engine(TypeEngine type, float value, int horsepower):
        type(type), value(value), horsepower(horsepower) {}
    void Show() {
        cout << "Engine: " << value << " L, "
            << horsepower << " HP, "
            << type << endl;
    }
};
class Body {
    string type;
    string color;
public:
    Body(string type, string color): type(type), color(color) {}
    void Show() {
        cout << "Body: " << type << ", "
            << color << endl;
    }
};
class Wheel {
    int width;
public:
    Wheel(int width): width(width) {}
    void Show() {
        cout << "Wheel: " << width << " mm" << endl;
    }
};
class Door {
    string color;
    TypeDoor Type;
public:
    Door(string color, TypeDoor Type): color(color), Type(Type) {}
    void Show() {
        cout << "Door: " << color << ", "
            << Type << endl;
    }
};
class Gearbox {
    string type;
    int value;
public:
    Gearbox(string type, int value): type(type), value(value) {}
    void Show() {
        cout << "Gearbox: " << type
            << ", gears: " << value << endl;
    }
};
class Lights {
    string color;
    TypeLights Type;
public:
    Lights(string color, TypeLights Type): color(color), Type(Type) {}
    void Show() {
        cout << "Lights: " << color << ", "
            << Type << endl;
    }
};
class Driver {
    string name;
    int age;
    string licenseId;
public:
    Driver(string name, int age, string licenseId):
        name(name), age(age), licenseId(licenseId) {}
    void Show() {
        cout << "Driver: " << name << ", "
            << age << " years, "
            << licenseId << endl;
    }
};

class Car {
    string brand;
    string model;
    int year;

    // Components
    Engine engine;
    Lights lights;
    Door door;
    Wheel wheel;
    Body body;
    Gearbox gearbox;

    Driver* driver;
public:
    Car(string brand, string model, int year, Engine engine,
        Lights lights, Door door, Wheel wheel,
        Body body, Gearbox gearbox) :
        brand(brand), model(model), year(year),
        engine(engine), lights(lights), door(door),
        wheel(wheel), body(body), gearbox(gearbox),
        driver(nullptr) {
    }
    Car(string brand, string model, int year, Engine engine,
        Lights lights, Door door, Wheel wheel,
        Body body, Gearbox gearbox, Driver* driver) :
        brand(brand), model(model), year(year),
        engine(engine), lights(lights), door(door),
        wheel(wheel), body(body), gearbox(gearbox),
        driver(driver) {
    }

    void AddDriver(Driver* driver) {
        this->driver = driver;
    }

    void Show() {
        cout << "Car: " << brand << " " << model << ", " << year << endl;
        engine.Show();
        lights.Show();
        door.Show();
        wheel.Show();
        body.Show();
        gearbox.Show();
        if (driver != nullptr) {
            driver->Show();
        }
        else cout << "Driver: not assigned" << endl;
    }
};


int main()
{
    Driver driver("Jimmy", 30, "B1234567");
    Engine engine(V6, 2.0, 300);
    Body body("Sedan", "Black");
    Wheel wheels(17);
    Door doors("Black", Forward);
    Gearbox gearbox("Manual", 6);
    Lights light("White", LED);

    Car car("BMW", "320i", 2022,
        engine, light, doors,
        wheels, body, gearbox);

    car.Show();
    cout << endl;
    car.AddDriver(&driver);
    cout << endl;
    car.Show();

}
