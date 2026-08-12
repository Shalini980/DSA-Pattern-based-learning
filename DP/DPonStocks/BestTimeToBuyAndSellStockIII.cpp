#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(int i,int buy,int n,vector<vector<vector<int>>>&dp,vector<int>&prices,int x)
    {
        if(x==0)return 0;
        if(i==n)return 0;
        if(dp[i][buy][x]!=-1)return dp[i][buy][x];
        if(x>0){
        if(buy)return dp[i][buy][x]=max(-prices[i]+find(i+1,0,n,dp,prices,x),0+find(i+1,1,n,dp,prices,x));

        else return dp[i][buy][x]=max(prices[i]+find(i+1,1,n,dp,prices,x-1),0+find(i+1,0,n,dp,prices,x));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(4,-1)));
        return find(0,1,n,dp,prices,2);
    }
};