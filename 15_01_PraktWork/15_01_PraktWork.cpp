#include <iostream>
using namespace std;

/*
Завдання 1:
Створіть клас Shape який містить загальні параметри
будь-якої фігури (ім,я, тип і тд). Визначте віртуальні методи:
•Show – вивід на екран інформації про фігуру; •Show
•GetArea – обчислення площі фігури; (•GetArea)

Визначте похідні класи: прямокутник, коло, прямокутний трикутник,трикутник,
трапеція зі своїми функціями площі. – кожний з яких буде
містити притаманні даній фігурі характеристики та перевизначати (override)
алгоритми методів базового класу Shape.
Також створити функцію TestShape, яка приймає фігуру та відображає її
інформацію включаючи площу.
В main протестувати роботу, передавши в функцію різні фігури.
*/

class Shape {
protected:
    string name;
    string type;
public:
    Shape(): name("No name"), type("No type") {}
    Shape(string n, string t) : name(n), type(t) {}

    virtual void show()const {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
    }
    virtual void getArea()const {
        cout << "Area of shape: " << endl;
    }
};

class quadrangle : public Shape {
private:
    double width;
    double height;
public:
    quadrangle(double w, double h) : width(w), height(h) {}

    void show()const override {
        cout << "Quadrangle with width: " << width << " and height: " << height << endl;
    }
    void getArea()const override {
        cout << "Area of quadrangle: " << width * height << endl;
    }
};
class circle : public Shape {
private:
    double radius;
public:
    circle(double r) : radius(r) {}
    void show()const override {
        cout << "Circle with radius: " << radius << endl;
    }
    void getArea()const override {
        cout << "Area of circle: " << 3.14 * radius * radius << endl;
    }
};
class triangle : public Shape {
private:
    double base;
    double height;
public:
    triangle(double b, double h) : base(b), height(h) {}
    void show()const override{
        cout << "Triangle with base: " << base << " and height: " << height << endl;
    }
    void getArea()const override{
        cout << "Area of triangle: " << 0.5 * base * height << endl;
    }
};
class quadTriangle : public Shape {
private:
    double base;
    double height;
public:
    quadTriangle(double b, double h) : base(b), height(h) {}
    void show()const override{
        cout << "Quadrangular triangle with base: " << base << " and height: " << height << endl;
    }
    void getArea()const override{
        cout << "Area of quadrangular triangle: " << 0.5 * base * height << endl;
    }
};
class trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;
public:
    trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

    void show()const override{
        cout << "Trapezoid with bases: " << base1 << " and " << base2 << " and height: " << height << endl;
    }
    void getArea()const override{
        cout << "Area of trapezoid: " << 0.5 * (base1 + base2) * height << endl;
    }
};

void testShape(const Shape& shape) {
    shape.show();
    shape.getArea();
    cout << '\n';
}


int main()
{
    cout << "Hello World!\n";
    
    quadrangle q(5, 10);
    circle c(5);
    triangle t(5, 10);
    quadTriangle qt(5, 10);
    trapezoid tr(5, 10, 8);

    testShape(q);
    testShape(c);
    testShape(t);
    testShape(qt);
    testShape(tr);

    cout << "Bye bye!\n";
}