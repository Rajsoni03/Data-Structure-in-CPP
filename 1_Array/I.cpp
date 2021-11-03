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
			cout << "Default Constructor" << endl;
			size = 1;
			begin = new T[size];
		}
		Array(int size){
			cout << "1 Para Constructor" << endl;
			this->size = size;
			begin = new T[this->size]; 
		}
		Array(int size, T data){
			cout << "2 Para Constructor" << endl;
			this->size = size;
			begin = new T[this->size]; 
			for (int i = 0; i < this->size; i++){
				*(this->begin + i) = data;
			}
		}

		// Copy Constructor
		Array(const Array &obj){
			cout << "Copy Constructor" << endl;
			// update size properties 
			size = obj.size;

			// update begin properties 
			begin = new T[obj.size];

			// update array elements
			for (int i = 0; i < obj.size; ++i){
				*(begin+i) = *(obj.begin + i);
			}
		}

		// Copy Assignment
		Array& operator=(const Array &obj){
			cout << "Copy Assignment" << endl;
			// update size
			this->size = obj.size;

			// update begin pointer
			delete[] begin;
			begin = new T[obj.size];

			// update elements
			for (int i = 0; i < obj.size; ++i){
				*(begin+i) = *(obj.begin + i);
			}
			return *this;
		}

		// Distructor
		~Array(){

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
	
	Array<int> arr1(10); 

	for (int i = 0; i < 10; i++){
		cin >> *(arr1.begin + i);
	}

	Array<int> arr2(4);

	arr2 = arr1; //	arr2.operator=(arr1);

	Array<int> arr3(arr2);

	Array<int> arr3 = Array<int>(); // move constructor
	arr3 = Array<int>(); // move assignment

	return 0;
}