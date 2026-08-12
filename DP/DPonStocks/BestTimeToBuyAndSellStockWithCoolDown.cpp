#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int i,int n,int buy,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)
        {
            return dp[i][buy]= max(-prices[i]+find(i+1,n,0,prices,dp),0+find(i+1,n,1,prices,dp));
        }
        else 
        {
            return dp[i][buy]=max(prices[i]+find(i+2,n,1,prices,dp),0+find(i+1,n,0,prices,dp));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,n,1,prices,dp);
    }
};