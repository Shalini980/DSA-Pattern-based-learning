#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int check(int n,int s, int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(n==0)
        {
           int take=s+arr[0];
           int notake=s;
           if(take==sum && notake==sum)return 2;
           else if(take==sum||notake==sum)return 1;
           else return 0;
           
        }
        if(s>sum)return 0;
        if(dp[n][s]!=-1)return dp[n][s];
        int take=check(n-1,s+arr[n],sum,arr,dp);
        int notake=check(n-1,s,sum,arr,dp);
        return dp[n][s]=take+notake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int tsum=0;
        for(int i=0;i<arr.size();i++)
        {
            tsum+=arr[i];
        }
        if(tsum < diff) return 0;
        if((tsum + diff) % 2 != 0) return 0;
        vector<vector<int>>dp(arr.size(),vector<int>(tsum+1,-1));
        int val=(tsum+diff)/2;
        return check(arr.size()-1,0,val,arr,dp);
    }
};