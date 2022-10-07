// Min Cost Climbing Stairs
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
// Space Optimization
// time  = O(n)
// space = O(1) 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCost(vector<int>& cost){
    int n = cost.size();
    int prev2 = 0;
    int prev1 = 0;
    int curr;

    for (int i = 0; i < n; i++){
        int left = cost[i] + prev1;
        int right = cost[i] + prev2;

        curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
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