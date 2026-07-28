#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int n,vector<int>&nums,vector<int>&dp)
    {
        if(n==0)return nums[0];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int pick=nums[n]+check(n-2,nums,dp);
        int notpick=0+check(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>dp(nums.size()+1,-1);
        return check(n,nums,dp);
    }
};