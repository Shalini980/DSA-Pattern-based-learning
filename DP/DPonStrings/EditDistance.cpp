#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
{
    if(j<0 && 1>=0)return i+1;
    if(i<0 && j>=0)return j+1;
    if(i<0 &&j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(word1[i]==word2[j])
    {
        return dp[i][j]=0+solve(word1,word2,i-1,j-1,dp);
    }
    else 
    return dp[i][j]=min(1+solve(word1,word2,i,j-1,dp),min(1+solve(word1,word2,i-1,j,dp),1+solve(word1,word2,i-1,j-1,dp)));
}
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};