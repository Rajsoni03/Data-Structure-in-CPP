// Pattern Printing
/*

1 2 3 ... n-1 n
1 2 3 . n-1
...
1 2 3 4
1 2 3 
1 2
1

*/

#include <iostream>
using namespace std;

void print(int n){
	if (n <= 0) return;
	for (int i = 1; i <= n; i++){
		cout << i << '\t';
	}
	cout << endl;
	print(n-1);
}

int main(){
	int n;
	cin >> n;
    print(n);
    return 0;
}