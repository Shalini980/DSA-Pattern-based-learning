#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int k=nums.size()-1;
        vector<int>ans(k+1,-1);
       
        int i=0;
        int j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]*nums[i]>=nums[j]*nums[j])
            {
                ans[k]=nums[i]*nums[i];
                k--;
                i++;
            }
            else 
            {
                ans[k]=nums[j]*nums[j];
                k--;
                j--;    
            }
        }
        return ans;
    }
};