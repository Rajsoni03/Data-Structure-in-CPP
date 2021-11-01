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
				*(this->begin + i) = data;
			}
		}

		// member methods
		T at(unsigned index){
			// start add. + (size of int * index)	
			if (index < size)
				return *(begin + index);
			else 
				cout << "Index out of range" << endl;
				return -1;
		}

		int find(T data){
			for (int i = 0; i < size; i++){
				if (*(begin + i) == data)
					return i;
			}
			return -1;
		}

		
		// ###########[ Homework ]##############
		// implement the binary search
		int find_binary(T data){
			return -1;
		}
};

int main(){										 
	
	Array<int> arr(5); // [0x00, 0x04, 0x08, 0x12, 0x16]

	for (int i = 0; i < 5; i++){
		cin >> *(arr.begin + i);
	}

	cout << arr.find(3) << endl;

	// ###########[ Homework ]##############
	cout << arr.find_binary(3); 

	return 0;
}