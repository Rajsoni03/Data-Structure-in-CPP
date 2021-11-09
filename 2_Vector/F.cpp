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

		void pop_back(){
			if (size==0) cout << "Vector is Empty\n";
			else{
				size--; // Step - 1
				if ((size % BLOCK_SIZE == 0) && (capacity != size+BLOCK_SIZE)){ // step 2 & 3
					T *temp = new T[size+BLOCK_SIZE]; // step 4
					for (int i = 0; i < size; ++i){
						*(temp+i) = *(begin+i);
					}
					delete[] begin;
					begin = temp; // step 5
					end = begin+size-1; 
					capacity = capacity - BLOCK_SIZE; // step 6
				}
				else
					end--;	
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

	cout << vec.size << endl;
	cout << vec.capacity << endl << endl;

	for (int i = 0; i < n; i++){
		cout << vec[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < 32; ++i){
		vec.pop_back();
	}

	cout << vec.size << endl;
	cout << vec.capacity << endl << endl;

	return 0;
}