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
   int sum(TreeNode*root,int &maxsum)
    {
        if(root==NULL)return 0;
        int l=max(0,sum(root->left,maxsum));
        int r=max(0,sum(root->right,maxsum));
        maxsum=max(maxsum,l+r+root->val);
        return root->val+max(l,r);

    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        sum(root,maxsum);
        return maxsum;
    }
};