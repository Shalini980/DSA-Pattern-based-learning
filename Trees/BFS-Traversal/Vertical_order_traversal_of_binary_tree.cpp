
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
  struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root->left ==NULL && root->right==NULL)return {{root->val}};
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int ,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int s=q.size();
            for(int i=1;i<=s;i++)
            {
               auto p=q.front();
               q.pop();
               TreeNode*temp=p.first;
               int x=p.second.first;
               int y=p.second.second;
               mp[x][y].insert(temp->val);
               if(temp->left)
               {
                q.push({temp->left,{x-1,y+1}});
               }
               if(temp->right)
               {
                q.push({temp->right,{x+1,y+1}});
               }
            
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp)
        {
            vector<int>y;
            for(auto s : it.second)
    {
        for(int val : s.second)
        {
            y.push_back(val);
        }
    }
            ans.push_back(y);
        }
        return ans;
        
    }
};