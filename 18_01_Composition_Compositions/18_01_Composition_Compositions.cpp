#include <iostream>
using namespace std;


enum Type { None, Standart, XL, XXL };

class Cartrige {
    float volume;
    string color;
    Type type;
public:
    Cartrige(): volume(0), color("No color"), type(None) {}
    Cartrige(float v, string c, Type t): volume(v), color(c), type(t) {}
    void ShowInfo()const {
        cout << "Volume: " << volume << '\n';
        cout << "Color: " << color << '\n';
        cout << "Type: ";

        switch (type) {
        case None: cout << "None"; break;
        case Standart: cout << "Standart"; break;
        case XL: cout << "XL"; break;
        case XXL: cout << "XXL"; break;
        default: break;
        }
        cout << '\n';
    }

};

class Scaner {
    float scanResolution;
    float height, width;
public:
    Scaner() : scanResolution(0), height(0), width(0) {}
    Scaner(float s, float h, float w) : scanResolution(s), height(h), width(w) {}
    void ShowInfo()const {
        cout << "Scaner resolution: " << scanResolution << '\n';
        cout << "Arena scaning: " << height << 'x' << width << '\n';
    }

};

class Printer {
    string model;
    Cartrige* cartriges;
    int countCartriges;
    Scaner scaner;
public:
    Printer(): model("None"), cartriges(nullptr), countCartriges(0) {}
    Printer(string m, float s, float h, float w): model(m), scaner(s, h, w) {
        countCartriges = 4;
        cartriges = new Cartrige[countCartriges];
        cartriges[0] = Cartrige(300, "Red", Type::Standart);
        cartriges[1] = Cartrige(300, "Green", Type::Standart);
        cartriges[2] = Cartrige(300, "Blue", Type::Standart);
        cartriges[3] = Cartrige(300, "Black", Type::Standart);
    }
    ~Printer() { if (cartriges != nullptr) delete[] cartriges; }

    void Scan() {
        cout << "Scaning..." << '\n';
    }
    void PintDocument() {
        cout << "Print Document..." << '\n';
    }
    void PintSettings() {
        for (int i = 0; i < countCartriges; i++) {
            cartriges[i].ShowInfo();
        }
        scaner.ShowInfo();
    }

};


int main()
{
    cout << "Hello World!\n";

    Printer printer("Canon", 300, 30, 50);
    printer.PintDocument();
    printer.Scan();
    printer.PintSettings();

}