#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
            }
        }
        int tm=0;
        while(!q.empty())
        {
            int t=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            tm=max(tm,t);
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()&& grid[nr][nc]==1 && vis[nr][nc]!=2)
                {
                    vis[nr][nc]=2;
                    q.push({t+1,{nr,nc}});
                }
            }
        }
        for(int i=0;i<grid.size() ;i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==0 && grid[i][j]!=vis[i][j] && grid[i][j]==1)return -1;
            }
        }
        return tm;
    }
};