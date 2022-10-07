// Pattern Printing
/*

1 2 3 ... n-1 n
1 2 3 . n-1
...
1 2 3 4
1 2 3 
1 2
1
1 2
1 2 3 
1 2 3 4
...
1 2 3 . n-1
1 2 3 ... n-1 n

*/

#include <iostream>
using namespace std;

void print(int n){
	if (n<=1){
		cout << 1 << endl;
		 return;
	}

	for (int i = 1; i <= n; i++) cout << i << ' ';
	cout << endl;

	print(n-1);

	for (int i = 1; i <= n; i++) cout << i << ' ';
	cout << endl;	
}

int main(){
    print(3);
    return 0;
}