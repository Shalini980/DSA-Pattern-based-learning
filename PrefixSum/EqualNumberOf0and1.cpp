#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)nums[i]=-1;
        }
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum)!=mp.end())
            {
                maxlen=max(maxlen,i-mp[sum]);
               
            }
            else  mp[sum]=i;
        }
        return maxlen;
    }
};