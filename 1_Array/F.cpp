#include <iostream>
using namespace std;


int main(){
	int a = 10;
	int *ptr = &a;

	cout << "a    : " << a << endl;
	cout << "ptr  : " << ptr << endl;
	cout << "*ptr : " << *ptr << endl;

	int &b = a;
	b++;

	cout << "\na    : " << a << endl;
	cout << "b    : " << b << endl;
	cout << "&a   : " << &a << endl;
	cout << "&b   : " << &b << endl;
	cout << "ptr  : " << ptr << endl;
	cout << "*ptr : " << *ptr << endl;
	
	return 0;
}