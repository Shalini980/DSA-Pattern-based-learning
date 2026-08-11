#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string &s,string &t,int n,int m,vector<vector<int>>&dp)
    {
        if(m<0)return 1;
        if(n<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s[n]==t[m])return dp[n][m]=numDistinct(s,t,n-1,m-1,dp)+numDistinct(s,t,n-1,m,dp);
        else return dp[n][m]=numDistinct(s,t,n-1,m,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return numDistinct(s,t,n-1,m-1,dp);

    }
};