// fibonacci series with dp 
// bottom up / tabular formet
// space optimization
// time  = O(n)
// space = O(1)

#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

ll fab(ll n){
	ll prev1 = 1;
	ll prev2 = 1;
	ll curr = 0;
	for (int i = 2; i <= n; i++){
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return curr;
}

int main(){
	ll n = 43;
	cout << fab(n);

	return 0;
}