// Printing Subsequences

#include <iostream>
#include <vector>
using namespace std;

void subsequences(vector<int>& ds, int i, int n, int arr[]){
	if (i == n){
		for (int it : ds) cout << it << ' ';
		if (ds.size()==0) cout << "{}";
		cout << endl;
		return;
	}
	ds.push_back(arr[i]);
	subsequences(ds, i+1, n, arr);

	ds.pop_back();
	subsequences(ds, i+1, n, arr);
}


int main(){
	int n = 16;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	vector<int> ds;
	subsequences(ds, 0, n, arr);
}