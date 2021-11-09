#include <iostream>
using namespace std;	

template <typename T>
class vector{
		const int BLOCK_SIZE = 16;
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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		vec.push_back(i);
	}

	return 0;
}