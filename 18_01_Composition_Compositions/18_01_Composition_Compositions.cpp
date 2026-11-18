#include <iostream>
using namespace std;


enum Type { None, Standart, XL, XXL };

class Document {
    string name;
    string format;
    int pages;
public:
    Document() : name("No name"), format("None"), pages(0) {}
    Document(string n, string f, int p) : name(n), format(f), pages(p) {}

    void ShowInfo()const {
        cout << "-=-=-=- Document: -=-=-=-" << '\n';
        cout << "Format: " << format << '\n';
        cout << "Pages: " << pages << '\n';
    }

};

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
    // Aggregation
    Document* doc;
public:
    Printer(): model("None"), cartriges(nullptr), countCartriges(0), doc(nullptr) {}
    Printer(string m, float s, float h, float w): model(m), scaner(s, h, w), doc(nullptr) {
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
        if (doc != nullptr) {
            cout << "Printing Document..." << '\n';
            doc->ShowInfo();
        }
        else cout << "No document!" << '\n';
    }
    void PintSettings() {
        for (int i = 0; i < countCartriges; i++) {
            cartriges[i].ShowInfo();
        }
        scaner.ShowInfo();
    }

    void AddDoc(Document* doc) {
        this->doc = doc;
    }
};


int main()
{
    cout << "Hello World!\n";

    Printer printer("Canon", 300, 30, 50);
    printer.PintDocument();
    printer.Scan();
    printer.PintSettings();

    Document doc1("Password", "A5", 16);
    Document doc2("C++ for beginner", "A4", 1520);

    printer.AddDoc(&doc1);
    printer.PintDocument();
    printer.AddDoc(&doc2);
    printer.PintDocument();

}