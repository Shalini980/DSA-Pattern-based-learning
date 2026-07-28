#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int n,vector<int>&dp)
    {
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int l=check(n-1,dp);
        int r=check(n-2,dp);
        return dp[n]=l+r;
    }
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       check(n,dp);
       return dp[n];
    }
};