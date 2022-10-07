// fibonacci series with dp 
// bottom up / tabular formet
// time  = O(n)
// space = O(n) 

#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

ll fab(ll n){
	vector<ll> dp(n+1, 1);
	for (int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main(){
	ll n = 43;
	cout << fab(n);

	return 0;
}