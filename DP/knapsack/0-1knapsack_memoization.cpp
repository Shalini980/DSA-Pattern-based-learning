#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
  
    int check(int W,vector<int>&val,vector<int>&wt,int n,vector<vector<int>> &t)
    {
        if(n==0 || W==0)return 0;
        if(t[n][W]!=-1)return t[n][W];
        if(W>=wt[n-1])
        {
            return t[n][W]=max(val[n-1]+check(W-wt[n-1],val,wt,n-1,t),check(W,val,wt,n-1,t));
        }
        else
        {
            return t[n][W]=check(W,val,wt,n-1,t);
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>>t(val.size()+1,vector<int>( W+1,-1));
        
        return check(W,val,wt,val.size(),t);
    }
};