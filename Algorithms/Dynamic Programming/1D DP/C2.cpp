// Min Cost Climbing Stairs
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
// recursion approch
// time  = O(n)
// space = O(n) + O(n) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(int n, vector<int>& cost, vector<int>& dp){
    if (n==0) return 0;
    if (n==1) return cost[0];

    if (dp[n-1] != -1) return dp[n-1];
    if (n > cost.size()) return dp[n-1] = min(minCost(n-1, cost, dp), minCost(n-2, cost, dp));

    int left = cost[n-1] + minCost(n-1, cost, dp);
    int right = cost[n-1] + minCost(n-2, cost, dp);
    return dp[n-1] = min(left, right);
}

// 0 [10 15 20] 0
// dp = [0, 10, 25, 30]

/*
		4
	   / \
	  3   2
	 / \     
	2   1
   / \
  1   0 
 / \
0  -1
			25
		   / \
		  30  25
		 / \     
		25  10
	   / \
	  10  10
	 / \
	10  0
*/


int main(){
	int n;
	cin >> n;

	vector<int> cost(n);
	for (int i = 0; i < n; i++){
		cin >> cost[i];
	}

    vector<int> dp(n+1, -1);
	cout << minCost(n+1, cost, dp) << endl;

	for (int i = 0; i < n+1; i++){
		cout << dp[i] << ' ';
	}
	return 0;
}