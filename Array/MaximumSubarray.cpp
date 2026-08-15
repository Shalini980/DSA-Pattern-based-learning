#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxs=nums[0];
        int start=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(sum==0)start=i;
            sum+=nums[i];
            if(sum>maxs)
            {
                maxs=sum;
            }
            if(sum<0)sum=0;
            
            
        }
        return maxs;
    }
};