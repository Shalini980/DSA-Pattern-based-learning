#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)nums[i]=0;
            else 
            {
                nums[i]=1;
            }
        }
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count=0;
        int i=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                count+=mp[sum-k];
            }
            mp[sum]++;
            i++;
        }
        return count;
        
    }
};