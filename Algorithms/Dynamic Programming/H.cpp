// Frog Jump 
// minium energy required to reach 0 to N th
// can jump 1 step or 2 step
// energyLoss = abs(energy[i] - energy[i-1])
// bottom up / tabular formet
// Space optimization
// time  = O(n)
// space = O(1) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minEnergy(int n, vector<int> &energy){
	vector<int> dp(n+1, -1);
	int prev1 = 0;
	int prev2 = 0;
	int curr = 0;

	for (int i = 1; i <= n; i++){
		int left = abs(energy[i-1] - energy[i]) + prev1;	
		int right = (i>=2) ? abs(energy[i-2] - energy[i]) + prev2 : INT_MAX;
		curr = min(left, right);
		prev2 = prev1;
		prev1 = curr;
		cout << " - " << i << " - " << left << " - " << right << endl;
	}
	return prev1;
}

int main(){
	int n;
	cin >> n;

	vector<int> energy(n);
	for (int i = 0; i < n; i++){
		cin >> energy[i];
	}

	cout << minEnergy(n-1, energy);
	return 0;
}