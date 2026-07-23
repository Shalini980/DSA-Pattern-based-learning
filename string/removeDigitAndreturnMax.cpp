#include<iostream>
using namespace std;
#include<bits/stdc++.h>
class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans="";
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==digit)
            {
                string temp=number;
                temp.erase(i,1);
                if(temp>ans)
                {
                    ans=temp;
                }
            }
            
        }
        return ans;
    }
};