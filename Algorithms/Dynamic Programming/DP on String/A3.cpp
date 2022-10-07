// Longest Common Substr
// Bottom Up / Iterative 

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string &S1, string &S2, int n, int m){
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 || j == 0) 
                dp[i][j] = 0;
            else if (S1[i-1] == S2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }
    return dp[n][m];
}
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        cout << longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
