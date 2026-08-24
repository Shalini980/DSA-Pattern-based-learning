#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>bfs;
        queue<int>q;
        vector<int>visited(adj.size(),0);
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return bfs;
        
    }
};