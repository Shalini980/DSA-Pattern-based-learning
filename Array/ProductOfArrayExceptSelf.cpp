#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        int pro=1;
        for(int i=1;i<n;i++)
        {
            pro=pro*nums[i-1];
            left[i]=pro;
        }
        pro=1;
        for(int i=n-2;i>=0;i--)
        {
            pro=pro*nums[i+1];
            right[i]=pro;
        }
        vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        {
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};