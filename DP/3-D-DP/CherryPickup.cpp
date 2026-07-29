#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
    {
        if(j1<0 ||j1>m||j2<0||j2>m)return -1;
        if(i==n)
        {
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=-1;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                if(j1==j2)maxi=max(grid[i][j1]+check(i+1,j1+dj1,j2+dj2,n,m,grid,dp),maxi);
                else maxi=max(grid[i][j1]+grid[i][j2]+check(i+1,j1+dj1,j2+dj2,n,m,grid,dp),maxi);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return check(0,0,m-1,n-1,m-1,grid,dp);
    }
};