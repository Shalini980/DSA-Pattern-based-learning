#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int find(int i,int prev,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(i>=arr.size())return 0;
        int notake=0+find(i+1,prev,arr,dp);
        int take=0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1||arr[i]>arr[prev])
        {
            take=1+find(i+1,i,arr,dp);
        }
        return dp[i][prev+1]=max(take,notake);
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(0,-1,arr,dp);
        
    }
};