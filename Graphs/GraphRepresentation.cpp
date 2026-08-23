#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n;i++)
    {
        int u;
        int v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Weighted graphs";
    vector<pair<int,int>>adj[n+1];

    cout<<"connected Component";

}