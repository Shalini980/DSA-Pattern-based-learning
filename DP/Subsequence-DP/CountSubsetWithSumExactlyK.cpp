#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int check(int i,int n,int sum,int target,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(i == n)
        {
            return (sum == target);
        }
        if(sum > target)
            return 0;
            
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take=check(i+1,n,sum+arr[i],target,arr,dp);
        int notake=check(i+1,n,sum,target,arr,dp);
        return dp[i][sum]=take+notake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int tsum=0;
        for(int i=0;i<arr.size();i++)
        {
            tsum+=arr[i];
        }
        vector<vector<int>>dp(arr.size(),vector<int>(tsum+1,-1));
        return check(0,arr.size(),0,target,arr,dp);
    }
};