#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void search(int node,vector<int>&vis,vector<int>&dfs,vector<vector<int>>&adj)
    {
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                search(it,vis,dfs,adj);
            }
        }
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>dfs;
        vector<int> visited(adj.size(),0);
        search(0,visited,dfs,adj);
        return dfs;
        
    }
};