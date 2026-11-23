#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v1) {
	cout << "Vector 1: ";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << ' ';
	}
	cout << endl;
}
void PrintVector(vector<int> v1, vector<int> v2) {
	cout << "Vector 1: ";
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << ' ';
	}
	cout << endl;
	cout << "Vector 2: ";
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << ' ';
	}
	cout << endl;
}
void printSize(vector<int> v) {
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;
}



int main()
{
    vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

	/*
	v1[0] = 55;
	for (auto item: v1) {
		cout << item << ' ';
	}
	cout << endl;
	*/

	v1.begin(); // - first element
	v1.end(); // - not last element, but first empty element
	// v1.erase(); - delete element by adress, or elements by begin and end


	PrintVector(v1);

	v1.erase(v1.begin());
	PrintVector(v1);

	v1.erase(v1.begin()+2);
	PrintVector(v1);

	v1.erase(v1.end()-1);
	PrintVector(v1);

	printSize(v1);

	v1.erase(v1.begin(), v1.end()-4);
	PrintVector(v1);

	// v1.insert(); - add element by position

	v1.insert(v1.begin(), 55);
	PrintVector(v1);

	v1.insert(v1.begin(), { 7, 8, 9 });
	PrintVector(v1);

	v1.insert(v1.begin() + 2, 3, 4 ); // 1, 2, 4, 4, 4, 3 ,4, 5...
	PrintVector(v1);

	v1.insert(v1.end(), v2.begin() +1, v2.end() -2 );
	PrintVector(v1);

	printSize(v1);


	v1.push_back(444);
	v1.push_back(444);
	v1.push_back(444);
	v1.push_back(444);
	PrintVector(v1);

	v1.pop_back();
	v1.pop_back();
	PrintVector(v1);

	v1.swap(v2);
	PrintVector(v1, v2);
	v1.swap(v2);

	cout << "Show first element: " << v1.front() << endl;
	cout << "Show last element: " << v1.back() << endl<< endl;

	printSize(v1);
	v1.resize(70);

	PrintVector(v1);
	printSize(v1);
	v1.shrink_to_fit();
	printSize(v1);

	for (int i = 0; i < v1.size(); i++) {

	}





}