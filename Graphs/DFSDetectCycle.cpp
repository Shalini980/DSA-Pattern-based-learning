#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it]&& it!=parent)
            {
                if(dfs(it,node,adj,vis))return true;
            }
            else if(it!=parent && vis[it])return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis))return true;
            }
        }
        return false;
        
    }
};