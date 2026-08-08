#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int n,int sum,int target,vector<int>&nums)
    {
        if(n==0)
        {
            if(sum+nums[0]==target && sum-nums[0]==target)return 2;
            else if(sum+nums[0]==target)return 1;
            else if(sum-nums[0]==target)return 1;
            else return 0;
        }
        int takeP=check(n-1,sum+nums[n],target,nums);
        int takeN=check(n-1,sum-nums[n],target,nums);
        return takeP+takeN;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return check(n-1,0,target,nums);
    }
};