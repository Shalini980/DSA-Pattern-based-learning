#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int find(int i,int n,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee)
    {
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)
        {
            return dp[i][buy]= max(-prices[i]+find(i+1,n,0,prices,dp,fee),0+find(i+1,n,1,prices,dp,fee));
        }
        else 
        {
            return dp[i][buy]=max(prices[i]-fee+find(i+1,n,1,prices,dp,fee),0+find(i+1,n,0,prices,dp,fee));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,n,1,prices,dp,fee);
    }
};