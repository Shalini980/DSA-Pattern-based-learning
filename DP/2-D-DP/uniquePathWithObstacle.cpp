#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int m,int n,vector<vector<int>>&obs,vector<vector<int>>&dp)
    {
        if(m==0&&n==0&&obs[m][n]==0)return 1;
        if(m==0&&n==0&&obs[m][n]==1)return 0;
        if(m<0 ||n<0)return 0;
        if(obs[m][n]==1)return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        int left=check(m-1,n,obs,dp);
        int right=check(m,n-1,obs,dp);
        return dp[m][n]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //if(m==1 && n==1&&obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return check(m-1,n-1,obstacleGrid,dp);
    }
};