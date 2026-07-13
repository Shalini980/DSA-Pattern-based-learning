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
     vector<double> averageOfLevels(TreeNode* root) {
        if(root->left==NULL&& root->right==NULL)return {1.0*root->val};
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty())
        {
            int s=q.size();
            double avg=0.0;
            for(int i=1;i<=s;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                avg+=temp->val;
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            avg= (1.0*avg)/(1.0*s);
            ans.push_back(avg);
        }
        return ans;
        
    }
};