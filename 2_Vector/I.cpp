#include <iostream>
using namespace std;	

template <typename T>
class vector{
		const int BLOCK_SIZE = 8;
		T *begin;
		T *end;
		int _size; // filled elements
		int _capacity; // max memory allocation

	public:
		vector(){
			begin = new T[BLOCK_SIZE];
			_size = 0;
			_capacity = BLOCK_SIZE;
			end = begin;
		};

		int size(){
			return _size;
		}
		
		int capacity(){
			return _capacity;
		}

		void push_back(T ele){

			if (_size < _capacity){
				end = begin+_size;
				*(end) = ele;
				_size++;
			}

			else{
				T *temp = new T[_size + BLOCK_SIZE];

				for (int i = 0; i < _size; i++){
					*(temp + i) = *(begin+i);
				}
				_capacity += BLOCK_SIZE;

				delete[] begin;

				begin = temp;

				*(begin+_size) = ele;
				end = begin+_size;
				_size++;
			}
		}

		// void pop_back(){
		// 	if (_size==0) cout << "Vector is Empty\n";
		// 	else{
		// 		_size--; // Step - 1
		// 		if ((_size % BLOCK_SIZE == 0) && (_capacity != _size+BLOCK_SIZE)){ // step 2 & 3
		// 			T *temp = new T[_size+BLOCK_SIZE]; // step 4
		// 			for (int i = 0; i < _size; ++i){
		// 				*(temp+i) = *(begin+i);
		// 			}
		// 			delete[] begin;
		// 			begin = temp; // step 5
		// 			end = begin+_size-1; 
		// 			_capacity = _capacity - BLOCK_SIZE; // step 6
		// 		}
		// 		else
		// 			end--;	
		// 	}		
		// }
		void pop_back(){
	        _size--;
	        if(_size%BLOCK_SIZE==0 ){
	            if(_size == (_capacity - 2*BLOCK_SIZE)){
	                T *temp = new T[_size+BLOCK_SIZE];
	                for(int i=0;i<_size;i++){
	                    *(temp+i) = *(begin+i);
	                }
	                delete[] begin;
	                begin = temp;
	                _capacity = _size+BLOCK_SIZE;
	                end = begin+_size;
	            }
	        }
	        else
	            end--;
	    }
		T operator[](int index){
			if (index < _size)
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

	cout << vec.size() << endl;
	cout << vec.capacity() << endl << endl;

	for (int i = 0; i < n; i++){
		cout << vec[i] << " ";
	}
	cout << endl << endl;


	for (int i = 0; i < 32; ++i){
		vec.pop_back();
	}

	cout << vec.size() << endl;
	cout << vec.capacity() << endl << endl;

	return 0;
}