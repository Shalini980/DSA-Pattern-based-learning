#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int j=0;
        int i=0;
        int len=INT_MIN;
        while(j<s.length())
        {
            while(mp[s[j]]>=2)
            {
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            len=max(len,j-i+1);
            j++;

        }
        return len;
    }
};