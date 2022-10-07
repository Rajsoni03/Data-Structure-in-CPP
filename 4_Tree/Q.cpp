#include <iostream>
#include <climits>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int sum = 0;
	int count = 0;

	while(count < n){
		int min = arr[0];
		int min_index = 0;
		for (int i = 0; i < n; i++){
			if (min > arr[i]){
				min = arr[i];
				min_index = i;
			}
		}
		if (min_index > 0 && arr[min_index-1] < INT_MAX){
			arr[min_index-1] = INT_MAX;
			count++;
		}
		if (min_index < n-1 && arr[min_index+1] < INT_MAX){
			arr[min_index+1] = INT_MAX;
			count++;
		}
		sum += arr[min_index];
		arr[min_index] = INT_MAX;
		count++;
	}
	cout << sum;
	return 0;
}