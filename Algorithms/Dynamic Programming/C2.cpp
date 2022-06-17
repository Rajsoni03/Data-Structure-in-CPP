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

int minCost(vector<int>& cost){   
    int n = cost.size();
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;
    
    int s1, s2;
    for (int i = 0; i < n; i++){
        s1 = cost[i] + prev1;
        s2 = (i>0) ? cost[i] + prev2 : INT_MAX;            
        curr = min(s1, s2);
        prev2 = prev1;
        prev1 = curr;
    }
    curr = min(prev1, prev2);        
    return curr;
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