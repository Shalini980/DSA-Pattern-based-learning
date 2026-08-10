#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int LCS(string &word1,string &word2)
    {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];

    }
    int minDistance(string word1, string word2) {
        int x=word1.length();
        int y=word2.length();
        int a=LCS(word1,word2);
        return (x-a)+(y-a);
    }
};