#include <iostream>
#include <forward_list>
using namespace std;

int main(){
	forward_list<int> list;

	list.push_front(10);
	list.push_front(20);
	list.push_front(30);
	list.push_front(40);
	list.push_front(50);

	// forward_list<char>::iterator it = list.begin();

	// overload ++ op
	// it = it->next;

	// cout << *it++ << endl;
	// cout << *it++ << endl;
	// cout << *it << endl;

	for (auto it = list.begin(); it != list.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}