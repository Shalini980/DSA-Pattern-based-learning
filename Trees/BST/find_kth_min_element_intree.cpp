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
    void inorder(TreeNode*root,queue<TreeNode*>&q)
    {
        if(root==NULL)return ;
        inorder(root->left,q);
        q.push(root);
        inorder(root->right,q);
        return ;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*>q;
        inorder(root,q);
        for(int i=1;i<k;i++)
        {
            q.pop();
        }
        return q.front()->val;


    }
};