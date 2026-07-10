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
  TreeNode* reverse(TreeNode*root)
    {
        if(root==NULL)return NULL;
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        reverse(root->left);
        reverse(root->right);
        return root;
    }
    bool mirror(TreeNode*p1,TreeNode*p2)
    {
        if(p1==NULL && p2==NULL)return true;
        if(p1!=NULL && p2==NULL)return false;
        if(p1==NULL && p2!=NULL)return false;
        if(p1->val!=p2->val)return false;
        return mirror(p1->left,p2->left) && mirror(p1->right,p2->right);
        
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode*ptr=root->left;
        TreeNode*ptr1=reverse(root->right);
        return mirror(ptr,ptr1);
    }
};