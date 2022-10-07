// K Pattern Printing
/*

1            n
1        n-1
...
1     4
1   3 
1 2
1
1 2
1   3 
1     4
...
1       n-1
1            n

*/

#include <iostream>
using namespace std;

void print(int n){
	if (n<=1) {
		cout << '*' << endl;
		return;
	}

	for (int i = 1; i <= n; i++) 
		(i==1 || i==n) ? cout << '*' : cout <<' ';
	cout << endl;

	print(n-1);

	for (int i = 1; i <= n; i++)
		(i==1 || i==n) ? cout << '*' : cout <<' ';
	cout << endl;
}

int main(){
    print(10);
    return 0;
}