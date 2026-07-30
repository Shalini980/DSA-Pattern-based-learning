#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool check(int i,int k,int n,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(k==0)return true;
        if(i==n)return arr[i]==k;
        bool take =false;
        if(dp[i][k]!=-1)return dp[i][k];
        if(k>=arr[i]) take=check(i+1,k-arr[i],n,arr,dp);
        bool nottake=check(i+1,k,n,arr,dp);
        return dp[i][k]=take||nottake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return check(0,sum,arr.size()-1,arr,dp);
        
    }
};