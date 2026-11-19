
#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

int Abs(int x) {
    if (x < 0)
        return -x;

    return x;
}

int Max(int a, int b) {
    if (a > b)
        return a;

    return b;
}

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

class Shape {
protected:
    const char* type;

public:
    Shape(const char* type) : type(type) {}

    virtual void Print() const = 0;

    virtual ~Shape() {}
};

class Line : public Shape {
    Point start;
    Point end;

public:
    Line(Point start, Point end) : Shape("Line") {
        this->start = start;
        this->end = end;
    }

    void Print() const override {
        cout << "Type: " << type << endl;

        int dx = Abs(end.x - start.x);
        int dy = Abs(end.y - start.y);

        int steps = Max(dx, dy);

        if (steps == 0) {
            gotoxy(start.x, start.y);
            cout << "*";
            return;
        }

        for (int i = 0; i <= steps; i++) {
            int x = start.x + (end.x - start.x) * i / steps;
            int y = start.y + (end.y - start.y) * i / steps;

            gotoxy(x, y);
            cout << "*";
        }
    }
};

class Rectangle : public Shape {
    Point topLeft;
    int width;
    int height;

public:
    Rectangle(Point p, int w, int h) : Shape("Rectangle") {
        topLeft = p;
        width = w;
        height = h;
    }

    void Print() const override {
        cout << "Type: " << type << endl;

        for (int i = 0; i < width; i++) {
            gotoxy(topLeft.x + i, topLeft.y);
            cout << "*";

            gotoxy(topLeft.x + i, topLeft.y + height);
            cout << "*";
        }

        for (int i = 0; i <= height; i++) {
            gotoxy(topLeft.x, topLeft.y + i);
            cout << "*";

            gotoxy(topLeft.x + width, topLeft.y + i);
            cout << "*";
        }
    }
};

class Polyline : public Shape {
    Point* points;
    int count;

public:
    Polyline(Point arr[], int count) : Shape("Polyline") {
        this->count = count;

        points = nullptr;

        if (count > 0) {
            points = new Point[count];

            for (int i = 0; i < count; i++) {
                points[i] = arr[i];
            }
        }
    }

    void Print() const override {
        cout << "Type: " << type << endl;

        if (count < 2)
            return;

        for (int i = 0; i < count - 1; i++) {
            int dx = Abs(points[i + 1].x - points[i].x);
            int dy = Abs(points[i + 1].y - points[i].y);

            int steps = Max(dx, dy);

            if (steps == 0) {
                gotoxy(points[i].x, points[i].y);
                cout << "*";
                continue;
            }

            for (int j = 0; j <= steps; j++) {
                int x = points[i].x +
                    (points[i + 1].x - points[i].x) * j / steps;

                int y = points[i].y +
                    (points[i + 1].y - points[i].y) * j / steps;

                gotoxy(x, y);
                cout << "*";
            }
        }
    }

    ~Polyline() {
        delete[] points;
    }
};

int main()
{
    system("cls");

    Line line(Point(5, 5), Point(25, 15));

    Rectangle rectangle(Point(30, 5), 15, 8);

    Point arr[] = {
        Point(5, 20),
        Point(15, 25),
        Point(25, 20),
        Point(35, 28)
    };

    Polyline polyline(arr, 4);

    Shape* shapes[3] = {
        &line,
        &rectangle,
        &polyline
    };

    for (int i = 0; i < 3; i++) {
        shapes[i]->Print();
    }

    gotoxy(0, 35);
    cout << "All shapes printed!" << endl;

    return 0;
}
