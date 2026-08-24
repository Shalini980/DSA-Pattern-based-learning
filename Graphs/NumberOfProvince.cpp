#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void search(int node,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;
       
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                search(it,vis,adj);
            }
        }
        return;
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        int count=0;
        vector<int>visited(V,0);
        vector<vector<int>>adj(V);
       for(auto edge : edges) {
             int u = edge[0];
             int v = edge[1];

             adj[u].push_back(v);
             adj[v].push_back(u);
         }
        for(int i=0;i<V;i++)
        {
            if(visited[i]!=1)
            {
                count++;
                search(i,visited,adj);
            }
        }
        return count;
        
    }
};