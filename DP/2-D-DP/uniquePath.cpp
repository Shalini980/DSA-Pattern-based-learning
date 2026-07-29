#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int m ,int n,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)return 1;
        if(m<0 || n<0)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]= check(m-1,n,dp)+check(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
      return check(m-1,n-1,dp);
    }
};