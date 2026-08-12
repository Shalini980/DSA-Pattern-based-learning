#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        vector<int>cnt(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%modulo==k)
            {
                if(i>0)cnt[i]=1+cnt[i-1];
                else cnt[i]=1;
            }
            else {
            if(i>0)cnt[i]=0+cnt[i-1];
            else cnt[i]=0;
            }

        }
        
        long long count=0;
        for(int i=0;i<nums.size();i++)
        {
            int rem=cnt[i]%modulo;
            int need=(rem-k+modulo)%modulo;
            count+=mp[need];
            mp[rem]++;


        }
        return count;
    }
};