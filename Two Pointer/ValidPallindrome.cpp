#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
      string temp="";
      for(char ch:s)
      {
        if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9')
        {
            ch=tolower(ch);
            temp+=ch;
        }
      }
      int i=0;
      int j=temp.length()-1;
      while(i<=j)
      {
        if(temp[i]!=temp[j])return false;
        i++;
        j--;
      }
      return true;
    }

};