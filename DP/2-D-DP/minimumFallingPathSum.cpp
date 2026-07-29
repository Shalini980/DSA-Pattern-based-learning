#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int i,int j,int m,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
         if(j<0 ||j>m)return 1e9;
        if(i==0)return matrix[i][j];
       
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        return dp[i][j]=min(matrix[i][j]+check(i-1,j,m,matrix,dp),min(matrix[i][j]+check(i-1,j-1,m,matrix,dp),matrix[i][j]+check(i-1,j+1,m,matrix,dp)));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int mini=INT_MAX;
        for(int i=0;i<m;i++)
        {
            mini=min(check(n-1,i,m-1,matrix,dp),mini);
        }
        return mini;
    }
};