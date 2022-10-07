// Frog Jump 
// minium energy required to reach 0 to N th
// can jump 1 step or 2 step
// energyLoss = abs(energy[i] - energy[i-1])
// dynamic programming
// time  = O(n)
// space = O(n) + O(n) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minEnergy(int n, vector<int> &energy, vector<int> &dp){
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];

	int left = abs(energy[n-1] - energy[n]) + minEnergy(n-1, energy, dp);
	int right = (n>=2) ? abs(energy[n-2] - energy[n]) + minEnergy(n-2, energy, dp) : INT_MAX;

	cout << " - " << n << " - " << left << " - " << right << endl;
	return dp[n] = min(left, right);
}

int main(){
	int n;
	cin >> n;

	vector<int> energy(n);
	for (int i = 0; i < n; i++){
		cin >> energy[i];
	}

	vector<int> dp(n, -1);

	cout << minEnergy(n-1, energy, dp);
	return 0;
}