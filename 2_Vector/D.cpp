#include <iostream>
using namespace std;	

template <typename T>
class vector{
		const int BLOCK_SIZE = 8;
	public:
		T *begin;
		T *end;
		int size; // filled elements
		int capacity; // max memory allocation

		vector(){
			begin = new T[BLOCK_SIZE];
			size = 0;
			capacity = BLOCK_SIZE;
			end = begin;
		};

		void push_back(T ele){

			if (size < capacity){
				end = begin+size;
				*(end) = ele;
				size++;
			}

			else{
				T *temp = new T[size+BLOCK_SIZE];

				for (int i = 0; i < size; i++){
					*(temp + i) = *(begin+i);
				}
				capacity += BLOCK_SIZE;

				delete[] begin;

				begin = temp;

				*(begin+size) = ele;
				end = begin+size;
				size++;
			}

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

	cout << vec.size << endl;
	cout << vec.capacity << endl;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);

	cout << endl;

	cout << vec.size << endl;
	cout << vec.capacity << endl;

	cout << endl;

	vec.push_back(9);

	cout << vec.size << endl;
	cout << vec.capacity << endl;

	return 0;
}