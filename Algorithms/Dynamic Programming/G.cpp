// Frog Jump 
// minium energy required to reach 0 to N th
// can jump 1 step or 2 step
// energyLoss = abs(energy[i] - energy[i-1])
// bottom up / tabular formet
// time  = O(n)
// space = O(n) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minEnergy(int n, vector<int> &energy){
	vector<int> dp(n+1, -1);
	dp[0] = 0;

	for (int i = 1; i <= n; i++){
		int left = abs(energy[i-1] - energy[i]) + dp[i-1];	
		int right = (i>=2) ? abs(energy[i-2] - energy[i]) + dp[i-2] : INT_MAX;
		dp[i] = min(left, right);
		cout << " - " << i << " - " << left << " - " << right << endl;
	}
	return dp[n-1];
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