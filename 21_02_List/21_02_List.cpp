#include <iostream>
#include <list>
using namespace std;

void showList(list<int>& l) {
    list<int>::iterator it;
    cout << "List: ";
    for (it = l.begin(); it != l.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

void showList(list<int>& l1, list<int>& l2) {
    list<int>::iterator it;
    cout << "List 1: ";
    for (it = l1.begin(); it != l1.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    cout << "List 2: ";
    for (it = l2.begin(); it != l2.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}




int main()
{
    list<int> l1, l2;


    for (int i = 0; i < 10; i++) {
        l1.push_back(i);
        l2.push_front(i);
    }
    showList(l1, l2);
    cout << "Size l1: " << l1.size() << endl;
    cout << "Size l2: " << l2.size() << endl << endl;

    l1.assign({ 11, 21, 31, 41});
    showList(l1);

    list<int>::iterator it = l1.begin();
    it++;
    it++;

    l1.erase(it);
    showList(l1);

    l1.push_back(100);
    l1.push_front(555);
    showList(l1);

    l1.insert(l1.begin(), 99);
    l1.insert(l1.begin(), { 1,2,3,4 });
    l1.insert(l1.end(), l2.begin(), l2.end());
    l1.insert(l1.end(), 3, 678);

    showList(l1);

    l1.remove(678);
    showList(l1);

    l1.resize(10);
    showList(l1);

    l1.resize(100, 7);
    showList(l1);

    l1.splice(l1.end(), l2, l2.begin());
    showList(l1, l2);

    l1.reverse();
    showList(l1);

    l1.sort();
    l2.sort();
    showList(l1, l2);

    l1.merge(l2); // both lists must been sorted
    showList(l1, l2);

    l1.unique();
    showList(l1);

    l1.swap(l2);
    showList(l1, l2);





}
