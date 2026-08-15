#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xors=0;
        bool bf=false;
        for(int i=0;i<nums.size();i++)
        {xors=xors^nums[i];
        if(nums[i]!=0)bf=true;
        }
        if(bf==false)return 0;
        if(xors!=0)return nums.size();
        return nums.size()-1;
       
    }
};