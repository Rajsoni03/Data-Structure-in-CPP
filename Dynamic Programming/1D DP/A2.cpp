// fibonacci series with dp
// top down / memoization
// time  = O(n)
// space = O(n) + O(n) 

#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

ll fab(ll n, vector<ll> &dp){
	if (n < 2) return 1;
	if (dp[n] != -1) return dp[n];
	return dp[n] = fab(n-1, dp) + fab(n-2, dp);
}

int main(){
	ll n = 91;
	vector<ll> dp(n+1, -1);
	cout << fab(n, dp);

	return 0;
}