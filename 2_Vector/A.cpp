#include <iostream>
using namespace std;

template <class T>
class Vector{
	private:
		unsigned _size; // how meny element in vec
		unsigned _capacity; // max allocated size

	public:
		T *begin;

		Vector(){
			_size = 0;
			_capacity = 2;
			begin = new T[_capacity];
		}

		unsigned size(){
			return _size;
		}

		T operator[](unsigned index){ 
			if (index > _size) return -1;
			return *(begin+index);
		}

		void push_back(T element){
			// add new element to arry
			*(begin+_size) = element;

			// count of filled element's 
			_size += 1;
		}
};

int main()
{
	Vector<int> vec;

	cout << vec.size() <<endl;

	vec.push_back(1);
	vec.push_back(2);
	cout << vec[0] << endl;
	cout << vec[1] << endl;

	cout << vec.size() <<endl;

	return 0;
}