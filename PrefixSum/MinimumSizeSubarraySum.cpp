#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int minl=INT_MAX;
        int sum=0;
        int i=0,j=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            while(sum>=target)
            {
                minl=min(minl,i-j+1);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        if(minl==INT_MAX)return 0;
        return minl;
       
        
    }
};