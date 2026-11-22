#include <iostream>
using namespace std;


float Divine(float a, float b) {
    float res;
    if (b == 0) {
        // cout << "Cant divine by zero" << endl;
        throw exception("cant divine by zero");
    }
    if (b == 1) {
        throw 404;
    }
    if (b == 2) {
        throw "202";
    }
    if (b == 3) {
        throw true;
    }
    else {
        res = a / b;
        cout << "Result: " << res << endl;

    }
}


class PasswordInvalidException : public exception {
public:
    PasswordInvalidException(const char* msg) : exception(msg) {}
};

class SmallPasswordException : public exception {
    int length;
public:
    SmallPasswordException(const char* msg, int l) : length(l), exception(msg) {}
    void Mesage() {
        cout << what() << endl;
        cout << "Actual length: " << length << endl;
    }
};


void ValidateLogin(const char* login, const char* password) {
    if (strlen(password)< 6)
        throw SmallPasswordException("Too small password!", strlen(password));

    if (islower(password[0]) || isalpha(password[0]))
        throw PasswordInvalidException("Password is invalid!");

    if (!isupper(login[0]) || !isalpha(login[0]))
        throw PasswordInvalidException("Login is incorrect!");

    cout << "Loading...." << endl;
    
}

class MyArray {
    int* arr;
    int size;
public:
    MyArray(int size = 10): size(size) {
        arr = new int[size] {};
    }
    ~MyArray() {
        if (arr != nullptr) delete[] arr;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    int getElement(int index) {
        if (index >= 0 and index < size) return arr[index];
        else throw out_of_range("Index is less than 0, or more than size");
    }
    void checkLen(int len) {
        if (len < 0) throw length_error("Some length error");
        cout << "Length is valid" << endl;
    }
    void SetSize(int newSize) {
        if (newSize < 0) throw invalid_argument("New size is less 0");
        else {
            int* temp = new int[newSize] {};
            for (int i = 0; i < size && i < newSize; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size = newSize;

        }
    }

};



void main()
{
    MyArray arr;
    arr.print();

    try {
        arr.getElement(100);
    }
    catch (out_of_range ex) {
        cout << ex.what() << endl;
    }



    /*
    char login[100];
    char password[100];

    for (int i = 0; i < 5; i++) {
        cout << "Enter login: "; cin >> login;
        cout << "Enter password: "; cin >> password;
        try {
            ValidateLogin(login, password);
        }
        catch (PasswordInvalidException ex) {
            cout << "Invalid error... do something" << endl;
            cout << "First must be small, a-z, A_Z, 0-9" << endl;
            cout << ex.what() << endl;
        }
        catch (SmallPasswordException ex) {
            ex.Mesage();
            cout << "Password must have at least 6 symbols!" << endl;
        }
        catch (exception ex) {
            cout << "General Error!" << endl;
            cout << ex.what() << endl;
            cout << "First symbol - big letter!" << endl;
        }
        catch (...) {
            cout << "Unknown error!" << endl;
        }
    }
    */


    /*
    float a, b;
    cout << "Enter Num1: "; cin >> a;
    cout << "Enter Num2 : "; cin >> b;

    try {
        float res = Divine(a, b);
        cout << "Result in main: " << res << endl;
    }
    catch (exception ex) {
        cout << ex.what() << endl;
    }
    catch (int ex) {
        cout << "Eror: " << ex << endl;
    }
    catch (const char* ex) {
        cout << "Eror: " << ex << endl;
    }
    catch (bool ex) {
        cout << "Bool exception: " << ex << endl;
    }
    catch (...) {
        cout << "Unknown exception" << endl;
    }
    */
}