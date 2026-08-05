#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int len=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(mp.find(sum)!=mp.end())
            {
                len=max(len,i-mp[sum]);
            }
            else mp[sum]=i;
        }
        return len;
    }
};