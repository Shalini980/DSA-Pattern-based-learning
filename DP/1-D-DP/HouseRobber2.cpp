#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=nums[i]+check(i+2,n,nums,dp);
        int notake=0+check(i+1,n,nums,dp);
        return dp[i]=max(take,notake);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size() == 1)
        return nums[0];
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        return max(check(0,n-2,nums,dp),check(1,n-1,nums,dp1));
    }
};