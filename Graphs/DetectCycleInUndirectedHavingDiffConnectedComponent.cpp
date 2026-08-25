#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>vis(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int,int>>q;
        
     
        for(int i = 0; i < V; i++)//connected componenet
        {
            if(vis[i])
                continue;

            q.push({i,-1});
            vis[i] = 1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto it:adj[x])
            {
                if(it !=y && !vis[it])
                {
                    vis[it]=1;
                    q.push({it,x});
                }
                else if(it!=y && vis[it])return true;
            }
        }
        }
        return false;
        
    }
};