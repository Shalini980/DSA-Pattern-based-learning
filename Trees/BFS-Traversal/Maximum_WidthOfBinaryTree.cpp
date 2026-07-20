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
    int widthOfBinaryTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)return 1;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        int maxs=0;
        while(!q.empty())
        {
            int s=q.size();
            int a=0;
            int b=0;
            for(int i=1;i<=s;i++)
            {
                auto it=q.front();
                q.pop();
                long long x=it.first;
                TreeNode*temp=it.second;
                if(i==1)
                {
                    a=x;
                }
                if(i==s)
                {
                    b=x;
                    maxs=max(maxs,abs(b-a)+1);
                }
                if(temp->left)q.push({2*x+1,temp->left});
                if(temp->right)q.push({2*x+2,temp->right});

            }
        }
        return maxs;
    }
};