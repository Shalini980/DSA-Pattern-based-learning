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
   vector<int> postorderTraversal(TreeNode* root) {;
        if(root==NULL)return{};
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        vector<int>ans;
        while(!s1.empty())
        {
            TreeNode*temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left)s1.push(temp->left);
            if(temp->right)s1.push(temp->right);
        }
        while(!s2.empty())
        {
            TreeNode*temp=s2.top();
            ans.push_back(temp->val);
            s2.pop();
        }
        return ans;
        
    }
};