#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     void search (int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis,int color)
    {
        queue<pair<int,int>>q;
        vis[r][c]=1;
        q.push({r,c});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            int colu=grid[row][col];
            grid[row][col]=color;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
                for(int i=0;i<4;i++)
                {
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if(nr >= 0 && nr < grid.size() &&
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == colu &&
                    !vis[nr][nc])
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            
           
        }
         return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        search(sr,sc,image,vis,color);
        return image;
    }
};