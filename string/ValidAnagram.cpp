#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(mp.find(t[i])!=mp.end())
            {
                mp[t[i]]--;
                if(mp[t[i]]==0)mp.erase(t[i]);
            }
        }
        if(mp.size()==0)return true;
        return false;
    }
};