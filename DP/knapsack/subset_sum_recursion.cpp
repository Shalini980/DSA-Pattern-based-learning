#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
  public:
    bool check(vector<int>&arr,int sum,int n)
    {
         if(sum==0)return true;
        if(n==0)return false;
       
        if(arr[n-1]<=sum)
        {
            return check(arr,sum-arr[n-1],n-1)||check(arr,sum,n-1);
        }
        else
        {
            return check(arr,sum,n-1);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        return check(arr,sum,arr.size());
    }
};