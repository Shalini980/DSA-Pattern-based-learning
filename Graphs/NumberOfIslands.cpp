#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void search (int r,int c,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        vis[r][c]=1;
        q.push({r,c});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
                for(int i=0;i<4;i++)
                {
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if(nr >= 0 && nr < grid.size() &&
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == '1' &&
                    !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            
           
        }
         return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'&& !vis[i][j])
                {
                    count++;
                    search(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};