#include <iostream>
using namespace std;	

template <typename T>
class vector{
		const int BLOCK_SIZE = 4;
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

		void pop_back(){
			if (_size==0) cout << "Vector is Empty\n";
			else{
				_size--; // Step - 1
				if ((_size % BLOCK_SIZE == 0) && (_capacity != _size+BLOCK_SIZE)){ // step 2 & 3
					T *temp = new T[_size+BLOCK_SIZE]; // step 4
					for (int i = 0; i < _size; ++i){
						*(temp+i) = *(begin+i);
					}
					delete[] begin;
					begin = temp; // step 5
					end = begin+_size-1; 
					_capacity = _capacity - BLOCK_SIZE; // step 6
				}
				else
					end--;	
			}		
		}


		void push_front(T ele){
			if (_size < _capacity){
				for (int i = 0; i < _size; ++i){
					*(end-i+1) = *(end-i);
				}
				end++;
				*begin = ele;
				_size++;
			}
			else{
				T *temp = new T[_size+BLOCK_SIZE];
				*temp = ele;
				for (int i = 0; i < _size; ++i) {
					*(temp+i+1) = *(begin+i);
				}
				_size++;
				delete[] begin;
				begin = temp;
				end = begin+_size-1;
				_capacity = _capacity+BLOCK_SIZE;
			}
		}

		void pop_front(){
			_size--;
			if ((_size%BLOCK_SIZE == 0) && (_capacity != _size+BLOCK_SIZE)){
				T *temp = new T[_capacity - BLOCK_SIZE];
				for (int i = 0; i < _size; ++i){
					*(temp+i) = *(begin+i+1);
				}
				delete[] begin;
				begin = temp;
				end = begin + _size - 1;
				_capacity = _capacity - BLOCK_SIZE;
			}
			else {
				for (int i = 0; i < _size; ++i)	{
					*(begin+i) = *(begin+i+1);
				}
				end--;
			}	
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

	for (int i = 1; i <= n; i++){
		vec.push_back(i);
	}

	for (int i = 0; i < vec.capacity(); i++){
		cout << vec[i] << " " ;
	}

	cout << endl<< endl;

	vec.push_front(5);
	vec.push_front(4);
	vec.push_front(3);
	vec.push_front(2);
	vec.push_front(1);

	vec.pop_front();
	vec.pop_front();
	vec.pop_front();
	vec.pop_front();
	vec.pop_front();

	cout << endl;
	for (int i = 0; i < vec.capacity(); i++){
		cout << vec[i] << " " ;
	}

	cout << endl << endl << vec.size() << endl;
	cout << vec.capacity() << endl;

	return 0;
}