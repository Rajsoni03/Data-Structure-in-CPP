// Dimond Pattern Printing
/*

             n
         n-1   n-1
       ...       ...
      4             4
    3                 3
  2                     2
1                         1
  2                     2
    3                 3
      4             4
       ...       ...
         n-1   n-1
             n

*/

#include <iostream>
using namespace std;

void print(int n, int k){
	if (n<=1) {
		cout << " *";
		for (int i = 1; i < 2*k-2; i++) cout << "  ";
		cout << " *" << endl;
		return;
	}

	for (int i = 1; i <= k*2; i++)
		(i==n || i==2*k - n) ? cout << " *" : cout <<"  ";
	cout << endl;

	print(n-1, k);

	for (int i = 1; i <= k*2; i++)
		(i==n || i==2*k - n) ? cout << " *" : cout <<"  ";
	cout << endl;
}

int main(){
	int n = 10;
    print(n, n);
    return 0;
}