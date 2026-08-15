#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int len=0;
       for (int x : st) {

           
            if (st.find(x - 1) == st.end()) {

                int curr = x;
                int l = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    l++;
                }

                len = max(len, l);
            }
        }
           
        
        return len;
    }
};