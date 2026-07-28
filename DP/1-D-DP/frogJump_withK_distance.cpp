#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int check(int i,int n,vector<int>&heights,vector<int>&dp,int k)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int minjump=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            int jump=INT_MAX;
            if(i+j<=n) jump=check(i+j,n,heights,dp,k)+abs(heights[i]-heights[i+j]);
            minjump=min(jump,minjump);
        }
        return dp[i]=minjump;
    }
    int frogJump(vector<int>&heights,int k)
    {
        int n=heights.size();
        vector<int>dp(n+1,-1);
        int ans=check(0,n-1,heights,dp,k);
        return ans;
    }

};