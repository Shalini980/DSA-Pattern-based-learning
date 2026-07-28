#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int check(int day,int last,vector<vector<int>>&mat,vector<vector<int>>&dp)
  {
      if(day==0)
      {
          int maxi=0;
          for(int i=0;i<=2;i++)
          {
              if(i!=last)
              {
                  maxi=max(maxi,mat[0][i]);
              }
          }
          return maxi;
      }
      if(dp[day][last]!=-1)return dp[day][last];
      int maxi=0;
      for(int i=0;i<=2;i++)
      {
          if(i!=last){
          int points=mat[day][i]+check(day-1,i,mat,dp);
          maxi=max(maxi,points);
          }
      }
      return dp[day][last]=maxi;
  }
    int maximumPoints(vector<vector<int>>& mat) {
        vector<vector<int>>dp(mat.size()+1,vector<int>(mat[0].size()+1,-1));
        return check(mat.size()-1,3,mat,dp);
        
    }
};