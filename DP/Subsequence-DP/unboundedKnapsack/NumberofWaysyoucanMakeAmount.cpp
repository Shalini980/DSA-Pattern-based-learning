#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int n,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(amount==0)return 0;
            else if(amount>=coins[0] && amount%coins[0]==0)
            {
                return amount/coins[0];
            }
            else return 1e8;
        }
        if(dp[n][amount]!=-1)return dp[n][amount];
        if(amount==0)return 0;
        int take=INT_MAX;
        if(amount>=coins[n])take=1+check(n,amount-coins[n],coins,dp);
        int notake=0+check(n-1,amount,coins,dp);
        return dp[n][amount]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return (check(coins.size()-1,amount,coins,dp)==1e8)?-1:check(coins.size()-1,amount,coins,dp);

    }
};