// print numbers 
/*
hello - n
hello - n-1
hello - n-2
hello - n-3
hello - .
hello - .
hello - .
hello - 2
hello - 1
*/

#include <iostream>
using namespace std;

void print(int n){
	if (n<=0) return; // base case
	cout << "hello - " << n << endl;
	print(n-1);
}

int main(){
	print(10);
	return 0;
}