#include <iostream>
using namespace std;

template <class T>
class Array{
	public:
		// member variables
		T *begin;
		unsigned size;

		// Constructors
		Array(){
			size = 1;
			begin = new T[size];
		}
		Array(int size){
			this->size = size;
			begin = new T[this->size]; 
		}
		Array(int size, T data){
			this->size = size;
			begin = new T[this->size]; 
			for (int i = 0; i < this->size; i++){
				this->begin[i] = data;
			}
		}

		// member methods
		T at(unsigned index){
			if (index < size)
				return begin[index]; // start add. + (size of int * index)	
			else 
				cout << "Index out of range" << endl;
				return -1;
		}
		int find(T data){ // linear search
			for (int i = 0; i < size; i++){
				if (begin[i] == data)
					return i;
			}
			return -1;
		}
};

int main(){										 
	
	Array<int> arr(5); // [0x00, 0x04, 0x08, 0x12, 0x16]

	cout << arr.size << endl;

	for (int i = 0; i < 5; i++){
		cin >> arr.begin[i];
	}

	cout << arr.at(3) << endl; // arr[3]
	cout << arr.at(6) << endl; // print -1

	cout << arr.find(3); 

	return 0;
}