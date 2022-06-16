// fibonacci series recurssion
// time  = O(2^n)
// space = O(n) 
#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

ll fab(ll n){
	if (n < 2) return 1;
	return fab(n-1) + fab(n-2);
}

int main(){
	ll n = 43;
	cout << fab(n);

	return 0;
}