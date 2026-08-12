#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int i,int buy,int n,vector<vector<int>>&dp,vector<int>&prices)
    {
        if(i==n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)return dp[i][buy]=max(-prices[i]+find(i+1,0,n,dp,prices),0+find(i+1,1,n,dp,prices));

        else return dp[i][buy]=max(prices[i]+find(i+1,1,n,dp,prices),0+find(i+1,0,n,dp,prices));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,1,n,dp,prices);
    }
};