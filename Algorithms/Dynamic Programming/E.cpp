// Frog Jump 
// minium energy required to reach 0 to N th
// can jump 1 step or 2 step
// energyLoss = abs(energy[i] - energy[i-1])
// recursion 
// time  = O(2^n)
// space = O(n) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minEnergy(int n, vector<int> &energy){
	if (n <= 0) return 0;

	int left = abs(energy[n-1] - energy[n]) + minEnergy(n-1, energy);
	int right = (n>=2) ? abs(energy[n-2] - energy[n]) + minEnergy(n-2, energy) : INT_MAX;

	cout << " - " << n << " - " << left << " - " << right << endl;
	return min(left, right);
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