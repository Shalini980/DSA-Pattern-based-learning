#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool check(int n,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(sum==0)return dp[n][sum]=true;
        if(n==0)
        {
            return dp[n][sum]=(arr[0]==sum);
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        bool take=false;
        if(sum>=arr[n]) take=check(n-1,sum-arr[n],arr,dp);
        bool notake=check(n-1,sum,arr,dp);
        return dp[n][sum]=take||notake;
       
    }
    int minDifference(vector<int>& arr) {
        // code here
        int tsum=0;
        for(int i=0;i<arr.size();i++)
        {
            tsum+=arr[i];
        }
        vector<vector<int>>dp(arr.size(),vector<int>(tsum+1,-1));
        check(arr.size()-1,tsum,arr,dp);
        int mini=INT_MAX;
        for(int s = 0; s <= tsum; s++)
{
    check(arr.size()-1, s, arr, dp);
}
        for(int i=0;i<=tsum/2;i++)
        {
            if(dp[arr.size()-1][i]==1)
            {
                mini=min(mini,abs(2*i-tsum));
            }
        }
        return mini;
    }
};
