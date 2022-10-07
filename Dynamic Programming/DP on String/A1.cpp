// Longest Common Substr
// recurssion 

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr (string &S1, string &S2, int n, int m){
    if (n <= 0 || m <= 0) 
    	return 0;
    if (S1[n] == S2[m]) 
    	return 1 + longestCommonSubstr(S1, S2, n-1, m-1);
    return max(longestCommonSubstr(S1, S2, n-1, m), 
    	       longestCommonSubstr(S1, S2, n, m-1));
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
