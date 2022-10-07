#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){
	int pivot = arr[end];
	int pivot_i = start;
	for (int i = start; i < end; i++){
		if (arr[i] <= pivot){
			swap(arr[i], arr[pivot_i]);
			pivot_i++;
		}
	}
	swap(arr[end], arr[pivot_i]);
	return pivot_i;
}

void quickSort(int arr[], int start, int end){
	if (start >= end) return;
	int pivot = partition(arr, start, end);
	quickSort(arr, start, pivot-1);
	quickSort(arr, pivot+1, end);
}

int main(){
	int arr[] = {10, 6, 9, 3, 2, 8, 4, 7, 1, 5};
	quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++){
		cout << arr[i] <<" ";
	}
	return 0;
}