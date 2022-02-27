#include <iostream>
#include <cmath>
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
			// start add. + (size of int * index)	
			if (index < size)
				return *(begin + index);
			else 
				cout << "Index out of range" << endl;
				return -1;
		}

		int find(T data){
			int itr = 0;
			for (int i = 0; i < size; i++){
				itr++;
				if (begin[i] == data){
					cout << "Itration in find : " << itr << endl;
					return i;
				}
			}
			return -1;
		}
		
		// ###########[ Homework ]##############
		// implement the binary search
		int find_binary(T data){

			int start_index = 0;
			int end_index = size-1;
			int mid_index;

			int itr = 0;

			while (start_index <= end_index){
				itr++;
				mid_index = (start_index + end_index)/2;
				if (begin[mid_index] == data){
					cout << "Itration in find_binary : " << itr << endl;
					return mid_index;
				}
				else if (begin[mid_index] > data)		
					end_index = mid_index;

				else if (begin[mid_index] < data)		
					start_index = mid_index + 1;
				cout << start_index << " : " << mid_index << " : " << end_index << endl;
			}
			cout << "Element Not Found" << endl;
			return -1;
		}
};

int main(){										 
	
	Array<int> arr(10); 

	for (int i = 0; i < 10; i++){
		cin >> arr.begin[i];
	}
	cout << arr.find(5) << endl;
	cout << endl;
	// ###########[ Homework ]##############
	cout << arr.find_binary(10); 

	return 0;
}