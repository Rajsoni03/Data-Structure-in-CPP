#include <iostream>
using namespace std;

template <typename T>
class vector{
	public:
		T *begin;
		T *end;
		int size; // filled elements
		int capacity; // max memory allocation

		vector(){
			begin = new T[1];
			size = 1;
			capacity = 1;
			end = begin;
		};

		void push_back(T ele){

			T *temp = new T[size+1]; // allocate new memory 

			for (int i = 0; i < size; ++i){ // copy all elements of previous array to new array
				*(temp+i) = *(begin+i);
			}

			*(temp+size) = ele; // add new element at last

			delete[] begin; // delete previous array

			begin = temp;
			end = begin + size;

			size = size + 1;
			capacity = capacity + 1;
		}

		T operator[](int index){
			if (index < size)
				return *(begin+index);
			else
				return -1;
		}
};

int main()
{
	vector<int> vec;
	*(vec.begin) = 1;

	// N = 10;


	for (int i = 2; i <= 10; ++i){ 
		vec.push_back(i);
	}

	for (int i = 0; i < vec.size; ++i){
		cout << vec[i] << endl;
	}

	return 0;
}