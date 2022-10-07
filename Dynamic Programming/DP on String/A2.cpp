// Longest Common Substr
// recurssion + Memoization 

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string &S1, string &S2, int n, int m, vector<vector<int>> &dp){
    if (n <= 0 || m <= 0) 
    	return 0;
    if (dp[n][m] != -1) 
    	return dp[n][m];
    if (S1[n] == S2[m]) 
    	return dp[n][m] = 1 + longestCommonSubstr(S1, S2, n-1, m-1, dp);
    return dp[n][m] = max(longestCommonSubstr(S1, S2, n-1, m, dp), 
    	       longestCommonSubstr(S1, S2, n, m-1, dp));
}
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        cout << longestCommonSubstr (s1, s2, n, m, dp) << endl;
    }
}
