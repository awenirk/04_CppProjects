#include <iostream>
using namespace std;

/* Завдання 1:
Перепишіть клас Stack(Queue) одного з попередніх домашніх завдань таким чином,
щоб генерувати виключення для можливих некоректних ситуацій
які можуть виникнути.
Наприклад, неможливість виділити потрібну кількість пам’яті,
переповнення стека, витяг з порожнього стека і т.д. Для
реалізації даного завдання використати або створити власні
класи-exception або ж взяти з біблеотеки <stdexcept>.
*/

class Stack {
private:
    enum { EMPTY = -1 };
    int* arr;
    int size;
    int topIndex;

public:
    Stack() : arr(nullptr), size(0), topIndex(EMPTY) {}
    Stack(int size) : arr(nullptr), size(size), topIndex(EMPTY) {
        if (size <= 0) {
            throw invalid_argument("Stack size must be greater than zero!");
        }

        arr = new int[size];
    }
    ~Stack() {
        delete[] arr;
    }

    bool IsFull() const {
        return topIndex == size - 1;
    }
    bool Push(int elem) {
        if (IsFull()) {
            throw overflow_error("Stack is full!");
        }

        arr[++topIndex] = elem;
        return true;
    }
    bool IsEmpty() const {
        return topIndex == EMPTY;
    }
    int Pop() {
        if (IsEmpty()) throw underflow_error("Stack is empty! Cannot pop.");
        return arr[topIndex--];
    }
    int GetCount() const {
        return topIndex + 1;
    }
    void Clear() {
        topIndex = EMPTY;
    }
    int Peek() const {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty! Cannot peek.");
        }

        return arr[topIndex];
    }
    void Print() const {
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    try {
        Stack st(15);

        cout << "Size = " << st.GetCount() << endl;

        for (int i = 0; i < 7; i++) {
            st.Push(rand() % 50);
        }

        cout << "Size = " << st.GetCount() << endl;
        st.Print();

        while (!st.IsEmpty()) {
            cout << "Delete element : " << st.Pop() << endl;
            st.Print();
        }

        cout << "Size = " << st.GetCount() << endl;
    }
    catch (const exception& ex) {
        cout << "Exception: " << ex.what() << endl;
    }
}