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
				*(this->begin + i) = data;
			}
		}
		// Copy Constructor
		Array(const Array &obj){
			// update size properties 
			size = obj.size;

			// update begin properties 
			begin = new T[obj.size];

			// update array elements
			for (int i = 0; i < obj.size; ++i){
				*(begin+i) = *(obj.begin + i);
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
				if (*(begin + i) == data){
					cout << "Itration in find : " << itr << endl;
					return i;
				}
			}
			return -1;
		}
		
		// implement the binary search
		int find_binary(T data){

			int start_index = 0;
			int end_index = size-1;
			int mid_index;

			int itr = 0;

			int max_run = log(size)+2;
			while (max_run--){
				itr++;
				cout << start_index << " : " << mid_index << " : " << end_index << endl;

				mid_index = (start_index + end_index)/2;

				if (*(begin+mid_index) == data){
					cout << "Itration in find_binary : " << itr << endl;
					return mid_index;
				}
				else if (*(begin+mid_index) > data)		
					end_index = mid_index - 1;

				else if (*(begin+mid_index) < data)		
					start_index = mid_index + 1;
			
			}
			cout << "Element Not Found" << endl;
			return -1;
		}


		// Operator Overloading
		T& operator[](const unsigned& index){
			cout << &index << endl;
			return *(begin + index);
		}
		
};

int main(){										 
	
	Array<int> arr(10); 

	for (int i = 0; i < 10; i++){
		cin >> *(arr.begin + i);
	}

	Array<int> arr2(arr);

	cout << arr.size << endl;
	cout << arr2.size << endl;

	for (int i = 0; i < arr2.size; ++i)
	{
		cout << *(arr2.begin + i) << " " ;
	}

	return 0;
}