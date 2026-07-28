#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<bool>>t(arr.size()+1,vector<bool>(sum+1));
        int n=arr.size();
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(j==0)t[i][j]=true;
                else if(i==0)t[i][j]=false;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }
                else 
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
       
    }
};