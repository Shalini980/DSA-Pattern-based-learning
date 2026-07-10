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
   int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(root->left!=NULL && root->right!=NULL || root->left==NULL && root->right==NULL)
        {
            return 1+min(l,r);
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            return 1+r;
        }
        else
        return 1+l;
        
        
    }
};