#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int i1,int i2,string text1,string text2,vector<vector<int>>&dp)
    {
        if(i1<0 || i2<0)return 0;
        if(text1[i1]==text2[i2]) return 1+check(i1-1,i2-1,text1,text2,dp);
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        return dp[i1][i2]=max(check(i1-1,i2,text1,text2,dp),check(i1,i2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.length();
        int j=text2.length();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return check(i-1,j-1,text1,text2,dp);
    }
};