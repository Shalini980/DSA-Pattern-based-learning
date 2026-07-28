#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
  
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums)
            totalSum += x;

        if (totalSum % 2 != 0)
            return false;
        
        vector<vector<bool>>dp(nums.size()+1,vector<bool>(totalSum/2+1));
        for(int i=0;i<=totalSum/2;i++)
        {
            dp[0][i]=false;
        }
        for(int i=0;i<=nums.size();i++)
        {
            dp[i][0]=true;
        }
        dp[0][0]=true;
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=totalSum/2;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[nums.size()][totalSum/2];
    }
};