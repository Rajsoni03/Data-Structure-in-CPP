#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int task_dp[5]){
	for (int i = 0; i < 5; i++){
		cout << task_dp[i] << " ";
	}
	cout << endl;
}

int func(vector<vector<int>> v){
	int task_dp[v.size()+1];

	task_dp[0] = 0;
	task_dp[1] = v[0][1];

	for (int i = 2; i <= v.size(); i++){
		task_dp[i] = max(v[i-1][1] + task_dp[i-2], v[i-1][0] + task_dp[i-1]);
		print(task_dp);
	}
	return task_dp[v.size()];
}


int main()
{
	int n = 4;
	vector<vector<int>> v = {{1, 2}, {4, 10}, {20, 21}, {2, 23}};
	cout << func(v);
	return 0;
}

