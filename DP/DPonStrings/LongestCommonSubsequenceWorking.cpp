#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.length();
        int j=text2.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        for(int x=0;x<=j;x++)dp[0][x]=0;
        for(int x=0;x<=i;x++ )dp[x][0]=0;
        for(int x=1;x<=i;x++)
        {
            for(int y=1;y<=j;y++)
            {
                if(text1[x-1]==text2[y-1])dp[x][y]=1+dp[x-1][y-1];
                else dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
            }
        }
        
        return dp[i][j];
    }
};