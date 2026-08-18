#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;

        for(int i=0;i<s1.size();i++)
        {
            char c1 = s1[i];
            char c2 = s2[i];

            if(mp1.count(c1) && mp1[c1] != c2)
                return false;

            if(mp2.count(c2) && mp2[c2] != c1)
                return false;

            mp1[c1] = c2;
            mp2[c2] = c1;
        }

        return true;
    }
};