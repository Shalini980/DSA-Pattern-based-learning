#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int n,int k,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(k==0)return true;
        if(n==0)return nums[n]==k;
        if(dp[n][k]!=-1)return dp[n][k];
        bool notake=check(n-1,k,nums,dp);
        bool take=false;
        if(k>=nums[n])
        {
            take=check(n-1,k-nums[n],nums,dp);
        }
        return dp[n][k]=take|notake;
    }
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(int i=0;i<nums.size();i++)
        {
            tsum+=nums[i];
        }
        if(tsum%2!=0)return false;
        else
        {
            vector<vector<int>>dp(nums.size(),vector<int>((tsum/2)+1,-1));
            return check(nums.size()-1,(tsum/2),nums,dp);
        }
        return false;
    }
};