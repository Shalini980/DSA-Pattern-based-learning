#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum<p)return -1;
        if(sum%p==0)return 0;
        long long x=sum%p;
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long s=0;
        int l=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(mp.find((s-x+p)%p)!=mp.end())
            {
                l=min(l,i-mp[(s-x+p)%p]);
            }
             mp[s % p]=i;
        }
        return (l==nums.size())?-1:l;
        
        
    }
};