#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int n,vector<int>&dp)
    {
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
       return dp[n]=check(n-1,dp)+check(n-2,dp);
    }
    int fibonacci(int n) {
       vector<int>dp(n+1,-1);
       check(n,dp);
       return dp[n];
    }
};