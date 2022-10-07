#include <iostream>
using namespace std;

class Singletan{
	private:
		int data;  
		static Singletan *instance;       //  instance of the class
		Singletan(int data):data(data){}; //  private constructor

	public:
		static Singletan* getObject(int data = 0){
			if (!instance) 
				return instance = new Singletan(data);
			return instance;
		}
		
		void setData(int data){
			this->data = data;
		}

		int getData(){
			return this->data;
		}
};

Singletan *Singletan::instance = nullptr;       // initialize the singletan instance to null 

int main(){
	Singletan *s1 = Singletan::getObject(10);
	cout << s1->getData() << endl;

	Singletan *s2 = Singletan::getObject(20);	// return same instance which is previously initialized
	cout << s2->getData() << endl;

	s2->setData(100);							// modify s2 and print s1
	cout << s1->getData() << endl;	            // s1 and s2 pointing the same instance

	return 0;
}