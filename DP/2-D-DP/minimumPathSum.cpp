#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)return grid[m][n];
        if(m<0 ||n<0)return 100000000;
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=min(grid[m][n]+check(m-1,n,grid,dp),grid[m][n]+check(m,n-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(m-1,n-1,grid,dp);
        
    }
};