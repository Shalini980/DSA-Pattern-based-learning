#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element=0;
        long count=0;
        int i=0;
        while(i<nums.size())
        {
            if(count==0)element=nums[i];
            if(nums[i]==element)count++;
            else if(nums[i]!=element)count--;
            i++;
        }
        count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==element)count++;
        }
        if(count>(nums.size()/2))return element;
        return -1;
    }
};