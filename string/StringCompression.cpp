#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        if(chars.size()<=1)return chars.size();
        int count=1;
        for(int i=0;i<chars.size();i++)
        {
            if(i+1<chars.size()&&chars[i]==chars[i+1])count++;
            else
            {
                s.push_back(chars[i]);
                if(count>1)
                {
                    string t=to_string(count);
                    for(char ch:t)s+=ch;
                }
                count=1;
            }
        }
        
        chars.clear();
        for(char ch:s)
        {
            chars.push_back(ch);
        }
        return chars.size();
    }
};