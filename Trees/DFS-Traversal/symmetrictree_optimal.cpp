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
  bool mirror(TreeNode*p1,TreeNode*p2)
    {
        if(p1==NULL && p2==NULL)return true;
        if(p1!=NULL && p2==NULL)return false;
        if(p1==NULL && p2!=NULL)return false;
        if(p1->val!=p2->val)return false;
        return mirror(p1->left,p2->right) && mirror(p1->right,p2->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode*ptr=root->left;
        TreeNode*ptr1=root->right;
        return mirror(ptr,ptr1);
    }
};