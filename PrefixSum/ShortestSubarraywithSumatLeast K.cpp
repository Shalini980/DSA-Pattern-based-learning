#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
         vector<int>prefix(nums.size(),0);
         int i=0;
         int n=nums.size();
         int res=INT_MAX;
         deque<int>q;
         while(i<n)
         {
            if(i==0)prefix[i]=nums[i];
            else prefix[i]=nums[i]+prefix[i-1];
            if(prefix[i]>=k)
            {
                res=min(res,i+1);
                
            }
            while(!q.empty() && prefix[i]-prefix[q.front()]>=k)
                {
                        res=min(res,i-q.front());
                        q.pop_front();
                    
                }
                while(!q.empty() && prefix[i]<=prefix[q.back()])
                {
                    q.pop_back();
                }
                q.push_back(i);
                i++;
            
         }
         return (res==INT_MAX)?-1:res;
    }
};