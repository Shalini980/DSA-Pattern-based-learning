#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int check(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxsum=INT_MIN;
        for(int j=i;j<=n;j++)
        {
            int sum=nums[j]+check(j+2,n,nums,dp);
            maxsum=max(maxsum,sum);
        }
        return dp[i]=maxsum;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return max(check(0,nums.size()-1,nums,dp),check(1,nums.size()-1,nums,dp));
    }
};