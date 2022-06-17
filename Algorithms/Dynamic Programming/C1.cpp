// Min Cost Climbing Stairs
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
// recursion approch
// time  = O(2^n)
// space = O(n) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(int n, vector<int>& cost){
	if (n==0) return 0;

	int left, right;
	
	left = cost[n-1] + minCost(n-1, cost);
	if (n > 2)
	right = cost[n-2] + minCost(n-2, cost);

	if (n<cost.size())
	return min(left, right);

	// return (minCost(n-1, cost), minCost(n-2, cost));
}

int main(){
	int n;
	cin >> n;

	vector<int> cost(n);
	for (int i = 0; i < n; i++){
		cin >> cost[i];
	}

	cout << minCost(n, cost);
	return 0;
}