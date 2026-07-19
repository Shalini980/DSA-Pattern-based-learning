#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
    int check(vector<int>&arr,int sum,int n,vector<vector<int>>&t)
    {
         if(sum==0)return 1;
        if(n==0)return 0;
       if(t[n][sum]!=-1)return t[n][sum];
        if(arr[n-1]<=sum)
        {
            return t[n][sum]=check(arr,sum-arr[n-1],n-1,t)||check(arr,sum,n-1,t);
        }
        else
        {
            return t[n][sum]=check(arr,sum,n-1,t);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>>t(arr.size()+1,vector<int>(sum+1,-1));
        return (check(arr,sum,arr.size(),t)==1)?true:false;
    }
};