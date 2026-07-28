#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int check(int i,int n,vector<int>&heights,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int l=INT_MAX;
        int r=INT_MAX;
        if(i+1<=n)l=abs(heights[i]-heights[i+1])+check(i+1,n,heights,dp);
        if(i+2<=n)r=abs(heights[i]-heights[i+2])+check(i+2,n,heights,dp);
        return dp[i]=min(l,r);
    }
    int frogJump(vector<int>&heights)
    {
        int n=heights.size();
        vector<int>dp(n+1,-1);
        int ans=check(0,n-1,heights,dp);
        return ans;
    }

};