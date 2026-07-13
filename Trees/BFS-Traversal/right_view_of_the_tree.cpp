
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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty())
        {
            int s=q.size();
            ans.push_back(q.front()->val);
            for(int i=1;i<=s;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->right)q.push(temp->right);
                if(temp->left)q.push(temp->left);
            }   
        }
        return ans;
        
    }
};