#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
        if(i==n)
        {
          
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX)return dp[i][j];

        return dp[i][j]=min(triangle[i][j]+check(i+1,j,n,triangle,dp),triangle[i][j]+check(i+1,j+1,n,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<vector<int>> dp(n);

        for(int i=0;i<n;i++)
        {
            dp[i] = vector<int>(triangle[i].size(), INT_MAX);

        }
        return check(0,0,n-1,triangle,dp);
    }
};