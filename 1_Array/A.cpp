#include <iostream>
using namespace std;

// arr[5] = 200 204 208 212 216
// i = 500

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for (int &i : arr){ // arr[0]
		cin >> i;
	}


	for (int i : arr){
		cout << i << ' ';
	}

	return 0;
}