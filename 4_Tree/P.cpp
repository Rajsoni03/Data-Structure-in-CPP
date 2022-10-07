#include <iostream>
#include <algorithm>
using namespace std;

int marathon(int input1, int input2, int input3[]){
	int topSum = 0;

	sort(input3, input3 + input1);

	for (int i = 0; i < input2; i++){
		topSum += input3[input1 - i - 1];
	}
	return topSum;
}


int main(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << marathon(n, k, arr);

	return 0;
}