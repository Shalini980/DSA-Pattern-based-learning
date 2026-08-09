#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int i1,int i2,string text1,string text2,vector<vector<int>>&dp)
    {
        if(i1==0 || i2==0)return 0;
        if(text1[i1-1]==text2[i2-1]) return dp[i1][i2]= 1+check(i1-1,i2-1,text1,text2,dp);
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        return dp[i1][i2]=max(check(i1-1,i2,text1,text2,dp),check(i1,i2-1,text1,text2,dp));
    }
    string longestCommonSubsequence(string text1, string text2) {
        int i=text1.length();
        int j=text2.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        check(i,j,text1,text2,dp);
        int len=dp[i][j];
        string ans=" ";
        for(int i=0;i<len;i++)
        {
            ans+='$';
        }
        int index=len-1;
        int n=i;
        int m=j;
        while(n>0 && m>0)
        {
            if(text1[n-1]==text2[m-1])
            {
                ans[index]=text1[n-1];
                n--;
                m--;
                index--;
            }
            else if(dp[n-1][m]>dp[n][m-1])
            {
                n--;
            }
            else m--;
        }
        return ans;
    }
};