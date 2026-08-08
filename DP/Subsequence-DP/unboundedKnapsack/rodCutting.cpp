#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int check(vector<int>&price , int n,int i,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return 0;
        }
         if(i == 0)
            return n * price[0];
        if(dp[n][i]!=-1)return dp[n][i];
       int take=0;
       if(n>=i+1)take=price[i]+check(price,n-(i+1),i,dp);
       int notake=0;
       notake=0+check(price,n,i-1,dp);
       return dp[n][i]=max(take,notake);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return check(price,n,n-1,dp);
        
    }
};