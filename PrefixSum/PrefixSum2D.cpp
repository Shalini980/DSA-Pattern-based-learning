#include<bits/stdc++.h>
using namespace std;
class Solution
{
    int find(vector<vector<int>>nums)
    {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(i>0)prefix[i][0]=nums[i][0]+prefix[i-1][0];
            else prefix[i][0]=nums[i][0];
        }
        for(int i=0;i<m;i++)
        {
           if(i>0)prefix[0][i]=nums[0][i]+prefix[0][i-1];
            else prefix[0][i]=nums[0][i];   
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                prefix[i][j]=nums[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
        int l1,r1,l2,r2;
        cin>>l1>>l2>>r1>>r2;
         int ans = prefix[l2][r2];

        // Remove everything above
        if (l1 > 0)
            ans -= prefix[l1-1][r2];

        // Remove everything to the left
        if (r1 > 0)
            ans -= prefix[l2][r1-1];

        // We subtracted top-left twice, so add it once
        if (l1 > 0 && r1 > 0)
            ans += prefix[l1-1][r1-1];

        return ans;
    }
};