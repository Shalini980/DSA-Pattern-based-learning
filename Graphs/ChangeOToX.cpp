#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&board)
    {
        vis[x][y]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=x+dr[i];
            int nc=y+dc[i];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && !vis[nr][nc] && board[nr][nc]=='O')
            {
                dfs(nr,nc,vis,board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size()));
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O' && !vis[0][i])
            {
                dfs(0,i,vis,board);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
            {
                dfs(i,0,vis,board);
            }
        }
         for(int i=0;i<board.size();i++)
        {
            if(board[i][board[0].size()-1]=='O' && !vis[i][board[0].size()-1])
            {
                dfs(i,board[0].size()-1,vis,board);
            }
        }
        for(int i=0;i<board[0].size();i++)
        {
            if(board[board.size()-1][i]=='O' && !vis[board.size()-1][i])
            {
                dfs(board.size()-1,i,vis,board);
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(vis[i][j]==0 && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        return ;
    }
};