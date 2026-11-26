#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//#define file "file.txt";
const string file = "TrainsDataBase.txt";

/* Завдання:
Написати програму «Автоматизована інформаційна система залізничного вокзалу».
Система містить: відомості про відправлення потягів далекого прямування.
Для кожного потяга вказуємо:
-	номер;
-	час відправлення;
-	станцію призначення.

Забезпечити наступний функціонал:
1.	Додати потяг в систему;
2.	Виведення інформації по всіх потягах;
3.	Виведення інформації по конкретному потяга (по номеру);
trains[i].getNumber() == number;
4.	Відредагувати час відправлення потяга (по номеру);
5.	Відсортувати список потягів по часу відправлення;****
6.	Показати список потягів по станції призначення;
7.	Записати список в файл;
8.	Зчитати список з файлу.
Використовувати контейнерний клас vector. Для запису/читання потяга з файла перевантажити оператори << >>
*/

class Train {
private:
    struct Time {
        short h, m, s;
        Time():h(0), m(0), s(0) {}
        Time(int h, int m, int s):h(h), m(m), s(s) {}
    };
    int number;
    Time departureTime;
    string destination;
public:
    Train(): number(0), departureTime(), destination("No destination") {}
    Train(int n, Time t, string d): number(n), departureTime(t), destination(d) {}
    Train(int n, int h, int m, int s, string d) : number(n), departureTime({h,m,s}), destination(d) {}

    int getNum()const { return number; }
    int getTimeInS() const {
        return ((this->departureTime.h * 3600) +
            (this->departureTime.m * 60) +
            (this->departureTime.s));
    }
    string getDestination()const { return destination; }
    
    void setTime(Time t) { this->departureTime = t; }
    void setTime(int h, int m, int s) {
        this->departureTime.h = h;
        this->departureTime.m = m;
        this->departureTime.s = s;
    }

    void printTrain()const {
        cout << "Number: " << number << endl;
        cout << "Departure time: "
            << this->departureTime.h << ':'
            << this->departureTime.m << ':'
            << this->departureTime.s << endl;
        cout << "Destination: " << destination << endl;
    }

    bool operator < (const Train& other)const {
        return this->getTimeInS() < other.getTimeInS();
    }
    bool operator > (const Train& other)const {
        return this->getTimeInS() > other.getTimeInS();
    }
    friend ostream& operator<<(ostream& out, const Train& train);
    friend istream& operator>>(istream& in, Train& train);

};

class Railway {
private:
    vector<Train> trains;

public:
    Railway(): trains() {}

    void addTrain(const Train t) { trains.push_back(t); }
    void printAll()const {
        for (int i = 0; i < trains.size(); i++) {
            trains[i].printTrain();
        }
    }
    void printByNum(int n)const {
        for (int i = 0; i < trains.size(); i++) {
            if (trains[i].getNum() == n) { trains[i].printTrain(); }
        }
    }
    void showByDestination(string d)const {
        for (int i = 0; i < trains.size(); i++) {
            if (trains[i].getDestination() == d) { trains[i].printTrain(); }
        }
    }
    
    void editTrainTimeByNum(int num) {
        for (Train& train : trains) {
            if (train.getNum() == num) {
                int h, m, s;

                cout << "Enter new time (h m s): ";
                cin >> h >> m >> s;

                train.setTime(h, m, s);
                return;
            }
        }

        cout << "Train not found!\n";
    }
    void sortByTime() {
        for (int i = 0; i < trains.size() - 1; i++) {
            for (int j = 0; j < trains.size() - i - 1; j++) {
                if (trains[j + 1] < trains[j]) {
                    Train temp = trains[j];
                    trains[j] = trains[j + 1];
                    trains[j + 1] = temp;
                }
            }
        }
    }

    void writeToFile() {
        ofstream out("trains.txt");

        if (!out.is_open()) {
            cout << "File open error!\n";
            return;
        }

        for (const Train& train : trains) {
            out << train;
        }

        out.close();
    }
    void readFromFile() {
        ifstream in("trains.txt");

        if (!in.is_open()) {
            cout << "File open error!\n";
            return;
        }

        trains.clear();

        Train train;

        while (in >> train) {
            trains.push_back(train);
        }

        in.close();
    }

};

ostream& operator << (ostream& out, const Train& train) {
    out << train.number << '|';
    out << train.departureTime.h << ':';
    out << train.departureTime.m << ':';
    out << train.departureTime.s << '|';
    out << train.destination << '\n';

    return out;
}
istream& operator >> (istream& in, Train& train) {
    char sep;

    in >> train.number >> sep;
    in >> train.departureTime.h >> sep;
    in >> train.departureTime.m >> sep;
    in >> train.departureTime.s >> sep;

    getline(in, train.destination);

    return in;
}


int main()
{
    Railway rw;

    //1.	Додати потяг в систему;
    rw.addTrain(Train{ 1,{ 01,00,00 }, "Kyiv"});
    rw.addTrain(Train{ 2,{ 15,20,00 }, "Kharkiv"});
    rw.addTrain(Train{ 3,{ 18,50,00 }, "Lviv"});
    rw.addTrain(Train{ 4,{ 8,30,00 }, "Rivne"});
    rw.addTrain(Train{ 5,{ 8,30,00 }, "Ternopil"});
    rw.addTrain(Train{ 6,{ 12,30,00 }, "Kyiv"});

    //2.	Виведення інформації по всіх потягах;
    cout << "-=-=-=-=-=- Print All: -=-=-=-=-=-" << endl;
    rw.printAll();

    //3.	Виведення інформації по конкретному потяга(по номеру);
    cout << endl << "-=-=-=-=-=- Print by num (2): -=-=-=-=-=-" << endl;
    rw.printByNum(2);

    //4.	Відредагувати час відправлення потяга(по номеру);
    cout << endl << "-=-=-=-=-=- Edit train (2): -=-=-=-=-=-" << endl;
    rw.editTrainTimeByNum(2);
    rw.printByNum(2);

    //5.	Відсортувати список потягів по часу відправлення;
    cout << endl << "-=-=-=-=-=- Sort by time: -=-=-=-=-=-" << endl;
    rw.sortByTime();
    rw.printAll();
    
    //6.	Показати список потягів по станції призначення;
    cout << endl << "-=-=-=-=-=- Show by destination (Kyiv): -=-=-=-=-=-" << endl;
    rw.showByDestination("Kyiv");
       
    //7.	Записати список в файл;
    cout << endl << "-=-=-=-=-=- Write to file -=-=-=-=-=-" << endl;
    rw.writeToFile();
    
    //8.	Зчитати список з файлу.
    cout << "-=-=-=-=-=- Read from file: -=-=-=-=-=-" << endl;
    rw.readFromFile();


    rw.printAll();
}
