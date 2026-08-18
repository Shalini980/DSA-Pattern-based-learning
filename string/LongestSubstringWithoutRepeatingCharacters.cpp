#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        while(i<s.length())
        {
            mp[s[i]]++;
            while(mp.size()<(i-j+1))
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)mp.erase(s[j]);
                j++;
            }
            len=max(len,i-j+1);
            i++;
        }
        return len;

    }
};
