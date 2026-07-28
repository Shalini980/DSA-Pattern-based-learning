#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int check(int i,int n,vector<int>&cost,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int l=INT_MAX,r=INT_MAX;
        if(i+1<=n)l=cost[i]+check(i+1,n,cost,dp);
        if(i+2<=n)r=cost[i]+check(i+2,n,cost,dp);
        return dp[i]=min(l,r);
    }
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int>dp(cost.size()+1,-1);
        check(0,cost.size(),cost,dp);
        return dp[cost.size()];
    }
};

