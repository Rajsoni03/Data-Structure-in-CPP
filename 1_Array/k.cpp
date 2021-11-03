#include <iostream>
#include <array>
using namespace std;

int main(){										 
	
	array<int, 10> arr1; 

	for (int i = 0; i < 10; i++){
		cin >> arr1[i];
	}

	for (int i = 0; i < 10; i++){
		cout << arr1[i] << endl;
	}
	
	return 0;
}