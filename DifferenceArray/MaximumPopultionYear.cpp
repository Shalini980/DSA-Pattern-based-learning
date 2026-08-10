#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>diff(101,0);
        int m=0;
        for(int i=0;i<logs.size();i++)
        {
            int l=logs[i][0]-1950;
            int r=logs[i][1]-1950;
            diff[l]+=1;
            diff[r]-=1;
            m=max(m,r);
        }
        int maxi=0;
           for (int i = 0; i <= m; i++)
        {
            if (i > 0) diff[i] = diff[i] + diff[i-1];
            maxi = max(diff[i], maxi);
        }

        
        for(int i=0;i<=m;i++)
        {
            if(diff[i]==maxi)return 1950+i;
        }
        return 0;
    }
};