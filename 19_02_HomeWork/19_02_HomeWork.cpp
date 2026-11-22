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

/*
Завдання 1:
Клас Stack з обробкою винятків.
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
            throw invalid_argument("Invalid stack size!");
        }

        arr = new int[size];
    }
    ~Stack() {
        delete[] arr;
    }

    bool IsFull() const {
        return topIndex == size - 1;
    }
    bool IsEmpty() const {
        return topIndex == EMPTY;
    }
    bool Push(int elem) {
        if (IsFull()) {
            throw overflow_error("Stack is full!");
        }

        arr[++topIndex] = elem;
        return true;
    }
    int Pop() {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty!");
        }

        return arr[topIndex--];
    }
    int Peek() const {
        if (IsEmpty()) {
            throw underflow_error("Stack is empty!");
        }

        return arr[topIndex];
    }
    int GetCount() const {
        return topIndex + 1;
    }
    void Clear() {
        topIndex = EMPTY;
    }
    void Print() const {
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


/*
Завдання 1 (другий варіант):
Двозв'язний список List з обробкою винятків.
*/

class List {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count;

    Node* GetNode(int position) const {
        if (position < 0 || position >= count) {
            throw out_of_range("Invalid position!");
        }
        Node* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current;
    }

public: 
    List() : head(nullptr), tail(nullptr), count(0) {}
    ~List() {
        Clear();
    }


    bool IsEmpty() const {
        return head == nullptr;
    }
    int GetCount() const {
        return count;
    }
    void AddToEnd(int value) {
        Node* newNode = new Node(value);

        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        count++;
    }
    void AddToBegin(int value) {
        Node* newNode = new Node(value);

        if (IsEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        count++;
    }
    void Insert(int position, int value) {
        if (position < 0 || position > count) { 
            throw out_of_range("Invalid position!");
        }

        if (position == 0) {
            AddToBegin(value);
            return;
        }

        if (position == count) {
            AddToEnd(value);
            return;
        }

        Node* current = GetNode(position);
        Node* newNode = new Node(value);

        newNode->prev = current->prev;
        newNode->next = current;

        current->prev->next = newNode;
        current->prev = newNode;

        count++;
    }
    int GetElement(int position) const {
        if (IsEmpty()) {
            throw underflow_error("List is empty!");
        }

        return GetNode(position)->data;
    }
    void Remove(int position) {
        if (IsEmpty()) {
            throw underflow_error("List is empty!");
        }

        Node* current = GetNode(position);

        if (current == head) {
            head = head->next;
        }
        else {
            current->prev->next = current->next;
        }

        if (current == tail) {
            tail = tail->prev;
        }
        else {
            current->next->prev = current->prev;
        }

        delete current;
        count--;
    }
    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        count = 0;
    }
    void Print() const {
        if (IsEmpty()) {
            throw underflow_error("List is empty!");
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};


int main() {
    try {
        cout << "-=-=-=- STACK -=-=-=-" << endl;

        Stack st(5);

        for (int i = 0; i < 5; i++) { 
            st.Push(rand() % 50);
        } 

        st.Print();

        cout << "Deleted: " << st.Pop() << endl;
        cout << "Top element: " << st.Peek() << endl;
        cout << "Count: " << st.GetCount() << endl;


        cout << "\n-=-=-=- LIST -=-=-=-" << endl;

        List list;

        list.AddToEnd(10);
        list.AddToEnd(20);
        list.AddToEnd(30);
        list.AddToBegin(5);

        list.Print(); 

        list.Insert(2, 15);
        list.Print();

        cout << "Element at position 2: "
            << list.GetElement(2) << endl;

        list.Remove(1);
        list.Print();

        cout << "Count: " << list.GetCount() << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    } 
    

    return 0;

}


