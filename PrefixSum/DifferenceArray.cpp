#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
        // code here
        vector<int>diff(arr.size()+1,0);
        int n=opr.size();
        for(int i=0;i<n;i++)
        {
            int l=opr[i][0];
            int r=opr[i][1];
            int x=opr[i][2];
            diff[l]+=x;
            diff[r+1]-=x;
        }
        for(int i=1;i<arr.size();i++)
        {
          diff[i]+=diff[i-1];   
        }
         for(int i=0;i<arr.size();i++)
        {
          arr[i]=arr[i]+diff[i];   
        }
        return arr;
    }
};