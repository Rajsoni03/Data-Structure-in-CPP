// 1 -  Printing Subsequences

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

// 2 - Printing Subsequences where sum is k 

#include <iostream>
#include <vector>
using namespace std;

void subsequences(vector<int>& ds, int i, int n, int arr[], int sum, int target){
	if (i == n){
		if (sum == target){
			for (int it : ds) cout << it << ' ';
			if (ds.size()==0) cout << "{}";
			cout << endl;
		}
		return;
	}
	sum += arr[i];
	ds.push_back(arr[i]);
	subsequences(ds, i+1, n, arr, sum, target);

	sum -= arr[i];
	ds.pop_back();
	subsequences(ds, i+1, n, arr, sum, target);
}


int main(){
	int n = 16;
	int k = 12;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	vector<int> ds;
	subsequences(ds, 0, n, arr, 0, k);
}

// 3 - mctFromLeafValues

#include <iostream>
#include <vector>
using namespace std;

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;
    int mul = 0;
    
    for (int i = 0; i < n-1; i++){
        int index = 0;
        mul = arr[0] * arr[1];
        for (int j = i; j < arr.size()-1; j++){
            if (mul > arr[j] * arr[j+1]){
                mul = arr[j] * arr[j+1];
                index = j;
            }
        }
        for (int o = 0; o < arr.size(); o++){
          cout << "- " << arr[o] << " - " << ans << endl;
        }
        cout << endl;
        ans += mul;
        arr = vector<int>(arr.begin()+index+1, arr.end());// + vector<int>(2);
    }
    return ans;
}
int main(){
  vector<int> v = {5, 2, 3};
  cout << mctFromLeafValues(v) << endl;
}