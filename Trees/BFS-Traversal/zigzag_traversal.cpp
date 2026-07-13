
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        int x=0;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            vector<int>zigzag;
            for(int i=1;i<=s;i++)
            {
               TreeNode*temp=q.front();
               q.pop();
               zigzag.push_back(temp->val);
               if(temp->left)q.push(temp->left);
               if(temp->right)q.push(temp->right);
            }
            if(x%2!=0)
            {
                reverse(zigzag.begin(),zigzag.end());

            }
            x++;
            ans.push_back(zigzag);
        }
        return ans;
    }
};