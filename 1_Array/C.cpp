#include <iostream>
using namespace std;

// a-z A-Z _ $
// 0-9 XXXX
// #()[]{} XXXX
// keywords XXXX

template <class T>
class Array{
	public:
		T *begin;

		Array(){
			begin = new T[1];
		}
		Array(int size){
			begin = new T[size]; 
		}
		Array(int size, T data){
			begin = new T[size]; 
			for (int i = 0; i < size; i++){
				*(begin + i) = data;
			}
		}
};

int main(){										 
	
	Array<int> arr(5); // [0x00, 0x04, 0x08, 0x12, 0x16]

	for (int i = 0; i < 5; i++){
		cin >> *(arr.begin + i);
	}

	for (int i = 0; i < 5; i++){
		cout << *(arr.begin + i) << endl;
	}

	return 0;
}