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
      void level(TreeNode*root,vector<vector<int>>&ans)
    {
        if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int>tempi;
            for(int i=1;i<=s;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                tempi.push_back(temp->val);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);

            }
            ans.push_back(tempi);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
         vector<vector<int>>temp;
        level(root,ans);
        for(int i=ans.size()-1;i>=0;i--)
        {
            vector<int>p;
            for(int j=0;j<ans[i].size();j++)
            {
                p.push_back(ans[i][j]);
            }
            temp.push_back(p);
        }
        return temp;
    }
        

        
    
};