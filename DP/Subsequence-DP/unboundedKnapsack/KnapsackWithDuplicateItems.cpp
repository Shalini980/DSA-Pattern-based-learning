#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(int n,int cap,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp)
    {
        if(cap==0)return 0;
        if(n==0)
        {
            int take=INT_MIN;
            if(cap>=wt[0]) take= (cap/wt[n])*val[n];
            int notake=0;
            return max(take,notake);
            
        }
        if(dp[n][cap]!=-1)return dp[n][cap];
        int take=INT_MIN;
        if(cap>=wt[n])take=val[n]+solve(n,cap-wt[n],val,wt,dp);
        int notake=0+solve(n-1,cap,val,wt,dp);
        return dp[n][cap]=max(take,notake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n=val.size();
       vector<vector<int>>dp(wt.size(),vector<int>(capacity+1,-1));
       return solve(n-1,capacity,val,wt,dp);
        
    }
};