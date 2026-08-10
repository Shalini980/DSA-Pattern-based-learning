#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1001, 0);;
        int m=trips[0][2];
        for(int i=0;i<trips.size();i++)
        {
            int x=trips[i][0];
            int l=trips[i][1];
            int r=trips[i][2];
            diff[l]+=x;
            diff[r]-=x;
            m=max(m,r);
        }
        if(diff[0]>capacity)return false;
        for(int i=1;i<m;i++)
        {
            diff[i]+=diff[i-1];
            if(diff[i]>capacity)return false;
        }
        return true;
    }
};