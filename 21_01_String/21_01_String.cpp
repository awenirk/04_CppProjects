#include <iostream>
#include <string>
using namespace std;



int main()
{
    string name = "avenir";
    string surname = "SomeBuddy";
    cout << name << ' ' << surname << endl;
    surname += "!!!";
    cout << name << ' ' << surname << endl;

    string one("Hello World!");
    cout << one << endl;

    string two(20, '$');
    cout << two << endl;

    string three(one);
    cout << three << endl;

    one += " Oops!";
    cout << one << endl;

    string five({'S', 't', 'r', 'i', 'n', 'g'});
    cout << five << endl;
    five[1] = 'p';
    cout << five << endl;
    cout << five[0] << endl;

    string six = one + five;
    cout << six << endl;
    
    char alls[] = "All`s well that ends well!";

    string seven(alls, 20);
    cout << seven << endl;

    string eight(alls + 6, alls + 10);
    cout << eight << endl;

    string nine(&alls[6], &alls[10]); // from adress to address
    cout << nine << endl;

    string ten(alls);
    cout << "Size = " << ten.size() << endl;
    cout << "Capacity = " << ten.capacity() << endl;

    for (int i = 0; i < ten.size(); i++) {
        cout << ten[i] << ' ';
    }
    cout << endl;

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    for (auto s : ten) {
        cout << s << ' ';
    }
    cout << endl;

    for (auto i = ten.begin(); i != ten.end(); i++) {
        cout << *i << ' ';
    }
    cout << endl;

    
    const char c_str[] = "Hello";
    string str = "hello world!";

    cout << "Size: " << str.size() << endl;
    cout << "Capacity = " << ten.capacity() << endl;
    
    // str.clear();

    cout << "Size: " << str.size() << endl;
    cout << "Capacity = " << ten.capacity() << endl;

    if (str.empty()) { cout << "Str is empty!" << endl; }

    cout << str << endl;

    str.append(" end. ");
    cout << str << endl;

    str.append(c_str, 4);
    cout << str << endl;

    str.append({ 'S', 't', 'r', 'i', 'n', 'g' });
    cout << str << endl;

    str.append(str.begin() + 5, str.end() - 4);
    cout << str << endl;
    
    str += "Asdgwss";
    cout << str << endl;

    str.insert(str.begin(), 'H');
    cout << str << endl;

    str.insert(0, 5, 'A');
    cout << str << endl;
    
    str.insert(5, "gggg");
    cout << str << endl;

    str.insert(0, c_str);
    cout << str << endl;

    str.insert(str.end(), { 'a','b','c','d' });
    cout << str << endl;

    /*
    str.erase(str.begin());
    cout << str << endl;

    str.erase(0, 15);
    cout << str << endl;

    str.erase(8);
    cout << str << endl;

    str.erase();
    cout << str << endl;
    */

    str.replace(0, 5, "Yes");
    cout << str << endl;

    cout << "Index of first 'o': " << str.find('q') << endl;
    cout << "Index of last 'o': " << str.rfind('o') << endl;
    cout << "Index of last 'o': " << str.find_first_of('o') << endl;
    cout << "Index of last 'o': " << str.find_first_not_of('o') << endl;

    cout << "Index of last 'o': " << str.find_last_of('o') << endl;
    cout << "Index of last 'o': " << str.find_last_not_of('o') << endl;

    cout << "SubString: " << str.substr(5, 15) << endl;


}
