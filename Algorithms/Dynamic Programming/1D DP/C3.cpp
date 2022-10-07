// Min Cost Climbing Stairs
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
// tabulation approch with Memoization
// time  = O(n)
// space = O(n) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(vector<int>& cost){
    int n = cost.size();     
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++){
        int left = cost[i-1] + dp[i-1];
        int right = (i>1) ? cost[i-1] + dp[i-2] : cost[i-1];
        dp[i] = min(left, right);
    }
    return min(dp[n], dp[n-1]);
}

int main(){
	int n;
	cin >> n;

	vector<int> cost(n);
	for (int i = 0; i < n; i++){
		cin >> cost[i];
	}

	cout << minCost(cost);
	return 0;
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
