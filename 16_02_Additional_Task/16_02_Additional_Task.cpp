
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string home;
    int age;
    bool alive;

public:
    Animal(string h = "Forest", int a = 0) {
        home = h;
        age = a;
        alive = true;
    }

    virtual void Print() = 0;

    bool isAlive() {
        return alive;
    }

    void Die() {
        alive = false;
    }

    virtual ~Animal() {}
};

class Fox : public Animal {
public:
    Fox(string h = "Forest", int a = 0) : Animal(h, a) {}

    void Print() override {
        if (alive) {
            cout << "Fox, age: " << age
                << ", home: " << home << endl;
        }
    }

    void Grow() {
        if (alive) {
            age++;

            if (age >= 10) {
                Die();
                cout << "The fox died of old age!" << endl;
            }
        }
    }
};

class Rabbit : public Animal {
public:
    Rabbit(string h = "Forest", int a = 0) : Animal(h, a) {}

    void Print() override {
        if (alive) {
            cout << "Rabbit, age: " << age
                << ", home: " << home << endl;
        }
    }

    void Grow() {
        if (alive) {
            age++;

            if (age >= 5) {
                Die();
                cout << "The rabbit died of old age!" << endl;
            }
        }
    }
};

class Plant {
protected:
    string home;

public:
    Plant(string h = "Forest") {
        home = h;
    }

    virtual void Print() = 0;

    virtual ~Plant() {}
};

class Grass : public Plant {
private:
    int amount;

public:
    Grass(string h = "Forest", int a = 10) : Plant(h) {
        amount = a;
    }

    void Print() override {
        cout << "Amount of grass: " << amount << endl;
    }

    int getAmount() {
        return amount;
    }

    void Eat() {
        amount = 0;
    }
};

class Life {
private:
    Fox foxes[100];
    Rabbit rabbits[100];

    int foxCount;
    int rabbitCount;

    Grass grass;

public:
    Life() {
        foxCount = 2;
        rabbitCount = 3;

        foxes[0] = Fox("Forest", 2);
        foxes[1] = Fox("Forest", 3);

        rabbits[0] = Rabbit("Forest", 1);
        rabbits[1] = Rabbit("Forest", 2);
        rabbits[2] = Rabbit("Forest", 3);
    }

    int CountFoxes() {
        int count = 0;

        for (int i = 0; i < foxCount; i++) {
            if (foxes[i].isAlive()) {
                count++;
            }
        }

        return count;
    }

    int CountRabbits() {
        int count = 0;

        for (int i = 0; i < rabbitCount; i++) {
            if (rabbits[i].isAlive()) {
                count++;
            }
        }

        return count;
    }

    void Print() {
        cout << "\n========== NATURE STATUS ==========\n";

        cout << "\nFoxes:\n";

        for (int i = 0; i < foxCount; i++) {
            foxes[i].Print();
        }

        cout << "\nRabbits:\n";

        for (int i = 0; i < rabbitCount; i++) {
            rabbits[i].Print();
        }

        cout << "\nNumber of foxes: " << CountFoxes() << endl;
        cout << "Number of rabbits: " << CountRabbits() << endl;

        grass.Print();
    }

    void Live() {
        cout << "\n========== NEW DAY ==========\n";

        for (int i = 0; i < foxCount; i++) {
            foxes[i].Grow();
        }

        for (int i = 0; i < rabbitCount; i++) {
            rabbits[i].Grow();
        }

        int foxesAlive = CountFoxes();
        int rabbitsAlive = CountRabbits();

        if (grass.getAmount() > rabbitsAlive) {
            cout << "There is more grass than rabbits. Grass remains.\n";
        }
        else {
            grass.Eat();
            cout << "Rabbits ate all the grass!\n";
        }

        if (rabbitsAlive < foxesAlive && rabbitsAlive > 0) {

            for (int i = 0; i < rabbitCount; i++) {
                if (rabbits[i].isAlive()) {
                    rabbits[i].Die();

                    cout << "A fox ate a rabbit!\n";
                    break;
                }
            }
        }

        cout << "\nFoxes remaining: " << CountFoxes() << endl;
        cout << "Rabbits remaining: " << CountRabbits() << endl;
    }

    void AddFox() {
        if (CountFoxes() > 5) {
            cout << "There are more than 5 foxes. No new foxes can appear!\n";
        }
        else if (foxCount < 100) {
            foxes[foxCount] = Fox("Forest", 0);
            foxCount++;

            cout << "A new fox has appeared!\n";
        }
        else {
            cout << "There is no space for new foxes!\n";
        }
    }
};

int main() {

    Life life;
    int choice;

    do {
        cout << "\n-=-=-=-=-=- MENU -=-=-=-=-=-\n";
        cout << "1. Show nature status\n";
        cout << "2. Next day\n";
        cout << "3. Create a fox\n";
        cout << "0. Exit\n";

        cout << "\nYour choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            life.Print();
            break;

        case 2:
            life.Live();
            break;

        case 3:
            life.AddFox();
            break;

        case 0:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
