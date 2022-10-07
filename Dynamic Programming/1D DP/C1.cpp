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
	if (n==1) return cost[0];
	if (n > cost.size()) return min(minCost(n-1, cost), minCost(n-2, cost));

	int left = cost[n-1] + minCost(n-1, cost);
	int right = cost[n-1] + minCost(n-2, cost);

	return min(left, right);
}

int main(){
	int n;
	cin >> n;

	vector<int> cost(n);
	for (int i = 0; i < n; i++){
		cin >> cost[i];
	}

	cout << minCost(n+1, cost);
	return 0;
}

/*
INPUT:
10
1 100 1 2 1 100 1 1 100 1

3
10 15 20

OUTPUT:
6
15
*/