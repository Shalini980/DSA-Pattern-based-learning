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
  void fix(TreeNode* root, TreeNode*& list)
{
    if(root == NULL)
        return;

    TreeNode* L = root->left;
    TreeNode* R = root->right;

    list->right = root;
    list = list->right;

    root->left = NULL;

    fix(L, list);
    fix(R, list);
}
    void flatten(TreeNode* root) {
        TreeNode*list=new TreeNode(-1);
        TreeNode*temp=list;
        fix(root,list);
        root=temp->right;  

        
    }
};