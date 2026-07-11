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
     void find(TreeNode*root,string str,vector<string>&ptr)
   {
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)
    {
        str.append(to_string(root->val));
        ptr.push_back({str});
    }
    find(root->left,str+to_string(root->val)+"->",ptr);
     find(root->right,str+to_string(root->val)+"->",ptr);
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ptr;
        find(root,"",ptr);
        return ptr;
    }
};