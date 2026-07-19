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
      bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)return false;
        queue<TreeNode*>q;
        bool xf=false;
        bool yf=false;
        q.push(root);
        TreeNode*xptr;
        TreeNode*yptr;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=1;i<=s;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left && temp->left->val==x)
                {
                    xptr=temp;
                    xf=true;
                }
                else if(temp->left && temp->left->val==y)
                {
                    yptr=temp;
                    yf=true;

                }
                 if(temp->right && temp->right->val==x)
                {
                    xptr=temp;
                    xf=true;
                }
                else if(temp->right &&temp->right->val==y)
                {
                    yptr=temp;
                    yf=true;

                }

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);

            }
            if(xf==true && yf==true)
            {
                if(xptr!=yptr)return true;
                else return false;
            }
           
            else if(xf==true && yf==false)return false;
            else if(xf==false && yf==true)return false;
            
        }
        return false;
    }
};