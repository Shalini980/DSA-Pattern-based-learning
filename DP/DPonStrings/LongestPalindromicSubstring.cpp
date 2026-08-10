#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(int i,int j,string &s ,vector<vector<int>>&dp)
    {
        if(i>=j)return dp[i][j]=true;
        if(dp[i][j]!=-1)return dp[i][j];
        if( s[i]==s[j])return dp[i][j]=solve(i+1,j-1,s,dp);
        return dp[i][j]=false;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0;
        int sp=0;
      vector<vector<int>> dp(n, vector<int>(n, -1));


        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(i,j,s,dp))
                {
                    if(j-i+1>maxlen)
                    {
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};