// print numbers 
/*
hello - 1
hello - 2
hello - 3
hello - .
hello - .
hello - .
hello - n-2
hello - n-1
hello - n
*/

#include <iostream>
using namespace std;

void print(int n){
	if (n<=0) return;
	print(n-1);
	cout << "hello - " << n << endl;
}

int main(){
	print(10);
	return 0;
}