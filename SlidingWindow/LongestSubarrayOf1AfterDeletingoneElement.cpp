#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen=0;
        int i=0;
        int j=0;
        int count=0;
        int zero=0;
        int n=nums.size();
        while(i<n)
        {
            if(nums[i]==1)count++;
            else zero++;
            while(zero>1)
            {
               
                if(nums[j]==0)
                zero--;
                if(nums[j]==1)
                count--;
                 
                 j++;
            }
            maxlen=max(maxlen,count);
            i++;
        }
         if (zero == 0)
            maxlen--;
        return maxlen;

    }
};