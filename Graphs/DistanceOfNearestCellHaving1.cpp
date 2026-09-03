#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>dist(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int a=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            dist[x][y]=a;
            q.pop();
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=x+dx[i];
                int nc=y+dy[i];
                if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({a+1,{nr,nc}});
                }
            }
        }
        return dist;
    }
};